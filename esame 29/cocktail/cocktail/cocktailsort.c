#include<stdlib.h>
#include<stdio.h>




void CocktailSort(int* v, size_t v_size)
{
	int start = 0;
	int end = v_size - 1;

	while (!(end<=start))
	{
		for (size_t i = start; i < end; i++)
		{
			if (v[i] > v[i + 1])
			{
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}
		end--;
		for (size_t i =end ; i > start; i--)
		{
			if (v[i] < v[i - 1])
			{
				int tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
			}

		}
		start++;
	}


}


