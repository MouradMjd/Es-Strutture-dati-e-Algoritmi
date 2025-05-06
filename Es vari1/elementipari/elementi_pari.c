#include"elemtype.h"
#include"list.h"

extern Item* ElementiPari(const Item* i)
{
	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}
	Item* new_lis = ListCreateEmpty();
	ElemType j = 0;
	while (!ListIsEmpty(i))
	{
		if (j == 0 || ((j%2)== 0))
		{
			new_lis = ListInsertBack(new_lis, ListGetHeadValue(i));
		}
		j++;
		i = i->next;
	}
	return new_lis;
}

void main(void)
{
	int v[] = {1,2,3,4,5};
	Item* i = ListCreateEmpty();
	for (size_t j = 0; j < 5; j++)
	{
		i = ListInsertBack(i, &v[j]);
	}
	ElementiPari(i);
}