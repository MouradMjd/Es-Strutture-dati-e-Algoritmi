#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>




bool Pop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h))
	{
		return false;
	}

	ElemType n = *HeapGetNodeValue(h, 0);
	e = &n;
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
	h->size = h->size - 1;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;

}