#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>
#include<string.h>




extern void HeapMinHeapsort(Heap* h)
{
	ElemType* arr = malloc(h->size * sizeof(ElemType));

	Heap* h1 = HeapCreateEmpty();
	for (unsigned i = 0; i < h->size; ++i) {
		HeapMinInsertNode(h1,&h->data[i]);
	}
	int r = 0;
	int s = h->size;
	for (size_t i = 0,w=s-1; i < s; i++,w--)
	{
		arr[w] = h1->data[0];
		ElemSwap(&h1->data[r], &h1->data[h1->size - 1]);
		h1->size = h1->size - 1;
		h1->data = realloc(h1->data, h1->size * sizeof(ElemType));
		HeapMinMoveDown(h1, 0);

	}
	for (size_t i = 0; i < s; i++)
	{
		h->data[i] = arr[i];
	}
	free(arr);
	HeapDelete(h1);

}


/*int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Heap* h = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);
	HeapMinHeapsort(h);



}*/