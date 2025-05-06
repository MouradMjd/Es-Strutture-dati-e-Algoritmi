#include<stdlib.h>
#include"elemtype.h"
#include"list.h"


Item* Split(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item* i1 = i;
	int size = 0;
	while (!ListIsEmpty(i1))
	{
		size++;
		i1 = ListGetTail(i1);
	}
	int detai = 0;
	if (size % 2 == 0)
	{
		detai = size / 2;
	}
	else
	{
		detai = (size / 2) + 1;
	}
	Item* head2 = i;
	Item* tmp = i;
	Item* prec = i;
	for (int k = 0; k < detai; k++)
	{
		if (k==detai-1)
		{
			prec = tmp;
			head2 = tmp->next;
			prec->next = NULL;
			break;
		}
		tmp = ListGetTail(tmp);
		
	}

	return head2;


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

	Item* l1 = Split(l);
}