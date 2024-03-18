#include<stdlib.h>
#include<math.h>




void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Stooge(int* vector, size_t vector_size) {
    if (vector_size <= 1) {
        return;
    }
    
    if (vector[0] > vector[vector_size - 1]) {
        swap(&vector[0], &vector[vector_size - 1]);
    }
    if (vector_size == 2)
    {
        return;
    }

        size_t m = ceil(vector_size * 2.0 / 3.0);

        Stooge(vector, m);
        Stooge(vector + (vector_size - m), m);
        Stooge(vector, m);
    
}

//void main(void)
//{
//	int v[] = { 6,5,3,7,8,2,1 };
//	size_t s = 7;
//	Stooge(v, s);
//}