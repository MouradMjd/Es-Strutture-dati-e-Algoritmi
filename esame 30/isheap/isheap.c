#include"elemtype.h"
#include"minheap.h"




bool IsHeap(const Heap* h)
{
	if (HeapIsEmpty(h))
	{
		return true;
	}

	for (size_t i = 0; i < h->size; i++)
	{
		int l = HeapLeft(i);
		int r = HeapRight(i);
		if (ElemCompare(&h->data[i], &h->data[l]) > 0 && l < h->size)
		{
			return false;
		}
		if (ElemCompare(&h->data[i], &h->data[r]) > 0 && r < h->size)
		{
			return false;
		}

	}
	return true;
}