#ifndef _CZHEAP
#define _CZHEAP

typedef struct heap {
    int n;
    int size;
    void **elems;
    char  (*comp)(void*,void*);
} heap;

void heap_init(heap*, int, char (*)(void*,void*));
void heap_free(heap*);

void heap_insert(heap*, void*);
void* heap_extract(heap*);

#endif /* _CZHEAP */
