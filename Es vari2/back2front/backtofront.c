#include"elemtype.h"
#include"list.h"




void B2F(Item **i)
{
	Item *i1 = *i;
	Item* tmp = *i;
	Item* tmp2 = *i;
	Item *head = i1;
	int size = 0;

	while (!ListIsEmpty(i1))
	{
		size++;
		i1 = ListGetTail(i1);
	}

	for (size_t i = 0; i < size-2; i++)
	{
		tmp = ListGetTail(tmp);
	}
	for (size_t i = 0; i < size-1; i++)
	{
		tmp2 = ListGetTail(tmp2);
	}

	tmp->next = NULL;
	tmp2->next = head;
	*i = tmp2;

}

void main(void)
{
	ElemType s[] = { 1,2,3,5 };
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}

	B2F(&l);
}
