#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int32_t* pi;
    float* pf;

    if (!(pi = (int32_t*) malloc(sizeof (int32_t)))) {
        fprintf(stderr, "Memory allocation failed for 'pi'\n");
        exit(EXIT_FAILURE);
    }

    if (!(pf = (float*) malloc(sizeof (float)))) {
        fprintf(stderr, "Memory allocation failed for 'pf'\n");
        exit(EXIT_FAILURE);
    };

    *pi = 1024;
    *pf = 3.14;

    printf("%d \n@ %p\n%f \n@ %p\n", *pi, pi, *pf, pf);

    free(pi);
    free(pf);
}
