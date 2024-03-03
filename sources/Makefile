CC = i686-w64-mingw32-gcc
STRIP = i686-w64-mingw32-strip
DLLTOOL = i686-w64-mingw32-dlltool
KPACK = kpack

CFLAGS = -I../include -D_BUILD_LIBC -nostdinc -c -Os \
         -fno-builtin -fno-ident -ffreestanding -fno-leading-underscore \
         -fno-stack-check -fno-stack-protector -mno-stack-arg-probe -fno-exceptions \
         -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks

all: libc.obj.a libc.obj crtdll.o 

libc.obj.a: libc.def
	$(DLLTOOL) --no-leading-underscore -d $< -l $@

libc.obj: libc.o
	$(STRIP) --strip-unneeded $< -o $@
	$(KPACK) $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: install
install: libc.obj.a
	cp -f libc.obj.a ../lib/libc.obj.a
	cp -f libc.def ../lib/libc.def
	cp -f crtdll.o ../lib/crtdll.o

.PHONY: clean
clean:
	rm -rf *.obj *.o 
