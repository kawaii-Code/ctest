#include <string.h>
#include <stdlib.h>

#include "example.h"

void array_add(int *dest, int *other, size_t n) {
    for (int i = 0; i < n; i++) {
        dest[i] = other[i] + dest[i];
    }
}

const char *string_concat(const char *a, const char *b) {
    long length = strlen(a) + strlen(b);
    char *result = malloc((length + 1) * sizeof *a);
    *result = '\0';

    strcat(result, a);
    strcat(result, b);

    return result;
}
