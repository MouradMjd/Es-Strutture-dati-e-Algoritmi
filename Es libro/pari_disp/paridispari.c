#include"elemtype.h"
#include"list.h"

Item* PariDispari(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}

	Item* tmp1 = i;
	Item* par= NULL;
	Item* disp=NULL;
	Item* head_p = NULL;
	Item* head_d = NULL;
	while (!ListIsEmpty(tmp1))
	{
		if ((*ListGetHeadValue(tmp1) % 2) == 0)
		{
			if (par == NULL)
			{
				par = ListGetHeadValue(tmp1);
				head_p = ListGetHeadValue(tmp1);
			}
			else
			{
				par->next = ListGetHeadValue(tmp1);
				par = ListGetTail(par);
			}
			tmp1 = ListGetTail(tmp1);
			
	
		}
		else
		{
			if (disp == NULL)
			{
				disp = ListGetHeadValue(tmp1);
				head_d = ListGetHeadValue(tmp1);
			}
			else
			{
				disp->next = ListGetHeadValue(tmp1);
				disp = ListGetTail(disp);
			}
		
			tmp1 = ListGetTail(tmp1);
		}

	}
	disp->next = NULL;
	par->next = head_d;
	i=head_p;
	return i;
	
}


//
//void main(void)
//{
//	int a[] = { 1,2,3,4,6,5,4,9,3,3};
//	Item* l = ListCreateEmpty();
//	for (size_t i = 0; i < 10; i++)
//	{
//		l = ListInsertBack(l, &a[i]);
//	}
//	l=PariDispari(l);
//	ListWriteStdout(l);
//
//}

