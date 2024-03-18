#include<stdlib.h>



extern void GnomeSort(int* v, size_t v_size)
{
	if (v_size != 1)
	{
		for (size_t i = 0; i < v_size;)
		{
			if (i == 0)
			{
				i = 1;
			}
			if (v[i] >= v[i - 1])
			{
				i++;
			}
			else
			{
				int tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
				i--;
			}

		}
	}

}


