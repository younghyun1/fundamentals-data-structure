#include <stdio.h>

int main (void) {
    int i = 1322;
    int* pi;

    pi = &i;
    printf("%p\n", pi);

    pi = NULL;
    printf("%p\n", pi);

    if (pi == NULL) {
        printf("is null\n");
    }
}
