#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>

extern bool Pop(Heap* h, ElemType* e)
{
    if (h->size == 0)
    {
        return false;
    }
	if (h->size == 1)
	{
		*e=*HeapGetNodeValue(h, 0);
        free(h->data);
		h=HeapCreateEmpty();
		return true;
	}
    *e = *HeapGetNodeValue(h, 0);
    ElemSwap(HeapGetNodeValue(h, 0),HeapGetNodeValue(h, (h->size-1)));
    h->size = h->size-1;
    h->data = realloc(h->data,h->size * sizeof(ElemType));
    HeapMinMoveDown(h,0);
    HeapWriteStdout(h);
    return h;
    return true;

}

//int main(void) {
//    ElemType v[] = { 4, 6, 12, 10, 8, 24, 34, 50, 32, 25, 3 };
//    size_t v_size = sizeof(v) / sizeof(ElemType);
//
//    Heap* h = HeapCreateEmpty();
//    for (unsigned i = 0; i < v_size; ++i) {
//        HeapMinInsertNode(h, &v[i]);
//    }
//    HeapWriteStdout(h);
//    ElemType e=0;
//    Pop(h, &e);
//    HeapWriteStdout(h);
//
//    return; 
//
//}