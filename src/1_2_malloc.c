#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)                              \
    do {                                          \
        (p) = malloc((s));                        \
        if (!(p)) {                               \
            fprintf(stderr, "Memory allocation failed\n"); \
            exit(EXIT_FAILURE);                   \
        }                                         \
    } while (0)

int main (void) {
    int32_t* pi;
    float* pf;

    MALLOC(pi, sizeof(int32_t));
    MALLOC(pf, sizeof(float));

    *pi = 1024;
    *pf = 3.14;

    printf("%d \n@ %p\n%f \n@ %p\n", *pi, pi, *pf, pf);

    free(pi);
    free(pf);
}
