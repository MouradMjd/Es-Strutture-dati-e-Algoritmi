#include"elemtype.h"
#include"minheap.h"
#include <stdlib.h>
#include <string.h>






bool IsHeap(const Heap* h)
{
    if (h == NULL)
    {
        return false;
    }
    if (HeapIsEmpty(h)||h->size==1)
    {
        return true;
    }

    for (size_t i = 0; !HeapIsEmpty(h); i++)
    {
        ElemType* l = HeapGetNodeValue(h, HeapLeft(i));
        ElemType* r = HeapGetNodeValue(h, HeapRight(i));
        if (l == HeapGetNodeValue(h,h->size-2) || r == HeapGetNodeValue(h, h->size - 1))
        {
            break;
        }
        int l1 = ElemCompare(l, HeapGetNodeValue(h, i));
        int r1 = ElemCompare(r, HeapGetNodeValue(h, i));
        if (l1 != 1)
        {
            return false;
        }
        if (r1 != 1)
        {
            return false;
        }
     
  

    }
    return true;
}

//Heap* HeapifyMinHeap(const ElemType* v, size_t v_size) {
//    // Costruisco la heap con gli elementi del vettore v
//    Heap* h = HeapCreateEmpty();
//    h->size = v_size;
//    h->data = malloc(sizeof(ElemType) * (v_size));
//    memcpy(h->data, v, v_size * sizeof(ElemType));
//
//    // Chiamo la HeapMinMoveDown a partire dai nodi nel penultimo livello
//    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
//    // le proprietà (min-)heap. Non serve chiamare la HeapMinMoveDown sulle
//    // foglie perché non avrebbe alcun effetto.
//    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
//        HeapMinMoveDown(h, i);
//    }
//    return h;
//}
//
//int main(void) {
//    ElemType v[] = { 1, 12, 0, 21, 2, 18, 77, 8, 9 };
//    size_t v_size = sizeof(v) / sizeof(ElemType);
//
//    Heap* h = HeapifyMinHeap(v, v_size);
//    HeapWriteStdout(h);
//    IsHeap(h);
//    HeapDelete(h);
//
//    return ;
//}