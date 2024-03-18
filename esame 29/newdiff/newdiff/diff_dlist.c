#include"diff_dlist.h"
#include"doublelist.h"
#include"elemtype.h"




Item* DListDiff(const Item* i1, const Item* i2)
{
	Item *i11 = i1;
	Item *i22 = i2;

	if (DListIsEmpty(i11) && DListIsEmpty(i22))
	{
		return DListCreateEmpty();
	}
	if (DListIsEmpty(i11))
	{
		return i22;
	}
	if (DListIsEmpty(i22))
	{
		return(i11);
	}

	while (!DListIsEmpty(DListGetTail(i11)))
	{
		i11 = DListGetTail(i11);
	}
	while (!DListIsEmpty(DListGetTail(i22)))
	{
		i22 = DListGetTail(i22);
	}

	Item* newl = DListCreateEmpty();



	
	while (!DListIsEmpty(i11)&&!DListIsEmpty(i22))
	{
	
	
		if (ElemCompare(i11, i22) < 0)
		{
			i11->prev->value = i11->prev->value - 1;
			i11->value=i11->value +10;
		}
		int d = i11->value - i22->value;

		newl = DListInsertHead(&d, newl);
		i11 = (  i11->prev);
		i22 = (  i22->prev);
	}

	if (!DListIsEmpty(i11))
	{
		while (!DListIsEmpty(i11))
		{
			newl = DListInsertHead(&i1->value, newl);
			i11 = i11->prev;
		}

	}
	return newl;
}


void main(void)
{
	ElemType s[] = { 9,5,4 };
	ElemType v[] = { 6,9,6 };
	Item* l = DListCreateEmpty();
	Item* l2 = DListCreateEmpty();

	for (size_t i = 0; i < 3; i++)
	{
		l = DListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		l2 = DListInsertBack(l2, &v[i]);
	}

	Item* q = DListDiff(l, l2);
}