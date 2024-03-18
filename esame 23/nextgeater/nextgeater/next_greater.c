#include"elemtype.h"
#include"list.h"
#include"next_greater.h"
#include<stdint.h>
#include<stdlib.h>



extern ElemType* NextGreatercont(const Item* list)
{
	Item* num = list;
	Item* list1 = ListGetTail(list);
	while (!ListIsEmpty(list1))
	{
		if (ElemCompare(num, list1) < 0)
		{
			return list1;
		}
		list1 = ListGetTail(list1);
	}

	return ListCreateEmpty();


}

extern ElemType* NextGreater(const Item* list, size_t* answer_size)
{
	int size = 0;
	if (ListIsEmpty(list))
	{
		*answer_size = 0;
		return NULL;
	}
	Item* i1 = list;
	Item* newlist = ListCreateEmpty();
	Item* rad = ListCreateEmpty();
	while (!ListIsEmpty(i1))
	{
		Item* max = ListCreateEmpty();
		max=NextGreatercont(i1);
		if (ListIsEmpty(max))
		{
			int d = -2147483648;
			newlist = ListInsertBack(newlist, &d);
			if (size == 0)
			{
				rad = newlist;
			}
			size++;
		}
		else
		{
			newlist = ListInsertBack(newlist, max);
			if (size== 0)
			{
				rad = newlist;
			}
			size++;
		}
		i1 = ListGetTail(i1);
	}

	ElemType* v = calloc(size, sizeof(int));
	for (size_t i = 0; i < size; i++)
	{
		v[i] = rad->value;
		rad = ListGetTail(rad);
	}
	*answer_size = size;

	ListDelete(newlist);
	free(rad);
	return v;

}
