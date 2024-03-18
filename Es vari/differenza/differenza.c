#define _CRT_SECURE_NO_WARNINGS
#include"differenza.h"
#include"elemtype.h"
#include"list.h"
#include<stdio.h>

extern Item* Differenza(const Item* i1, const Item* i2)
{
	if (ListIsEmpty(i1) && ListIsEmpty(i2))
	{
		return ListCreateEmpty();
	}
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	if (ListIsEmpty(i1))
	{
		ListDelete(tmp1);
		return tmp2;
	}
	if (ListIsEmpty(i2))
	{
		ListDelete(tmp2);
		return tmp1;
	}
	Item* new_list = ListCreateEmpty();
	int p = 0;

	while (!ListIsEmpty(tmp1)&&!ListIsEmpty(tmp2))
	{

		ElemType* d= ListGetHeadValue(tmp1);
		int s=0;
		sscanf(d, "%d", &s);
		ElemType* v = ListGetHeadValue(tmp2);
		int m = 0;
		sscanf(v, "%d", &m);
		s= s - p;

		if (ElemCompare(&s, &m) > 0)
		{
			int val = ((s)) - (m);
			char l = 0;
			sprintf(&l, "%d", val);
			new_list = ListInsertBack(new_list, &val);
		}
		if (ElemCompare(&s,&m)<0)
		{
			p = 1;
			s = s + 10;
			int val = ((s)) - (m);
			char l = 0;
			sprintf(&l, "%d", val);
			new_list = ListInsertBack(new_list, &val);
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	while (!ListIsEmpty(tmp1))
	{
		ElemType* d = ListGetHeadValue(tmp1);
		int s = 0;
		sscanf(d, "%d", &s);
		(s) = s - p;
		char l = 0;
		sprintf(&l, "%d", s);
		new_list = ListInsertBack(new_list, &l);
		tmp1 = tmp1->next;
	}

	ListDelete(tmp1);
	ListDelete(tmp2);
	

	return new_list;
}

//void main(void)
//{
//	ElemType v[] = {'7','1','0','1'};
//	ElemType c[] = { '3','2','4'};
//	Item* i1 = ListCreateEmpty();
//	Item* i2 = ListCreateEmpty();
//	for (size_t i = 0; i < 4; i++)
//	{
//		i1=ListInsertBack(i1,&v[i]);
//	}
//	for (size_t i = 0; i < 3; i++)
//	{
//		i2=ListInsertBack(i2, &c[i]);
//	}
//	ListWriteStdout(i1);
//	ListWriteStdout(i2);
//	Differenza(i1, i2);
//}