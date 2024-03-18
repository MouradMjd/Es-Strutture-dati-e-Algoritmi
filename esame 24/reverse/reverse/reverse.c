#include"elemtype.h"
#include"list.h"
#include"reverse.h"

int size(Item* l)
{
	int n = 0;
	while (!ListIsEmpty(l))
	{
		n++;
		l = ListGetTail(l);
	}
	return n;
}


Item* Reverse(Item* list, int right)
{
	if (right <= 1)
	{
		return list ;
	}
	if (right >= size(list))
	{
		Item* prev = list;
		Item* prevprev = list;
		Item* now = list->next;
		Item* nex = list->next->next;
		Item* rad = list;
		int i = 0;
		while (1)
		{
			if (i == 0)
			{
				now->next = prev;
				prev->next = nex;
				prevprev = now;
				prev = now->next;
				now = nex;
				nex = now->next;
				
				
		    }
			else
			{
				now->next = prevprev;
				prev->next = nex;
				prevprev = now;
				now = nex;
				if (now == NULL)
				{
					break;
				}
				nex = now->next;

			}


		

		i++;
		}

		return prevprev;
	}
	else
	{
		Item* prev = list;
		Item* prevprev = list;
		Item* now = list->next;
		Item* nex = list->next->next;
		Item* rad = list;
		int i = 0;
		while (i<right-1)
		{
			if (i == 0)
			{
				now->next = prev;
				prev->next = nex;
				prevprev = now;
				prev = now->next;
				now = nex;
				nex = now->next;


			}
			else
			{
				now->next = prevprev;
				prev->next = nex;
				prevprev = now;
				now = nex;
				if (now == NULL)
				{
					break;
				}
				nex = now->next;

			}


			i++;
		}
		return prevprev;
	}

	Item* prev = list;
	Item* prevprev = list;
	Item* now = list->next->next;
	Item* next = list->next;
	int i = 0;
	while (true)
	{
		if (i == 0)
		{
			now->next = prev;
			prev->next = next;
			prevprev = now;
			now = next;
			next = now->next;
		}
		else
		{
			now->next = prevprev;
			prev->next = next;
			now = next;
			if (now == NULL)
			{

			}
			next = now->next;



		}


		i++;
	}



}






