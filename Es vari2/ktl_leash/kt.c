#include<stdlib.h>
#include"elemtype.h"
#include"minheap.h"

ElemType* ktlleash(const Heap* h, int k)
{
	Heap* h1 = HeapCreateEmpty();
	for (size_t i = 0; i < h->size; i++)
	{
		HeapMinInsertNode(h1, &h->data[i]);
	}

	for (size_t i = 1; i < k; i++)
	{
		ElemSwap(&h1->data[0], &h1->data[h1->size - 1]);
		h1->size = h1->size - 1;
		h1->data = realloc(h1->data, h1->size * sizeof(ElemType));
		HeapMinMoveDown(h1, 0);

	}

	for (size_t k = 0; k < h->size; k++)
	{
		ElemType* r = &h->data[k];
		if (ElemCompare(&h1->data[0], &h->data[k]) == 0)
		{
			return  &h->data[k];
		}
	}

}




int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Heap* h = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);


	ElemType* r = ktlleash(h, 4);



}