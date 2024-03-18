#include"elemtype.h"
#include"maxheap.h"


void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}


int LastStoneWeight(Heap* h)
{

    while (!HeapIsEmpty(h))
    {
        int y = *HeapGetNodeValue(h,0);
        Pop(h, HeapGetNodeValue(h, 0));
        if (HeapIsEmpty(h))
        {
            return y;
        }
        int x = *HeapGetNodeValue(h, 0);
        Pop(h, HeapGetNodeValue(h, 0));
        if (x == y)
        {
            continue;
        }
        int newy = y - x;
        HeapMaxInsertNode(h, &newy);
    }

    return 0;


}