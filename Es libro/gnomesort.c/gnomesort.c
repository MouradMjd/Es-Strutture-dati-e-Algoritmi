#include<stdlib.h>







void GnomeSort(int* v, size_t v_size)
{
	int tmp = 0;
	if (v_size != 1)
	{
		for (size_t i = 0; i < v_size;)
		{
			if (i == 0)
			{
				i++;
			}
			if (v[i] >= v[i - 1])
			{
				i++;
			}
			else
			{
				tmp = v[i - 1];
				v[i - 1] = v[i];
				v[i] = tmp;
				i = i - 1;
			}
		}
	}
}

//void main(void)
//{
//	int s[] = { 3,2,4,7 };
//	GnomeSort(s, 1);
//}