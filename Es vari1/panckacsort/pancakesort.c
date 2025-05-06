#include<stdlib.h>


void flip(int* v, size_t i)
{
	int tmp = 0;
	tmp = v[0];
	v[0] = v[i];
	v[i] = tmp;

}
int indmax(int *v,int j)
{
	int indmax = 0;
	for (size_t i = 0; i < j; i++)
	{
		if (v[i] > v[indmax])
		{
			indmax = i;
		}

	}
	return indmax;
}


void PancakeSort(int* v, size_t v_size)
{
	if (v != NULL)
	{
		size_t currsize = v_size;

		while (currsize != 1)
		{
			int m = indmax(v, currsize);
			flip(v, m);
			flip(v, currsize - 1);
			currsize--;
		}
	}
}

//void main(void)
//{
//	int v[] = { 4,3,2,1 };
//	PancakeSort(v, 4);
//}