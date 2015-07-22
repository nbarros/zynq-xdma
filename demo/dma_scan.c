#include "libxdma.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const int LENGTH = 1025;
	uint32_t i;
	//uint32_t *src;
	uint32_t *dst;

	printf("Starting the DMA...\n");
	if (xdma_init() < 0) {
		exit(EXIT_FAILURE);
	}
	printf("DMA started!\n");


	dst = (uint32_t *) xdma_alloc(LENGTH, sizeof(uint32_t));
	//src = (uint32_t *) xdma_alloc(LENGTH, sizeof(uint32_t));

	// fill src with a value
//	for (i = 0; i < LENGTH; i++) {
//		src[i] = 'B';
//	}
//	src[LENGTH - 1] = '\n';

	// fill dst with nothing
	for (i = 0; i < LENGTH; i++) {
		dst[i] = 0;
	}
	//dst[LENGTH - 1] = '\n';

	printf("test: dst buffer before any transmission:\n");
	for (i = 0; i < LENGTH; i++) {
		printf("%u ", dst[i]);
	}
	printf("\n");

//	if (0 < xdma_num_of_devices()) {
//		xdma_perform_transaction(0, XDMA_WAIT_NONE, src, LENGTH, dst,
//					 LENGTH);
//	}
	int ret = 0;
	uint32_t pos = 0;
	while (ret>= 0) {
		// CHanged length to 16 to make sure that we pull a frame at a time
		ret = xdma_perform_transaction(0,XDMA_WAIT_DST,NULL,0,dst,16);

		printf("===: dst buffer after transmission [pos : %d]:\n",pos);
			for (i = pos+3; i >= pos; --i) {
				printf("%u[%X] ", dst[i],dst[i]);
			}
			printf("\n");
			if (ret < 0) {

				printf("Something happened [%d].\n",ret);
				break;
			}
			pos += 4;
	}

	printf("test: dst buffer after transmit:\n");
	for (i = 0; i < LENGTH; i++) {
		printf("%u[%X] ", dst[i],dst[i]);
	}
	printf("\n");

	xdma_exit();

	return 0;
}
