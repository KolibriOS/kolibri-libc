if tup.getconfig("NO_TCC") ~= "" then return end

TCC = "kos32-tcc"
CFLAGS = " -c -nostdinc -Iinclude "

BUILD_DIR = "build"

OBJS = {}

C_SRC = {
    "ctype/is.c",
    "ctype/tolower.c",
    "ctype/isdigit.c",
    "ctype/isxdigit.c",
    "ctype/islower.c",
    "ctype/iscntrl.c",
    "ctype/isspace.c",
    "ctype/isgraph.c",
    "ctype/isalpha.c",
    "ctype/isprint.c",
    "ctype/ispunct.c",
    "ctype/isalnum.c",
    "ctype/isupper.c",
    "ctype/toupper.c"
}

tup.append_table(OBJS,
    tup.foreach_rule(C_SRC, TCC .. CFLAGS .. " %f -o %o ",  BUILD_DIR .. "/%B.o")
)

tup.rule(OBJS, "ar -crs %o %f", BUILD_DIR .. "/libc.a")
