#include<stdlib.h>
#include"elemtype.h"
#include"minheap.h"


Heap* merge(const Heap* h1, const Heap* h2)
{
	Heap* merge = HeapCreateEmpty();



	for (size_t i = 0; i < h1->size; i++)
	{
		HeapMinInsertNode(merge, &h1->data[i]);
	}
	for (size_t i = 0; i < h2->size; i++)
	{
		HeapMinInsertNode(merge, &h2->data[i]);
	}
	return merge;

}


int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	ElemType v1[] ={1,2,5,3 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Heap* h1 = HeapCreateEmpty();
	Heap* h2 = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h1, &v[i]);
	}
	for (unsigned i = 0; i < 4; ++i) {
		HeapMinInsertNode(h2, &v1[i]);
	}
	HeapWriteStdout(h1);
	Heap* d = merge(h1, h2);
	HeapWriteStdout(d);

}


