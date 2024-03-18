#include"doublelist.h"
#include"elemtype.h"
#include"sum_dlist.h"

 Item* DListSum(const Item* i1, const Item* i2)
{
	 if (DListIsEmpty(i2) && DListIsEmpty(i1))
	 {
		 return DListCreateEmpty();
	 }
	 if (DListIsEmpty(i1))
	 {
		 return i2;
	 }
	 if (DListIsEmpty(i2))
	 {
		 return i1;
	 }

	 Item* new_list = DListCreateEmpty();

	 while ((i1->next)!=NULL)
	 {
		 i1 = DListGetTail(i1);
	 }	 

	 while ((i2->next) != NULL)
	 {
		 i2 = DListGetTail(i2);
	 }
	  
	 int riporto = 0;
	 while (!DListIsEmpty(i1)&&!DListIsEmpty(i2))
	 {
		 int sum = *DListGetHeadValue(i1) + *DListGetHeadValue(i2) + riporto;
		 int val = sum % 10;
		 riporto = sum /10;
		 new_list = DListInsertHead(&val,new_list);
		 i1 = i1->prev;
		 i2 = i2->prev;
	 }

	 if (!DListIsEmpty(i1))
	 {
		 int sum = *DListGetHeadValue(i1) + riporto;
		 int val = sum % 10;
		 riporto = sum / 10;
		 new_list = DListInsertHead(&val, new_list);
		 i1 = i1->prev;
	 }

	 if (!DListIsEmpty(i2))
	 {
		 int sum = *DListGetHeadValue(i2) + riporto;
		 int val = sum % 10;
		 riporto = sum / 10;
		 new_list = DListInsertHead(&val, new_list);
		 i2 = i2->prev;
	 }

	 if (riporto != 0)
	 {
		 int in = riporto % 10;
		 riporto = riporto / 10;
		 new_list = DListInsertHead( &in,new_list);
	 }

	 return new_list;


}

 void main(void)
 {
	 ElemType s[] = { 9,5,4};
	 ElemType v[] = { 6,9 };
	 Item* l = DListCreateEmpty();
	 Item* r = DListCreateEmpty();

	 for (size_t i = 0; i < 3; i++)
	 {
		 l = DListInsertBack(l, &s[i]);
	 }
	 for (size_t i = 0; i < 2; i++)
	 {
		 r = DListInsertBack(r, &v[i]);
	 }

	 DListSum(l, r);
 }