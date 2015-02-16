CC = ${CROSS_COMPILE}gcc
LDFLAGS := -lxdma
CFLAGS := -c -Wall -Werror
INCLUDES := -I. -I../dev


.PHONY : all
all : libxdma


libxdma.o :
	$(CC) $(CFLAGS) $(INCLUDES) -fpic libxdma.c


libxdma : libxdma.o
	$(CC) -shared -Wl,-soname,libxdma.so -o libxdma.so libxdma.o


install : libxdma
	cp ${PWD}/libxdma.so /usr/local/lib
	cp ${PWD}/libxdma.h /usr/localinclude
	chmod 0755 /usr/local/lib/libxdma.so
	ldconfig


uninstall :
	rm /usr/lib/libxdma.so
	rm /usr/include/libxdma.h
	ldconfig


.PHONY : clean
clean :
	rm -f *.o libxdma.so
