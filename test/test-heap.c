#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

#define INITIAL_SIZE 100
#define SIZE 200

static char int_compare(void *a, void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;

    if (*x < *y) {
        return 1;
    }

    return -1;
}

int main()
{
    int i, j;

    heap h;
    heap_init(&h, INITIAL_SIZE, int_compare);

    int *data = malloc(SIZE * sizeof(int));

    for (i=0; i<SIZE; i++) {
        data[i] = rand() % 100;
        heap_insert(&h, &data[i]);
        printf("%d ", data[i]);
    } printf("\n");

    printf("%d %d\n", h.n, h.size);
    /*
    for (i=1; i<=SIZE; i++) {
        printf("%d ", *(int*)h.elems[i]);
    } printf("\n");
    */

    for (i=0; i<SIZE; i++) {
        int *res = heap_extract(&h);
        printf("%d, ", *res);
        /*
        for (j=1; j<=h.n; j++) {
            printf("%d ", *(int*)h.elems[j]);
        } printf("\n");
        */
    }

    heap_free(&h);
    free(data);

    return 0;
}
