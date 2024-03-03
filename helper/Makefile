CC = i686-w64-mingw32-gcc
LD = i686-w64-mingw32-ld
OBJCOPY = i686-w64-mingw32-objcopy
KPACK = kpack

CFLAGS = -I../include -nostdinc -c -Os \
	 -fno-builtin -fno-ident -fomit-frame-pointer -ffreestanding -fno-leading-underscore \
	 -fno-stack-check -fno-stack-protector -mno-stack-arg-probe -fno-exceptions \
	 -fno-asynchronous-unwind-tables -ffast-math

LDFLAGS = -static --strip-all -nostdlib -Tapp_dyn.lds --image-base 0 --subsystem native --file-alignment=16 --section-alignment=16 -L../lib

all: test

test: test.o
	$(LD) $(LDFLAGS) ../lib/crtdll.o $< -o $@ -lc.obj -lconsole.obj
	$(OBJCOPY) -O binary test
	$(KPACK) --nologo test

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o
