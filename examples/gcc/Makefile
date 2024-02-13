CC = i686-w64-mingw32-gcc
LD = i686-w64-mingw32-ld
OBJCOPY = i686-w64-mingw32-objcopy
KPACK = kpack

CFLAGS = -I../../include -nostdinc -c -Os \
	 -fno-builtin -fno-ident -fomit-frame-pointer -ffreestanding -fno-leading-underscore \
	 -fno-stack-check -fno-stack-protector -mno-stack-arg-probe -fno-exceptions \
	 -fno-asynchronous-unwind-tables -ffast-math

LDFLAGS = -static --strip-all -nostdlib -Tapp_dyn.lds --image-base 0 --subsystem native \
		 -L../../lib

all: board_strcat

board_strcat: board_strcat.o
	$(LD) $(LDFLAGS) ../../lib/crtdll.o $< -o $@ -lc.obj
	$(OBJCOPY) board_strcat -O binary
	$(KPACK) --nologo board_strcat

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -rf *.o
