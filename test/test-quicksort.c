#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

#define SIZE 10

int main() {
    int i;

    double *arr = malloc(SIZE * sizeof(double));

    for (i=0; i<SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%f ", arr[i]);
    } printf("\n");

    quicksort(0, SIZE-1, arr);

    for (i=0; i<SIZE; i++) {
        printf("%f ", arr[i]);
    } printf("\n");

    return 0;
}
