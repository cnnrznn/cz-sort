#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

#define SIZE 10

char comp_double(void *x, void *y)
{
    double *a = (double*)x;
    double *b = (double*)y;

    if (*a < *b) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    int i;

    // create data
    double *data = malloc(SIZE * sizeof(double));
    array arr;
    array_init(&arr, SIZE, comp_double);

    for (i=0; i<SIZE; i++) {
        data[i] = rand() % 100;
        arr.elems[i] = &data[i];
        printf("%f ", data[i]);
    } printf("\n");

    quicksort(0, SIZE-1, &arr);

    for (i=0; i<SIZE; i++) {
        printf("%f ", *(double*)(arr.elems[i]));
    } printf("\n");

    free(data);
    array_free(&arr);

    return 0;
}
