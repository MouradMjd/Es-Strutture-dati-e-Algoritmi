#include"elemtype.h"
#include"maxheap.h"
#include<stdlib.h>

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data,  h->size* sizeof(ElemType));
    HeapMaxMoveDown(h, 0);
    return;
}


int LastStoneWeight(Heap* h)
{
    while (true)
    {
        if (HeapIsEmpty(h))
        {
            return 0;
        }
        if (h->size==1)
        {
            return *HeapGetNodeValue(h, 0);
        }
        ElemType x = 0;
        ElemType y = 0;
        Pop(h, &x);
        Pop(h, &y);
        if (x != y)
        {
            const ElemType i = x - y;
            HeapMaxInsertNode(h, &i);
        }


    }


}

//void main(void)
//{
//    ElemType d[] = { 77,21,18 };
//    Heap* h = HeapCreateEmpty();
//    for (size_t i = 0; i < 3; i++)
//    {
//        HeapMaxInsertNode(h,&d[i]);
//    }
//    HeapWriteStdout(h);
//    LastStoneWeight(h);
//}