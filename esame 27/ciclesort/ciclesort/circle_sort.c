#include<stdlib.h>



void CircleSortrec(int* v, size_t v_size,int *s)
{
	if (v_size == 1)
	{
		return;
	}

	for (size_t i = 0,j=v_size-1; i<j; i++,j--)
	{
		if (v[i] > v[j])
		{
			*s = 1;
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
	if (v_size % 2 != 0)
	{
		if (v_size % 2 != 0 && v[v_size / 2] > v[v_size / 2 + 1]) {
			int temp = v[v_size / 2];
			v[v_size / 2] = v[v_size / 2 + 1];
			v[v_size / 2 + 1] = temp;
		}
	}


	CircleSortrec(v, v_size/2,s);
	CircleSortrec(v + (v_size/ 2 +1), v_size/2+1 ,s);

}

void CircleSort(int* v, size_t v_size) {
	if (v == NULL)
	{
		return NULL;
	}
	int s = 1;
	while (s==1)
	{
		s = 0;
		CircleSortrec(v, v_size,&s);
	}
}

void main(void)
{
	int v[] = { 3,1,-1,5 };
	CircleSort(v, 4);

}


