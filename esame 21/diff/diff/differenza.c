#define  _CRT_SECURE_NO_WARNINGS
#include"differenza.h"
#include"elemtype.h"
#include"list.h"
#include<stdlib.h>



extern Item* Differenza(const Item* i1, const Item* i2)
{
	if (ListIsEmpty(i1))
	{
		return i2;
	}
	if (ListIsEmpty(i2))
	{
		return i1;
	}
	Item* i11 = i1;
	Item* i22 = i2;
	Item* newlist = ListCreateEmpty();
	int p = 0;
	char* w;
	while (!(ListIsEmpty(i11)||ListIsEmpty(i22)))
	{
		int s = strtol(i11, &w, 0);
		int m = strtol(i22, &w, 0);
		s = s - p;
		p = 0;
		if (ElemCompare(&s, &m) < 0)
		{
			p = 1;
			s = s + 10;
		}
		int r = s - m;
		char c[3];
		sprintf(&c,"%d", r);
		newlist = ListInsertBack(newlist,&c);
		i11 = ListGetTail(i11);
		i22 = ListGetTail(i22);
	}

	if (ListIsEmpty(i22) && !ListIsEmpty(i11))
	{
		int s = strtol(i11, &w, 0);
		s = s - p;
		char c1[3];
		sprintf(&c1, "%d", s);
		newlist = ListInsertBack(newlist, &c1);
		i11 = ListGetTail(i11);
	}

	return newlist;
}



void main(void)
{
	ElemType s[] = { '7','1','0','1'};
	ElemType v[] = { '3','2','4'};
	Item* l = ListCreateEmpty();
	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		l1 = ListInsertBack(l1, &v[i]);
	}

	Item* l3 = Differenza(l, l1);
}


