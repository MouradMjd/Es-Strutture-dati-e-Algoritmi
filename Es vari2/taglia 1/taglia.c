#include<stdlib.h>
#include"elemtype.h"
#include"list.h"


Item* Taglia(Item* i, int n)
{
	if (n == 0)
	{
		ListDelete(i);
		return ListCreateEmpty();
	}
	if (n < 0)
	{
		return i;
	}
	Item* i1 = i;

	int x = n - 1;
	for (int k = 0; k < n-1; k++)
	{
		i1 = ListGetTail(i1);
	}

	i1->next = NULL;
	i1 = ListGetTail(i1);

	    
	ListDelete(i1);
	

	return i;


}


void main(void)
{
	ElemType s[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	ElemType v[] = { 0, 1, 2, 3 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &v[i]);
	}

	l = Taglia(l, 2);
}