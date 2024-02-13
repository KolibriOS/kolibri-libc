CC = i686-w64-mingw32-gcc
STRIP = i686-w64-mingw32-strip
DLLTOOL = i686-w64-mingw32-dlltool
CFLAGS = -I../include -D_BUILD_LIBC -nostdinc -c -Os -fno-builtin -fno-ident -fomit-frame-pointer -ffreestanding -fno-leading-underscore

all: libc.obj.a libc.obj 

libc.obj.a: libc.def
	$(DLLTOOL) --no-leading-underscore -d $< -l $@

libc.obj: libc.o
	$(STRIP) --strip-unneeded $< -o $@

libc.o: libc.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.obj *.o