#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>

extern void HeapDeleteNode(Heap* h, int k)
{
	if (!(k < 0 || k >= h->size))
	{
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, k));
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size = h->size - 1;
		h->data = realloc(h->data, h->size * sizeof(ElemType));
		HeapMinMoveDown(h, 0);
	}
}
