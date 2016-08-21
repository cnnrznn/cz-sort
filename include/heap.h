#ifndef _CZHEAP
#define _CZHEAP

typedef struct heap {
    int n;
    int size;
    void **elems;
    int (*comp)(void*,void*);
} heap;

void heap_init(heap*, long, int (*compare)(void*,void*));
void heap_free(heap*);

void heap_insert(heap*, void*);
void* heap_extract(heap*);

#endif /* _CZHEAP */
