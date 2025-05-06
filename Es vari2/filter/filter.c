#include<stdlib.h>
#include"elemtype.h"
#include"list.h"


Item* Filter(Item* i, ElemType e)
{
	Item* i1 = i;
	Item* next = i;
	Item* prev = i;

	while (!ListIsEmpty(i1))
	{
		if (ElemCompare(ListGetHeadValue(i1), &e) > 0|| ElemCompare(ListGetHeadValue(i1), &e) ==0)
		{
			next = i1->next;
			prev->next = next;
			free(i1);
			i1 = next;
		}
		else
		{
			prev = i1;
			i1 = ListGetTail(i1);
		}
		
		
	}

	return i;



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


	Item* l1 = Filter(l, 5);


}