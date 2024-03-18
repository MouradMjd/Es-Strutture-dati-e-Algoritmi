#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>



int KthLeast(const int* v, size_t n, int k)
{
	Heap* hm = HeapCreateEmpty();

	for (size_t i = 0; i < n; i++)
	{
		HeapMinInsertNode(hm, &v[i]);
	}
	int s = 0;
	for (size_t i = 0; i < k; i++)
	{
		s = *HeapGetNodeValue(hm, 0);
		ElemSwap(HeapGetNodeValue(hm,0), HeapGetNodeValue(hm,hm->size-1));
		hm->size = hm->size - 1;
		hm->data = realloc(hm->data,hm->size* sizeof(int));
		HeapMinMoveDown(hm, 0);
	}

	HeapDelete(hm);
	return s;
}

