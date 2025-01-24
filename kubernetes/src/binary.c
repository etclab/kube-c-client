#include <stdlib.h>
#include <string.h>
#include "../include/binary.h"
#ifdef OPENSSL
#include "openssl/pem.h"
#endif

binary_t* instantiate_binary_t(char* data, int len) {
	binary_t* ret = malloc(sizeof(struct binary_t));
	ret->len=len;
	ret->data = malloc(len);
	memcpy(ret->data, data, len);
	return ret;
}

char *base64encode (const void *b64_encode_this, int encode_this_many_bytes){
#ifdef OPENSSL
#warning [MAZU] TODO: Re-implement base64encode method.
    return NULL;
#else // OPENSSL
#warning Data will not be encoded. If you want to use function "base64encode", please define "-DOPENSSL" when building the library.
    return NULL;
#endif // OPENSSL
}

char *base64decode (const void *b64_decode_this, int decode_this_many_bytes, int *decoded_bytes){
#ifdef OPENSSL
#warning [MAZU] TODO: Re-implement base64decode method.
    return NULL;
#else // OPENSSL
#warning Data will not be decoded. If you want to use function "base64decode", please define "-DOPENSSL" when building the library.
    return NULL;
#endif // OPENSSL
}
