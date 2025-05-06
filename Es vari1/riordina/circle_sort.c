#include<stdlib.h>

extern int CircleSortl(int* v, size_t first,size_t v_size)
{
	int i = first;
	int sc = 0;
	int j = v_size-1;
	int tmp;
	while (i < j)
	{
		if (v[i] > v[j])
		{
			tmp = v[j];
			v[j] = v[i];
			v[i] = tmp;
			sc = 1;
		}
		i++;
		j--;
	}
	return sc;


}


extern void CircleSort(int* v, size_t v_size)
{

	if (v_size == 1)
	{
		return 1;
	}

	int q=CircleSortl(v, 0, v_size);
	int m = v_size / 2;
	if(CircleSort(v, m)|| CircleSort(v + (m), v_size));
	{

	}
	
}



void main(void)
{
	int vett[] = { 3,-1,1,5 };
	CircleSort(vett,4);
}















