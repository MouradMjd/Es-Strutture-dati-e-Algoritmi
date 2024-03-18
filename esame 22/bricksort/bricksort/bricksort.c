#include<stdlib.h>



void BrickSort(int* v, size_t v_size)
{
	int s = 1;
	size_t k = 1;
	size_t i = 0;
	while (s==1)
	{
		s = 0;
		for ( size_t j=i; j < v_size;j++)
		{
			if (v[i] > v[j])
			{
				s = 1;
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}

		}
		for (size_t j = k; j < v_size; j++)
		{
			if (v[k] > v[j])
			{
				s = 1;
				int tmp = v[k];
				v[k] = v[j];
				v[j] = tmp;
			}

		}
		i=i + 2;
		k=k + 2;
	}

}


