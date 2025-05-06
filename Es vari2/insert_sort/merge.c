#include"elemtype.h"
#include"list.h"
#include"merge.h"
#include<stdlib.h>


Item* copy(Item *tmp11)
{
	Item* tmp1 = ListCreateEmpty();
	while (!ListIsEmpty(tmp11))
	{
		tmp1 = ListInsertBack(tmp1, ListGetHeadValue(tmp11));
		tmp11 = tmp11->next;
	}
	return tmp1;
}

Item* ordermerge(Item* i1, Item* i2, enum MergeType m)
{
	
	
	if (m == KNoCopy)
	{
		int n = 0;
		Item* tmp1 = i1;
		Item* tmp2 = i2;
		Item* now = i1;
		Item* now2 = i1;
		while (!ListIsEmpty(tmp2))
		{
			tmp1 = ListGetHeadValue(i1);
			n = 0;
				while (!ListIsEmpty(tmp1))
				{
					if ((ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2))==0 ||
						ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) > 0)&&n==0)
					{
						now = tmp1->next;
						now2 = tmp2->next;
						tmp1->next = tmp2;
						tmp1->next->next = now;
						tmp2 = now2;
						break;
				    }
					if ((ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0 &&
						ElemCompare(ListGetHeadValue(tmp1->next), ListGetHeadValue(tmp2)) > 0))
					{
						now = tmp1->next;
						now2 = tmp2->next;
						tmp1->next = tmp2;
						tmp1->next->next = now;
						tmp2 = now2;
						break;
					}
					tmp1 = ListGetTail(tmp1);
					n++;
				}
				tmp2 = tmp2;

		}
		return ListGetHeadValue(i1);


	}

	if (m == Kcopy)
	{
		int n = 0;
		Item* tmp1= copy(i1);
		Item* tmp2 = copy(i2);
		Item* now = tmp1;
		Item* now2 = tmp2;


			while (!ListIsEmpty(tmp2))
			{
				tmp1 = ListGetHeadValue(i1);
				n = 0;
				while (!ListIsEmpty(tmp1))
				{
					if ((ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0 ||
						ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) > 0) && n == 0)
					{
						now = tmp1->next;
						now2 = tmp2->next;
						tmp1->next = tmp2;
						tmp1->next->next = now;
						tmp2 = now2;
						break;
					}
					if ((ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0 &&
						ElemCompare(ListGetHeadValue(tmp1->next), ListGetHeadValue(tmp2)) > 0))
					{
						now = tmp1->next;
						now2 = tmp2->next;
						tmp1->next = tmp2;
						tmp1->next->next = now;
						tmp2 = now2;
						break;
					}
					tmp1 = ListGetTail(tmp1);
					n++;
				}
				tmp2 = tmp2;

			}

		
		return ListGetHeadValue(tmp1);
	}



}


void main(void)
{
	ElemType s[] = { 1,2,7,8 };
	ElemType v[] = {1,3,4 };
	Item* l = ListCreateEmpty();
	Item* l1 = ListCreateEmpty();
	for (size_t i = 0; i < 4; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		l1 = ListInsertBack(l1, &v[i]);
	}

	Item* l3 = ordermerge(l, l1, Kcopy);
}