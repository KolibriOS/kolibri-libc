DLLTOOL = i686-w64-mingw32-dlltool


all: libconsole.obj.a

libconsole.obj.a: console.def
	$(DLLTOOL) --no-leading-underscore -k -d $< -l $@


.PHONY: install
install:
	cp -f libconsole.obj.a ../lib/libconsole.obj.a

.PHONY: clean
clean:
	rm -rf *.a
