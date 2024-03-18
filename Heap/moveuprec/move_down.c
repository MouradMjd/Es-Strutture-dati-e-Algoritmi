#include"elemtype.h"
#include"minheap.h"
#include<float.h>

/*void HeapMinMoveUpRec(Heap* h, int i)
{
	int p = HeapParent(i);
	if (ElemCompare(&h->data[i], &h->data[p]) < 0)
	{
		ElemSwap(&h->data[p], &h->data[i]);
		i = p;
	}
	else
	{
		return;
	}

	HeapMinMoveUpRec(h, HeapParent(i));
}*/


void HeapMinMoveDownRec(Heap* h, int i)
{
	int r= HeapRight(i);
	int l = HeapLeft(i);
	if (r >= h->size)
	{
		r = 1000;
	}
	if (l >= h->size)
	{
		l = 1000;
	}
	if (ElemCompare(&h->data[i], &h->data[l]) >0&&l<h->size&&ElemCompare(&h->data[l], &h->data[r])<0)
	{
		ElemSwap(&h->data[l], &h->data[i]);
		i = l;
	}
	if(ElemCompare(&h->data[i], &h->data[r]) > 0&&r<h->size && ElemCompare(&h->data[l], &h->data[r]) >0)
	{
		ElemSwap(&h->data[r], &h->data[i]);
		i = r;
	}
	else
	{
		return;
	}


	HeapMinMoveDownRec(h, i);
}


int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Heap* h = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);
	ElemSwap(&h->data[0], &h->data[3]);
	HeapWriteStdout(h);
	HeapMinMoveDownRec(h, 0);
	&h->data[0];

	HeapDelete(h);



}


