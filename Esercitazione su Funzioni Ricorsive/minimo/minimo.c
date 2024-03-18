#include<stdint.h>

int Minimorec(const int* v, int v_size,int *s)
{
	if (v_size == 0)
	{
		return;
	}
	if (v[(v_size-1)] < (* s))
	{
		*s = v[v_size-1];
	}

	Minimorec(v, v_size - 1, s);

}

int Minimo(const int* v, int v_size)
{
	int s = INT16_MAX;
	Minimorec(v, v_size, &s);
	return s;
}



void main(void)
{
	int s[] = { 3,1,6,5,-3,0 };
	int size = 6;
	Minimo(s, size);
}