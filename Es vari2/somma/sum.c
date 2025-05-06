#include"elemtype.h"
#include"list.h"
#include<stdlib.h>


Item* sum(const Item* i1, const Item* i2)
{
	if (ListIsEmpty(i1))
	{
		return i1;
	}

	if (ListIsEmpty(i2))
	{
		return i2;
	}
	Item* tmp1 = i1;
	int size1 = 0;
	Item* tmp2 = i2;
	int size2 = 0;
	while (!ListIsEmpty(tmp1))
	{
		size1++;
		tmp1 = ListGetTail(tmp1);
	}
	while (!ListIsEmpty(tmp2))
	{
		size2++;
		tmp2 = ListGetTail(tmp2);
	}

	int size = 0;
	if (size1 <= size2)
	{
		size = size1;
	}
	else
	{
		size = size2;
	}

	Item* tmp11 = ListCreateEmpty();
	Item* tmp22 = ListCreateEmpty();
	for (size_t k = 0; k < size1; k++)
	{
		tmp11 = ListInsertBack(tmp11, ListGetHeadValue(i1));
		i1 = ListGetTail(i1);
	     
	}
	for (size_t k = 0; k < size2; k++)
	{
		tmp22 = ListInsertBack(tmp22, ListGetHeadValue(i2));
		i2 = ListGetTail(i2);

	}

	Item* sum = ListCreateEmpty();


	for (size_t i = 0; i < size; i++)
	{
		int sum1 = *ListGetHeadValue(tmp11) + *ListGetHeadValue(tmp22);
		int ceck = sum1 / 10;
		if (ceck != 0)
		{
			int r = sum1 / 10;
			ElemType* s = ListGetTail(tmp11);
			*s = *s + r;
			sum1 = sum1 % 10;
		}
		sum = ListInsertBack(sum, &sum1);
		tmp11 = ListGetTail(tmp11);
		tmp22 = ListGetTail(tmp22);
	}
	if (size1 != size2)
	{
		if (size1 > size2)
		{
			while (!ListIsEmpty(tmp11))
			{
				sum = ListInsertBack(sum, ListGetHeadValue(tmp11));
				tmp11 = tmp11->next;
			}
		}
		else
		{
			sum = ListInsertBack(sum, ListGetHeadValue(tmp22));
			tmp22 = tmp22->next;
		}

	}

	ListDelete(tmp11);
	ListDelete(tmp22);
	return sum;
	


}


void main(void)
{
	ElemType s[] = { 1,7,5,4 };
	ElemType v[] = { 1,7,4 };
	Item* l = ListCreateEmpty();
	Item* l2 = ListCreateEmpty();
	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		l2 = ListInsertBack(l2, &v[i]);
	}
	Item* l1 = sum(l, l2);
}