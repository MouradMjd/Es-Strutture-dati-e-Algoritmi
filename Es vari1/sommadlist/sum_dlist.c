#include"sum_dlist.h"
#include"doublelist.h"
#include"elemtype.h"




extern Item* DListSum(const Item* i1, const Item* i2)
{
	
	if (i1 == NULL && i2 == NULL)
	{
		return DListCreateEmpty();
	}
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;
	if (tmp1 == NULL && tmp2 != NULL)
	{
		Item* s = DListCreateEmpty();
			while (!DListIsEmpty(tmp2))
			{
				s = DListInsertBack(s, DListGetHeadValue(tmp2));
				tmp2 = tmp2->next;
			}
		return s ;
	}
	if (tmp1 != NULL && tmp2 == NULL)
	{
		Item* s = DListCreateEmpty();
		while (!DListIsEmpty(tmp1))
		{
			s = DListInsertBack(s, DListGetHeadValue(tmp1));
			tmp1 = tmp1->next;
		}
		return s;
	}

	while (tmp1->next!=NULL)
	{
		tmp1 = tmp1->next;
	}
	while (tmp2->next!=NULL)
	{
		tmp2 = tmp2->next;
	}

	Item* new = DListCreateEmpty();
	int r = 0;

	while (!DListIsEmpty(tmp1)&&!DListIsEmpty(tmp2))
	{
		
		int som = *DListGetHeadValue(tmp1) + *DListGetHeadValue(tmp2) + ( r);
		r = (som / 10);
		int n = som % 10;
		new = DListInsertHead(&n, new);
		tmp1 = tmp1->prev;
		tmp2 = tmp2->prev;
	}
	while(!DListIsEmpty(tmp1))
	{
		int n = *DListGetHeadValue(tmp1) + r;
		int val = n % 10;
		r = (n / 10);
		new = DListInsertHead(&val, new);
		tmp1 = tmp1->prev;
	}
	while (r != 0)
	{
		int n = r%10;
		r = r / 10;
		new = DListInsertHead(&n, new);	
	}

	return new;
}

void main(void)
{
	ElemType s[] = { 9,5,4 ,6,7};
	ElemType v[] = { 6,9,8,9 };
	Item* l = DListCreateEmpty();
	Item* r = DListCreateEmpty();

	for (size_t i = 0; i < 5; i++)
	{
		l = DListInsertBack(l, &s[i]);
	}

	DListSum(r, l);
	return;
}