#include<stdint.h>



void BrickSort(int* v, size_t v_size)
{
	int ordinamento = 0;
	int q = 0;
	int j=1;

	while (v_size >1 && !ordinamento)
	{
		ordinamento = 1;
		for (size_t i = q,u=q; u < v_size-1; u++)
		{
			if (v[i]>v[u+1])
			{
				int tmp = v[i];
				v[i] = v[u + 1];
				v[u + 1] = tmp;
				ordinamento = 0;
			}
		}
		for (size_t i = j,u=j; u < v_size-1; u++)
		{
			if (v[i] > v[u + 1])
			{
				int tmp = v[i];
				v[i] = v[u + 1];
				v[u + 1] = tmp;
				ordinamento = 0;
			}
		}
		q = q + 2;
		j = j + 2;
		
	}
}

//void main(void)
//{
//	int v[] = { 2,6,1,8,9,4 };
//	BrickSort(v, 6);
//}