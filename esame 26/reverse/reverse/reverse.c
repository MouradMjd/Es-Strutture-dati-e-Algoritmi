#include"elemtype.h"
#include"list.h"
#include"reverse.h"
#include<stdlib.h>
#include<string.h>

int size(Item* l)
{
	int s = 0;
	while (!ListIsEmpty(l))
	{
		s++;
		l = ListGetTail(l);
	}
	return s;
}

Item* Reverse(Item* list, int left)
{
	if (left >= (size(list) - 1))
	{
		return list;
	}
	if (left <= 0)
	{
		Item* prev = list;
		Item* now = list;
		Item* succ = list;
		Item* rad = list;
		int i = 0;
		while(!ListIsEmpty(now))
		{
			if (i == 0)
			{
				rad = now;
				now = ListGetTail(now);
				succ = now->next;
			}
			else
			{
				now->next = rad;
				prev->next = succ;
				if (prev->next == NULL)
				{
					break;
				}
				rad = now;
				now = prev->next;
				succ = now->next;
			}
			i++;
		}
		return now;
	} 
	else
	{
		Item *rad1 = list;
		Item* i1 = list;
		Item* i2 = list;
		for (size_t i = 0; i < left; i++)
		{
			i1 = ListGetTail(i1);
		}
		for (size_t i = 0; i < left - 1; i++)
		{
			i2 = ListGetTail(i2);
		}

		Item* prev = i1;
		Item* now = i1;
		Item* succ = i1;
		Item* rad = i1;
		int i = 0;
		while (!ListIsEmpty(now))
		{
			if (i == 0)
			{
				rad = now;
				now = ListGetTail(now);
				succ = now->next;
			}
			else
			{
				now->next = rad;
				prev->next = succ;
				if (prev->next == NULL)
				{
					break;
				}
				rad = now;
				now = prev->next;
				succ = now->next;
			}
			i++;
		}
		i2->next = now;
		return rad1;
	}
	
	
}





