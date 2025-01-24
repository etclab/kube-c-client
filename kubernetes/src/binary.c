#include <stdlib.h>
#include <string.h>
#include "../include/binary.h"
#ifdef OPENSSL
#include "openssl/evp.h"
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
    // TODO(shadowbearvr): Verify this works...
    if (!b64_encode_this || encode_this_many_bytes <= 0) {
        return NULL;  // Return NULL for invalid input.
    }

    // Calculate the output buffer size: base64 encoding produces 4 output bytes for every 3 input bytes.
    int encoded_len = 4 * ((encode_this_many_bytes + 2) / 3);
    char *encoded_data = (char *)malloc(encoded_len + 1); // +1 for the null-terminator.
    if (!encoded_data) {
        return NULL;  // Return NULL if memory allocation fails.
    }

    // Perform base64 encoding.
    int output_len = EVP_EncodeBlock(
        (unsigned char *)encoded_data,        // Output buffer.
        (const unsigned char *)b64_encode_this, // Input data to encode.
        encode_this_many_bytes                // Length of input data.
    );

    // Null-terminate the encoded string.
    encoded_data[output_len] = '\0';

    return encoded_data; // Return the base64-encoded string.
#else // OPENSSL
#warning Data will not be encoded. If you want to use function "base64encode", please define "-DOPENSSL" when building the library.
    return NULL;
#endif // OPENSSL
}

char *base64decode (const void *b64_decode_this, int decode_this_many_bytes, int *decoded_bytes){
#ifdef OPENSSL
    // TODO(shadowbearvr): Verify this works...
    if (!b64_decode_this || !decoded_bytes) {
        return NULL; // Return NULL for invalid input.
    }

    // Calculate the maximum possible size of the decoded data.
    size_t max_decoded_len = 3 * (decode_this_many_bytes / 4);
    unsigned char *decoded_data = (unsigned char *)malloc(max_decoded_len);
    if (!decoded_data) {
        return NULL; // Return NULL if memory allocation fails.
    }

    size_t output_len = 0; // To store the length of the decoded data.
    size_t input_len = decode_this_many_bytes; // Use decode_this_many_bytes as the input length.

    // Decode the base64 input.
    if (EVP_DecodeBase64(
            decoded_data,             // Output buffer for decoded data.
            &output_len,              // Output length after decoding.
            max_decoded_len,          // Max size of the output buffer.
            (const unsigned char *)b64_decode_this, // Base64-encoded input.
            input_len                 // Length of the base64-encoded input.
        ) != 1) {
        free(decoded_data);
        return NULL; // Return NULL on decode failure.
    }

    *decoded_bytes = (int)output_len; // Store the length of the decoded data.
    return (char *)decoded_data; // Return the decoded data buffer.
#else // OPENSSL
#warning Data will not be decoded. If you want to use function "base64decode", please define "-DOPENSSL" when building the library.
    return NULL;
#endif // OPENSSL
}
