CC = kos32-gcc
STRIP = kos32-strip
CFLAGS = -I../include -D_BUILD_LIBC -nostdinc -c -Os -fno-builtin -fno-ident -fomit-frame-pointer -ffreestanding -fno-leading-underscore

all: libc.obj

libc.obj: libc.o
	$(STRIP) --strip-unneeded $< -o $@

libc.o: libc.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.obj *.o