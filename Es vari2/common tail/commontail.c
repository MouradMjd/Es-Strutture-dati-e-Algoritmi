#include<stdlib.h>
#include"elemtype.h"
#include"list.h"



Item* ctail(const Item *i1,const Item *i2)
{
	if (ListIsEmpty(i1) || ListIsEmpty(i2))
	{
		return ListCreateEmpty();
	}
	Item *i11 = i1;
	Item* i22 = i2;
	Item* head = i1;
	int tai = 0;
	while (!(ListIsEmpty(i11) || ListIsEmpty(i22)))
	{
		if (ElemCompare(i11, i22) == 0&&tai==0)
		{
			head = ListGetHeadValue(i11);
			tai = 1;
		}
		if (ElemCompare(i11, i22) != 0 && tai == 1)
		{
			tai = 0;
			head = ListCreateEmpty();
		}
		i11 = ListGetTail(i11);
		i22=ListGetTail(i22);
	}

	return head;

}

void main(void)
{
	ElemType s[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	ElemType v[] = {1,2,2,4,5,6,8,3};
	Item* l = ListCreateEmpty();
	Item* d = ListCreateEmpty();
	for (size_t i = 0; i < 8; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 8; i++)
	{
		d = ListInsertBack(d, &v[i]);
	}

	Item* l1 = ctail(l, d);
}