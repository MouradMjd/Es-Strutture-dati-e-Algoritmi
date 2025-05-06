#include<stdlib.h>
#include"elemtype.h"
#include"list.h"





bool Anyloop(Item* l)
{
	if (ListIsEmpty(l))
	{
		return true;
	}
	Item* tmp = l;
	Item* head = ListGetHeadValue(l);
	int i = 0;
	while (!ListIsEmpty(tmp))
	{
		Item* s = ListGetHeadValue(tmp);
		if (( s==head) && i != 0)
		{
			return false;
		}
		tmp = ListGetTail(tmp);
		i++;

	}

	return true;

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
	Item* i = ListGetHeadValue(l);
	Item* i1 = l;
	while (1)
	{
		i1 = i1->next;
		if (i1->next == NULL)
		{
			i1->next = i;
			break;
		}

	}

	
	bool e = Anyloop(l);
}