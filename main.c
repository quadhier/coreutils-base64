#include "base64.h"

#include <stdio.h>
#include <string.h>

int main() {
  char *in = (char *) "abc\n";
  idx_t inlen = strlen(in);
  printf("before encode: %s\n", in);

  char *out;
  idx_t outlen = base64_encode_alloc(in, inlen, &out);
  if (out == NULL && outlen == 0 && inlen != 0) {
    fprintf(stderr, "input too long\n");
    return 0;
  } else if (out == NULL) {
    fprintf(stderr, "memory allocation error\n");
    return 0;
  }
  printf("after encode: %s\n", out);

  bool ok = base64_decode_alloc(out, strlen(out), (char **)&in, &inlen);
  if (!ok) {
    fprintf(stderr, "input was not valid base64\n");
    return 0;
  } else if (out == NULL) {
    fprintf(stderr, "memory allocation error\n");
    return 0;
  }
  printf("after decode: %s\n", in);
}
