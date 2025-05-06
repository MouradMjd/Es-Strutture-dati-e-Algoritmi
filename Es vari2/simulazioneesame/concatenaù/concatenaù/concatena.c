#include"doublelist.h"
#include"elemtype.h"




Item* ConcatenaN(Item** v, size_t v_size)
{
	if (v == NULL || v_size == 0)
	{
		return DListCreateEmpty();
	}
	Item* testa = NULL;
	int x = 0;
	for (size_t i = 0; i < v_size-1; i++)
	{
		if (v[i] == NULL)
		{
			continue;
		}
		if (testa == NULL)
		{
			testa = DListGetHeadValue(v[i]);
		}

		while (!DListIsEmpty(v[i]))
		{

			v[i] = DListGetTail(v[i]);
			if (v[i] == NULL)
			{
				break;
			}
			if (v[i]->next == NULL)
			{
				for (size_t j = i+1; j < v_size; j++)
				{
					if (v[j] == NULL)
					{
						continue;
					}
					x = 1;
					v[i]->next = v[j];
					break;
				}
			}
			if (x == 1)
			{
				x = 0;
				break;
			}
		}

	}

	return testa;

}


