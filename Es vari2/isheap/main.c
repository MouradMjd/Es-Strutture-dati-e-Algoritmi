#include"elemtype.h"
#include"minheap.h"


bool isheaprec(const Heap* h,int i)
{
	int l = h->data[HeapLeft(i)];
	int r = h->data[HeapRight(i)];
	if (HeapLeft(i)>=h->size || HeapRight(i) >= h->size)
	{
		return true;
	}
	if (ElemCompare(&h->data[i], &h->data[HeapLeft(i)])>0|| ElemCompare(&h->data[i], &h->data[HeapRight(i)]) > 0)
	{
		return false;
	}

	return isheaprec(h, HeapLeft(i)) && isheaprec(h, HeapRight(i));



}

bool isheap(const Heap* h)
{
	return isheaprec(h, 0);
}





int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Heap* h = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);
	ElemSwap(&h->data[0], &h->data[4]);

	isheap(h);



}