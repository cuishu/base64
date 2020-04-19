#ifndef	BASE64_H
#define	BASE64_H

static inline size_t b64_encode_out_size(size_t size) { return ((size + 2) / 3 ) * 4 + 1; }
static inline size_t b64_decode_out_size(size_t size) { return ((size / 4) * 3); }

char* b64_encode(char* out, char* in, int in_len);
_Bool b64_decode(char* out, char* in, int in_len);

#endif
