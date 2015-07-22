CC = ${CROSS_COMPILE}gcc
LDFLAGS := -L../lib -lxdma
CFLAGS := -c -Wall
INCLUDES := -I. -I../dev -I../lib

EXECUTABLE = \
	app \
	demo \
	test \
	scan


.PHONY : all
all: $(EXECUTABLE)


test : xdma-test.o
	$(CC) $< -o $@ $(LDFLAGS)


demo : xdma-demo.o
	$(CC) $< -o $@ $(LDFLAGS)


app : xdma-app.o
	$(CC) $< -o $@ $(LDFLAGS)

scan : dma_scan.o
	$(CC) $< -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@


.PHONY : clean
clean:
	rm -f *.o $(EXECUTABLE)
