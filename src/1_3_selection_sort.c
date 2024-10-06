#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 200

uint32_t get_smallest_and_pop(uint32_t* array, size_t* len);

int main (void) {
    srand((unsigned int)time(NULL)); // seed the random number generator
    clock_t start_time = clock(); // Start timing

    uint32_t* int_array = (uint32_t*) malloc(LEN * sizeof(uint32_t));

    for (size_t i = 0; i < LEN; i++) {
        int_array[i] = (uint32_t)rand();
    }

    uint32_t* sorted_array = (uint32_t*) malloc(LEN * sizeof(uint32_t));


    size_t current_len = LEN;
    for(size_t counter = 0; counter < LEN; counter++) {
        sorted_array[counter] = get_smallest_and_pop(int_array, &current_len);
    }

    clock_t end_time = clock(); // End timing
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds

    for (size_t i = 0; i < LEN; i++) {
        printf("%u\n", sorted_array[i]);
    }

    printf("Total time taken: %.2fms\n", time_taken);

    free(int_array);
    free(sorted_array);
}

uint32_t get_smallest_and_pop(uint32_t* array, size_t* len) {
    uint32_t smallest = UINT32_MAX;
    size_t smallest_index = 0;

    // Find the smallest element and its index
    for (size_t i = 0; i < *len; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smallest_index = i;
        }
    }

    // Shift elements to "pop" the smallest one
    for (size_t i = smallest_index; i < *len - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrease length since one element was removed
    (*len)--;

    // Return the smallest element
    return smallest;
}
