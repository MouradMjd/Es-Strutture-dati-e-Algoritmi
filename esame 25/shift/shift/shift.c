#include"elemtype.h"
#include"list.h"
#include"shift.h"

size_t size(Item* i)
{
	int s = 0;
	while (!ListIsEmpty(i))
	{
		s++;
		i = ListGetTail(i);
	}

	return s;

}
Item* ShiftN(Item* list, size_t n)
{
	if (n >= size(list))
	{
		Item* rad = list;
		Item* last = list;
		while (!ListIsEmpty(ListGetTail(last)))
		{
			last = ListGetTail(last);
		}
		last->next = rad;
		return rad;
	}
	else
	{
		Item *now = list; 
		Item* nownex = list->next;
		Item* nownexnex = list->next->next;
		Item* prev = list;
		Item* rad = list;
		for (size_t i = 0; i < n; i++)
		{
			

			if (i == 0)
			{
				nownex->next = now;
				now->next = nownexnex;
				rad = nownex;
			}
			else
			{
				nownex->next = now;
				now->next = nownexnex;
				prev->next = nownex;

			}
			if (i == n - 1)
			{
				break;
			}
			prev = nownex;
			nownex = nownexnex;
			nownexnex = nownexnex->next;
		}
		return rad;
	}
}


void main(void)
{
	ElemType s[] = { 0, 1, 2,5 };
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}

	l = ShiftN(l, 6);
}

