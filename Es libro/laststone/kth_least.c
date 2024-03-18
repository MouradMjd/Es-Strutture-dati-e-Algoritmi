#include"elemtype.h"
#include"minheap.h"
#include<stdint.h>
#include<stdlib.h>

//
//extern int KthLeastrec(Heap *h, int k,int i,int l,int *min)
//{
//
//	if (i > h->size)
//	{
//		return;
//	}
//	if (*HeapGetNodeValue(h, i) >= *min&&l!=k)
//	{
//		*min = *HeapGetNodeValue(h, i);
//		l++;
//		return;
//	}
//
//
//
//	KthLeastrec(h, k, HeapLeft(i),l, min);
//	KthLeastrec(h, k, HeapRight(i),l, min);
//
//
//
//}
//extern int KthLeast(const int* v, size_t n, int k)
//{
//	Heap* h = HeapCreateEmpty();
//
//	for (size_t i = 0; i < n; i++)
//	{
//		HeapMinInsertNode(h, &v[i]);
//	}
//	HeapWriteStdout(h);
//	int min =0;
//	KthLeastrec(h, k,0,0,&min);
//	return min;
//}




extern int KthLeast(const int* v, size_t n, int k)
{
	Heap* h = HeapCreateEmpty();

	for (size_t i = 0; i < n; i++)
	{
		HeapMinInsertNode(h, &v[i]);
	}
	HeapWriteStdout(h);

	while (k-->0)
	{
		if (k == 0)
		{
			break;
		}
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size = h->size--;
		HeapMinMoveDown(h, 0);

	}
	return *HeapGetNodeValue(h, 0);
}

int main(void) {
    ElemType v[] = { 0, 2, 4, 8, 12, 18, 77, 21, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

	KthLeast(v,9, 9);

    return ;
}