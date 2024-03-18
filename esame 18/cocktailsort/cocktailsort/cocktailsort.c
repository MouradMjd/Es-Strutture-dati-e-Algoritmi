#include<stdlib.h>

void CocktailSort(int* v, size_t v_size)
{
	if (v == NULL)
	{
		return;
	}
	size_t start = 0;
	size_t end = v_size - 1;
	int s = 1;

	while (end>start&&s==1)
	{
		s = 0;

		for (size_t i = start; i <end ; i++)
		{
			if (v[i] > v[i + 1])
			{
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				s = 1;
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
				s = 1;
			}

		}
		start++;

	}
}

