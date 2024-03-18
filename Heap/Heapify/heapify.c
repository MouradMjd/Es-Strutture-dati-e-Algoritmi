#include"elemtype.h"
#include"minheap.h"



Heap* HeapMinHeapify(const ElemType* v, size_t v_size)
{
	Heap* h = HeapCreateEmpty();

	for (size_t i = 0; i < v_size; i++)
	{
		HeapMinInsertNode(h, &v[i]);
	}
	return h;
}


void main(void)
{
	ElemType v[] = { 4, 6 ,1, 2, 12, 23 };
	Heap* d = HeapMinHeapify(v, 6);
	HeapWriteStdout(d);
}
