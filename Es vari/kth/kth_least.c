#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>

extern int KthLeast(const int* v, size_t n, int k)
{
    Heap* h = HeapCreateEmpty();
    for (size_t i = 0; i < n; i++)
    {
        HeapMinInsertNode(h, &v[i]);
    }


    while (k!=1)
    {
        ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
        h->size--;
        h->data = realloc(h->data, h->size * sizeof(ElemType));
        HeapMinMoveDown(h, 0);
        k--;
    }
    int min = *HeapGetNodeValue(h, 0);
    HeapDelete(h);
    return min ;

}

int main(void) {
    ElemType v[] = {1,5,6,3,4,6};
    size_t v_size = sizeof(v) / sizeof(ElemType);

	KthLeast(v,5, 3);

    return ;
}