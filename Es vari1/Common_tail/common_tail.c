#include"elemtype.h"
#include"list.h"

int lung(Item* l)
{
	int i = 0;
	while (!ListIsEmpty(l))
	{
		i++;
		l = l->next;
	}
	return i;
}
int id(Item* tmp1, Item* tmp2)
{
	int b = 0;
	while (!ListIsEmpty(tmp1) && !ListIsEmpty(tmp2))
	{
		if (ElemCompare(tmp1, tmp2) == 0)
		{
				b = 1;
		}
		else
		{
			b = 0;
			break;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return b;
}
extern const Item* CommonTail(const Item* i1, const Item* i2)
{
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	Item* b = NULL;
	if (id(tmp1, tmp2) == 1)
	{
		return b;
	}
	int l1 = lung(tmp1);
	int l2 = lung(tmp2);
	int r = 0;
	if(l1>l2)
	{
		r = l1 - l2;
		for (size_t i = 0; i < r; i++)
		{
			tmp1 = tmp1->next;
		}
	}
	else if (l2>l1)
	{
		r = l2 - l1;
		for (size_t i = 0; i < r; i++)
		{
			tmp2 = tmp2->next;
		}
	}
	
	while (!ListIsEmpty(tmp1)&& !ListIsEmpty(tmp2))
	{
		if (ElemCompare(tmp1, tmp2) == 0)
		{
			if (b == NULL)
			{
				b = tmp1;
			}
			
		}
		else
		{
			b = NULL;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return b;
}

//void main(void)
//{
//	int v[] = { 7,2,5,4};
//	int s[] = { 2,5,4};
//	Item* g = ListCreateEmpty();
//	Item* d = ListCreateEmpty();
//	for (size_t i = 0; i < 4; i++)
//	{
//		g = ListInsertBack(g,&v[i]);
//	}
//	for (size_t i = 0; i < 3; i++)
//	{
//		d = ListInsertBack(d, &s[i]);
//	}
//	CommonTail(g, d);
//}