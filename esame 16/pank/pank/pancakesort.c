#include<stdio.h>
#include<stdlib.h>
void flip(int* v, size_t i)
{
	int tmp = 0;
	tmp = v[0];
	v[0] = v[i];
	v[i] = tmp;

}
int maxx(int *v, int s)
{
	int in = 0;
	int s1 = 0;
	for (size_t i = 0; i <= s; i++)
	{
		if (s1 > v[i])
		{
			s1 = v[i];
			in = i;
	   }
	}
	return in;
}
void PancakeSort(int* v, size_t v_size)
{
	size_t curr_size = v_size;

	while(curr_size!=1)
	{
		int m = maxx(v, curr_size-1);
		flip(v, m);
		flip(v, curr_size - 1);
		curr_size--;
	}



}


void main(void)
{
	int v[] = { 5,4,3,2,1 };
	PancakeSort(v, 5);
}