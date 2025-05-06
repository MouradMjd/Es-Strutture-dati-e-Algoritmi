#include"elemtype.h"
#include"minheap.h"



void min2max(Heap* h)
{
    for (size_t t = 0; t < h->size; t++)
    {
        for (size_t k = 0; k < h->size; k++)
        {

            int i = t;
            int l, r, big = i;
            bool done;
            do {
                done = true;
                l = HeapLeft(i);
                r = HeapRight(i);

                if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, big)) > 0) {
                    big = l;
                }

                if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, big)) > 0) {
                    big = r;
                }

                if (big != i) {
                    ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, big));
                    i = big;
                    done = false;
                }

            } while (!done);

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

    min2max(h);
    HeapWriteStdout(h);

}
