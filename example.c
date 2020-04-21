#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base64.h"

#define	SIZE	2048

int main()
{
	unsigned char str[SIZE];

	char* b64buff = malloc(b64_encode_out_size(SIZE));
	unsigned char* buff = malloc(SIZE);

	while (!feof(stdin)) {
		int n = fread(str, 1, SIZE, stdin);
		b64_encode(b64buff, str, n);
		printf("encode output: \n%s\n\n", b64buff);
		if (b64_decode(buff, b64buff, strlen(b64buff))) {
			printf("decode output: \n%s\n", (char*)buff);
		}
	}

	free(b64buff);
	free(buff);
	return 0;
}

