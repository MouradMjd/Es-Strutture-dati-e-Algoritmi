#include<stdlib.h>
#include"v_l.h"
#include"elemtype.h"
#include"list.h"


Item* Vector2list(const ElemType* v, size_t v_size, enum ConversioneType c)
{
	if (v == NULL)
	{
		return ListCreateEmpty();
	}
	Item* l = ListCreateEmpty();
	if (c == kinOrder)
	{
		for (size_t i = 0; i < v_size; i++)
		{
			l = ListInsertBack(l, &v[i]);
		}
	}

	if (c == kReverse)
	{
		for (size_t i =0; i <v_size; i++)
		{
			l = ListInsertHead(&v[i],l);
		}
	}



	return l;

};

ElemType* List2Vector(const Item* i, size_t v_size, enum ConversioneType c)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item* i1 = i;
	ElemType* v = malloc(v_size * sizeof(int));
	if (c == kinOrder)
	{
		for ( int j = 0; j<v_size;  j++)
		{
			v[j] = *(ListGetHeadValue(i1));
			i1 = ListGetTail(i1);
		}
	}
	if (c == kReverse)
	{
		Item* i2 = i;
		Item* revl = ListCreateEmpty();
		while (!ListIsEmpty(i2))
		{
			revl = ListInsertHead(ListGetHeadValue(i2), revl);
			i2 = ListGetTail(i2);
		}
		for (int k = 0; k<v_size; k++)
		{
			v[k] = *(ListGetHeadValue(revl));
			revl = ListGetTail(revl);
		}
	}
	return v;

}



void main(void)
{
	ElemType s[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 8; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}

	// *r = List2Vector(l, 8, kReverse);
	Item* l1 = Vector2list(v,5 , kReverse);


	
}