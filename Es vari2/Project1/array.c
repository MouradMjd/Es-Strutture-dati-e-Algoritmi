#include<stdlib.h>

void swap(int* arr, size_t i1, size_t i2)
{
	int tmp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = tmp;
}

void inverti_arrayrec(int* arr, size_t size,size_t i)
{
	if (size == i)
	{
		return;
	}
	if (i > size)
	{
		return;
	}

	swap(arr, i, size);
	inverti_arrayrec(arr, size - 1, i + 1);
}

void inverti_array(int* arr, size_t size)
{
	inverti_arrayrec(arr, size-1, 0);
}

void main(void)
{
	int list[] = { 1,2,3,4,5,7 };
	inverti_array(list, 6);
}