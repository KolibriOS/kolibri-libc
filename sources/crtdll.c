#include <sys/ksys.h>

static void (*libc_init)(void);
const char *libc_path = "/sys/lib/libc.obj";

__attribute__((noreturn)) void __start(void)
{
    ksys_dll_t *libc_imp = _ksys_dlopen(libc_path);
    if (!libc_imp) {
        _ksys_debug_puts("Unable to load: ");
        _ksys_debug_puts(libc_path);
        _ksys_debug_putc('\n');
    }
    libc_init = libc_imp[0].func_ptr;
    libc_init();
    __builtin_unreachable();
}
