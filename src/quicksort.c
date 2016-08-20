#include <stdio.h>

#include "quicksort.h"

/*
 * I had some fun with naming conventions in this file:
 *  lohi - the place where lo and hi meet
 */

void swap(int a, int b, double *arr)
{
    double tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int lo, int hi, double *arr)
{
    double pivot = arr[hi];
    int i, lohi=lo;

    for (i=lo; i<hi; i++) {
        if (arr[i] < pivot) {
            swap(i, lohi++, arr);
        }
    }
    swap(hi, lohi, arr);

    return lohi;
}

void quicksort(int lo, int hi, double *arr)
{
    if (hi < lo) {
        return;
    }

    int lohi = partition(lo, hi, arr);

    quicksort(lo, lohi-1, arr);
    quicksort(lohi+1, hi, arr);
}
