#include <stdlib.h>

#include "heap.h"

void heap_init(heap *h, int size, int (*compare)(void*,void*))
{
    h->n = 0;
    h->size = size;
    h->elems = malloc((size+1) * sizeof(void*));
    h->comp = compare;
}

void heap_free(heap *h)
{
    free(h->elems);
}

static void bubble_down(heap *h, int index)
{
    int min_index = index;

    if (2*min_index < h->n) { // are there children?
        // find lesser of children from index
        if (h->comp(h->elems[min_index], h->elems[2*index]) < 0) {
            // swap left child and root
            min_index = 2*index;
        }
        if (h->comp(h->elems[min_index], h->elems[2*index + 1]) < 0) {
            // swap right child and root
            min_index = (2*index) + 1;
        }

        if (min_index != index) {
            // do the swap
            void *tmp = h->elems[index];
            h->elems[index] = h->elems[min_index];
            h->elems[min_index] = tmp;

            // recurse
            bubble_down(h, min_index);
        }
    }
}

static void bubble_up(heap *h, int index)
{
    int parent = index / 2;

    if (h->comp(h->elems[index], h->elems[parent]) > 0) {
        void *tmp = h->elems[index];
        h->elems[index] = h->elems[parent];
        h->elems[parent] = tmp;

        if (parent > 1) {
            bubble_up(h, parent);
        }
    }
}

void heap_insert(heap *h, void *e)
{
    if (h->n < h->size) {
        // increment size
        h->n++;

        // place e in last position

        // bubble up e
    }
}

void* heap_extract(heap *h)
{
    if (h->n > 0) {
        void *e = h->elems[0];

        // put last element at root

        // bubble down root element

        // decrement size
        h->n--;

        return e;
    }

    return NULL;
}
