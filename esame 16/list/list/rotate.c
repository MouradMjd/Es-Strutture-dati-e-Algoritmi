#include"elemtype.h"
#include"list.h"


Item* Rotate(Item* i, int n)
{
	Item* rad = i;
	Item* i1 = i;
	Item* last = i;
	Item* nextlast = i;
	while (n!=1)
	{
		i1 = ListGetTail(i1);
		n--;
	}
	last = i1;
	nextlast = last->next;
	while (true)
	{
		if (i1->next == NULL)
		{
			break;
		}
		i1 = ListGetTail(i1);
	}
	i1->next = rad;
	last->next = NULL;


	return nextlast;
}
