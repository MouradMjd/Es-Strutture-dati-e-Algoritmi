#include"elemtype.h"
#include"minheap.h"
#include<stdlib.h>

bool HeapMinPop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h))
	{
		return false;
	}
	int i = 0;
	ElemSwap(&h->data[i], &h->data[h->size-1]);
	h->size = h->size - 1;//diminuisco il size visto che tolgo un elemento e rialloco
	h->data = realloc(h->data, h->size * sizeof(ElemType));//relloco il vettore data per togliere il dato 
	HeapMinMoveDown(h,i);
	return true;

}

/*int main(void) {
	ElemType v[] = { 32,5,4,6,12,23 };
	size_t v_size = 6;

	Heap* h = HeapCreateEmpty();
	for (unsigned i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);
	int i=0;
	HeapMinPop(h, &i);



}*/
