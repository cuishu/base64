#include <stdio.h>

static const char base64en[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/',
};

static const unsigned char base64de[] = {
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  62, 0,  0,  0,  63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0,  0,  0,  0,  0,  0,
	0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,  0,  0,  0,  0,
	0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0,  0,  0,  0,  0
};

int b64_encode(char* out, unsigned char* in, int in_len)
{
	register int k = 0, i=0;
	unsigned char a, b;
	for (; i < in_len; i+=3) {
		out[k++] = base64en[in[i] >> 2];
		switch(in_len-i) {
		case 1:
			out[k++] = base64en[in[i] << 4 & 0x3f];
			out[k++] = '=';
			out[k++] = '=';
			break;
		case 2:
			a = in[i+1];
			out[k++] = base64en[((in[i] << 4) & 0x3f) | (a >> 4)] ;
			out[k++] = base64en[(a << 2) & 0x3f];
			out[k++] = '=';
			break;
		default :
			a = in[i+1];
			b = in[i+2];
			out[k++] = base64en[((in[i] << 4) & 0x3f) | (a >> 4)] ;
			out[k++] = base64en[((a << 2) & 0x3f) | (b >> 6)];
			out[k++] = base64en[b & 0x3f];
			break;
		}
	}
	out[k] = '\0';
	return k;
}

int b64_decode(unsigned char* out, char* in, int in_len)
{
	if (in_len & 0x3) {
		return 0;
	}

	register int k = 0, i=0;
	char b, c;
	for (; i < in_len; i+=4) {
		b = base64de[(unsigned char)in[i+1]];
		c = base64de[(unsigned char)in[i+2]];
		out[k++] = base64de[(unsigned char)in[i]] << 2 | b >> 4;
		out[k++] = b << 4 | c >> 2;
		out[k++] = c << 6 | base64de[(unsigned char)in[i+3]];
	}
	return k;
}

