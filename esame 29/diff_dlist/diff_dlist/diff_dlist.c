#include"diff_dlist.h"
#include"elemtype.h"
#include"list.h"




Item* DListDiff(const Item* i1, const Item* i2)
{
	Item *i11 = i1;
	Item *i22 = i2;

	if (ListIsEmpty(i11) && ListIsEmpty(i22))
	{
		return ListCreateEmpty();
	}
	if (ListIsEmpty(i11))
	{
		return i2;
	}
	if (ListIsEmpty(i22))
	{
		return(i11);
	}

	while (!ListIsEmpty(ListGetTail(i11)))
	{
		i11 = ListGetTail(i11);
	}
	while (!ListIsEmpty(ListGetTail(i22)))
	{
		i22 = ListGetTail(i22);
	}

	Item* newl = ListCreateEmpty();




	while (!ListIsEmpty(i11)&&!ListIsEmpty(i22))
	{
		int w = 0;
		int s = 0;
		if (w != 0)
		{
			i11->value = i11->value - 1;
			w--;
		}
		if (ElemCompare(i11, i22) < 0)
		{
			w++;
			i11->value=i11->value +10;
		}
		int d = i11->value - i22->value;

		newl = ListInsertHead(&d, newl);
		i11 = ( * i11->prev);
		i22 = ( * i22->prev);
	}

	if (!ListIsEmpty(i11))
	{
		while (!ListIsEmpty(i11))
		{
			newl = ListInsertHead(&i1->value, newl);
			i11 = i11->prev;
		}

	}



	return newl;


}


void main(void)
{
	ElemType s[] = { 9,5,4 };
	ElemType v[] = { 6,9 };
	Item* l = ListCreateEmpty();
	Item* l2 = ListCreateEmpty();

	for (size_t i = 0; i < 3; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 2; i++)
	{
		l2 = ListInsertBack(l2, &v[i]);
	}

	Item* q = DListDiff(l, l2);
}