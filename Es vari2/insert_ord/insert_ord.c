#include"elemtype.h"
#include"list.h"



Item* insertord(const ElemType* e, Item* i)
{
	Item* tmp = i;
	Item* min = i;
	Item* max = i;
	if (ElemCompare(ListGetHeadValue(tmp), e) > 0)
	{
		i = ListInsertHead(e, i);
		return ListGetHeadValue(i);;
	}

	while (1)
	{
		if (tmp->next == NULL)
		{
			tmp->next = e;
			break;
		}
		if ((ElemCompare(tmp, e) == 0 || ElemCompare(tmp, e) < 0) && (ElemCompare(tmp->next, e) == 0 || ElemCompare(tmp->next, e) > 0))
		{
			min = tmp;
			max = tmp->next;
			tmp->next = e;
			tmp->next->next = max;
			break;
		}
		tmp = ListGetTail(tmp);

	}


	return i;




}



void main(void)
{
	ElemType s[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 8; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	ElemType x = 0;

	insertord(&x, l);
}