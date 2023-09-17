#include <string.h>
#include <stdlib.h>

#include "example.h"

int sum(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

void arr_add(int *dest, int *other, size_t n) {
    for (int i = 0; i < n; i++) {
        dest[i] = other[i] + dest[i];
    }
}

const char *greet(const char *name) {
#define HELLO "Hello, "

    long len = strlen(HELLO) + strlen(name);
    char *greeting = malloc((len + 1) * sizeof *name);
    *greeting = '\0';

    strcat(greeting, HELLO);
    strcat(greeting, name);

    return greeting;
}
