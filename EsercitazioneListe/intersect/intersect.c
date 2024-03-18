#include<stdio.h>
#include<stdlib.h>
#include"elemtype.h"
#include"list.h"
#include<stdbool.h>

bool init(int *e,Item *i2)
{
	while(1)
	{
		if (ElemCompare(e, ListGetHeadValue(i2)) == 0)
		{
			return true;
		}
		i2 = ListGetTail(i2);
		if (i2 == NULL)
		{
			break;
		}
	}
	return false;

}
Item* diff(const Item* i1, const Item* i2)
{
	Item* i11 = i1;
	Item* i22 = i2;

	Item* l = ListCreateEmpty();


	while (1)
	{
		if (!init(ListGetHeadValue(i11), i22))
		{
			l = ListInsertBack(l, ListGetHeadValue(i11));
		}
		i11 = ListGetTail(i11);
		if (i11 == NULL)
		{
			break;
		}
	}

	ListDelete(i11);
	ListDelete(i22);

	return l;
}

bool isnotrep(int *e,Item *l)
{
	if (l == NULL)
	{
		return true;
	}
	while (1)
	{
		if (ElemCompare(e, ListGetHeadValue(l)) == 0)
		{
			return false;
		}
		l = ListGetTail(l);
		if (l == NULL)
		{
			break;
		}

	}
	return true;


}

Item* Intersect(const Item* i1, const Item* i2)
{
	Item* i11 = i1;
	Item* i22 = i2;

	Item* l = ListCreateEmpty();


	while (1)
	{
		if (init(ListGetHeadValue(i11), i22))
		{
			l = ListInsertBack(l, ListGetHeadValue(i11));
		}
		i11 = ListGetTail(i11);
		if (i11 == NULL)
		{
			break;
		}
	}

	ListDelete(i11);
	ListDelete(i22);

	return l;



}



Item* Intersectnorep(const Item* i1, const Item* i2)
{
	Item* i11 = i1;
	Item* i22 = i2;

	Item* l = ListCreateEmpty();


	while (1)
	{
	
		if (init(ListGetHeadValue(i11), i22)&&isnotrep(ListGetHeadValue(i11),l))
		{
			l = ListInsertBack(l, ListGetHeadValue(i11));
		}
		i11 = ListGetTail(i11);
		if (i11->next == NULL)
		{
			break;
		}
	}

	ListDelete(i11);
	ListDelete(i22);

	return l;



}



void main(void)
{
	int s1[] = {3, 4, 2, 0, 45, 1, 3};
	int s2[] = { 8, 5, 2, 3, 45,7 };
	int n = 3;

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (size_t j = 0; j < 7; j++)
	{
		i1 = ListInsertBack( i1, &s1[j]);
	}
	for (size_t k = 0; k < 6; k++)
	{
		i2 = ListInsertBack(i2, &s2[k]);
	}

	Item* l1 = Intersectnorep(i1, i2);

	Item* l = diff(i1, i2);
	Item* s = Intersect(i1, i2);



}