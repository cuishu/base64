#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base64.h"

int main()
{
	char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char* b64buff = malloc(b64_encode_out_size(strlen(str)));
	puts(b64_encode(b64buff, str, strlen(str)));

	char* buff = malloc(b64_decode_out_size(strlen(b64buff)));
	if (b64_decode(buff, b64buff, strlen(b64buff))) {
		puts(buff);
	}

	free(b64buff);
	free(buff);
	return 0;
}

