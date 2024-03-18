#include"elemtype.h"
#include"list.h"
#include"shift.h"

Item* ShiftN(Item* list, size_t n)
{
	if (ListIsEmpty(list)||n==0)
	{
		return list;
	}
	int lenlist = 0;
	Item* s = list;
	while(!ListIsEmpty(s))
	{
		lenlist++;
		s = s->next;
	}
	if (lenlist == 1)
	{
		return list;
	}
	if (n >= lenlist)
	{
		n = n - (lenlist - 1);
	}

	Item* prev = NULL;
	Item* prevprev = NULL;
	Item* next = list->next;
	Item* curr = list;
	Item* head=0;
	for (size_t i = 0; i <n; i++)
	{
		if (prev == NULL)
		{
			prev = list;
			curr = next;
			next = curr->next;
			head = curr;
		}
		curr->next= prev;
		prev->next = next;
		if (prevprev == NULL)
		{
			prevprev = curr;
		}
		else
		{
			prevprev->next = curr;
			prevprev = prevprev->next;
		}
		
		curr = next;
		if (next->next != NULL)
		{
			next = next->next;
		}
		
	}
	ListDelete(s);
	return head;

}

void main(void)
{
	ElemType s[] = { 0, 1,2,3, 4, 5, 6, 7, 8 };
	ElemType v[] = { 0, 1, 2, 3 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 9; i++)
	{
		l = ListInsertBack(l, &s[i]);
	} 
	ShiftN(l, 2);
}