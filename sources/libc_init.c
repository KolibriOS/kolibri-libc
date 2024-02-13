/*
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <string.h>
#include <sys/ksys.h>
#include <stdint.h>

typedef struct {
    char sign[8];
    int ver;
    int start;
    int iend;
    int memsize;
    int stacktop;
    char *cmdline;
    char *ath;
    int __subsystem__;
    void *__idata_start;
    void *__idata_end;
    int (*main)(int argc, char **argv, char **envp);
} __packed kos_app_header_t;

typedef union {
    uint32_t forwarder_string;
    uint32_t function;
    uint32_t ordinal;
    uint32_t address_of_data;
} pe_thunk_data32_t;

typedef struct {
    union {
        uint32_t characteristics;
        uint32_t original_first_thunk;
    };
    uint32_t time_date_stamp;
    uint32_t forwarder_chain;
    char *name;
    uint32_t first_thunk;
} pe_import_descriptor_t;

typedef struct {
    uint16_t hint;
    char name[1];
} pe_import_by_name_t;

#define IMAGE_ORDINAL_FLAG 0x80000000
#define LIBPATH_MAX        1024
#define LIBPATH_LEN        9

__attribute__((noreturn)) static void libc_init(void)
{
    kos_app_header_t *app_hdr = (kos_app_header_t *)0;
    pe_import_descriptor_t *imp_desc = app_hdr->__idata_start;

    char libpath[LIBPATH_MAX] = "/sys/lib/";

    pe_thunk_data32_t *iat = (pe_thunk_data32_t *)imp_desc->first_thunk;
    pe_thunk_data32_t *ilt = (pe_thunk_data32_t *)imp_desc->original_first_thunk;

    while (imp_desc->name && !imp_desc->time_date_stamp) {
        strncpy(libpath + LIBPATH_LEN, imp_desc->name, LIBPATH_MAX - LIBPATH_LEN - 1);

        ksys_dll_t *coff_dll = _ksys_dlopen(libpath);
        if (!coff_dll) {
            /* TODO: Replace to sprintf() */
            _ksys_debug_puts("Unable to load: ");
            _ksys_debug_puts(libpath);
            _ksys_debug_putc('\n');
            goto exit;
        }

        while (ilt->address_of_data) {
            pe_import_by_name_t *record = (pe_import_by_name_t *)ilt->address_of_data;
            uintptr_t func_ptr = (uintptr_t)_ksys_dlsym(coff_dll, record->name);

            if (func_ptr) {
                iat->function = func_ptr;
            } else {
                /* TODO: Replace to sprintf() */
                _ksys_debug_puts("Unresolved import '");
                _ksys_debug_puts(record->name);
                _ksys_debug_puts("' from ");
                _ksys_debug_puts(libpath);
                _ksys_debug_putc('\n');
                goto exit;
            }

            iat++;
            ilt++;
        }
        imp_desc++;
    }
    /* TODO: Implement argc and argv */
    app_hdr->main(0, NULL, NULL);

exit:
    _ksys_exit();
    __builtin_unreachable();
}
