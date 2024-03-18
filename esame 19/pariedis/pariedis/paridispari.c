#include"elemtype.h"
#include"list.h"

Item * nextd(Item* i)
{
	
	while (!ListIsEmpty(i))
	{
		if (i->value % 2 == 0)
		{
			return i;
		}
		i = ListGetTail(i);
	}


	return NULL;
}
Item* prevnextd(Item* i)
{

	while (!ListIsEmpty(i->next))
	{
		if (i->next->value % 2 == 0)
		{
			return i;
		}
		i = ListGetTail(i);
	}


	return NULL;
}

Item* PariDispari(Item* i)
{
	Item *i2 = i;
	Item* pprim = NULL;
	Item* ini = i;
	int w = 0;
	while (i2->value%2!=0)
	{
		if (w == 0)
		{
			pprim = i2;
			w = 1;
		}
		if (i2->next->value % 2 == 0)
		{
			ini = ListGetTail(i2);
			i2->next = NULL;
			break;
		}
		i2 = ListGetTail(i2);
	}
	if (ini->value % 2 == 0)
	{
		int e = 0;
		Item *now = ini;
		Item* l = ini;
		Item* next = ini->next;
		Item* disp = NULL;
		Item* nextdis = NULL;
		Item* prev = NULL;
		Item* prevprev = NULL;
		int w1 = 0;
		while (1)
		{
			if (w1 == 0)
			{
				disp = nextd(now);
				prev = prevnextd(now);
				if (disp == NULL)
				{
					break;
				}
				nextdis = disp->next;
				now->next = disp;
				disp->next = prev;
				next->next = nextdis;
				next = next->next;
				now = ListGetTail(now);
				prevprev = disp->next;
				w1 = 1;
			}
			disp = nextd(now);
			prev = prevnextd(now);
			if (disp == NULL)
			{
				break;
			}
			nextdis = disp->next;
			now->next = disp;
			disp->next = prevprev;
			prev->next = nextdis;
			next->next = nextdis;
			next = next->next;
			now = ListGetTail(now);
		}
		if (pprim != NULL)
		{
			nextdis->next = pprim;
		}

	}

	return ini;
}

void main(void)
{
	int v[] = { 1,3,4,7,8,0,10,2,5,9,14,200,78 };
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < 13; i++)
	{
		list = ListInsertBack(list, &v[i]);
	}
	PariDispari(list);


}

