#include "array.h"
#include "binsearch.h"

#include <stdlib.h>
#include <stdio.h>

char int_compare(void *a, void *b)
{
    int *x = a;
    int *y = b;

    if (*x < *y)
        return 1;
    else if (*x > *y)
        return -1;
    else
        return 0;
}

int main()
{
    int i;
    array arr;

    int *data = malloc(100 * sizeof(int));
    for (i=0; i<100; i++)
        data[i] = i;

    array_init(&arr, 100, int_compare);
    for (i=0; i<100; i++)
        arr.elems[i] = &data[i];

    int target = 99;

    int *res = binsearch(&arr, (void*)(&target), 0, arr.size-1);

    printf("Target: %d\n", target);
    printf("Found:  %d\n", *res);
}
