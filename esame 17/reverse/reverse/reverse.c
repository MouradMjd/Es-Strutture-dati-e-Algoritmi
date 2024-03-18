#include"elemtype.h"
#include"list.h"

Item* Reverse(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	int w = 0;
	Item* rad = i;
	Item* prev = i;
	Item* now = i->next;
	Item* next = i->next->next;
	Item* prevprev = i;
	while (true)
	{
		if (w == 0)
		{
			prevprev = prev;
			prev->next = next;
			now->next = prev;
			prev = now;
			now = next;
			w = 1;
		}
		prevprev->next = now->next;
		now->next = prev;
		prev = now;
		if (prevprev->next == NULL)
		{
			break;
		}
		now = prevprev->next;

	}



	return now;



}



