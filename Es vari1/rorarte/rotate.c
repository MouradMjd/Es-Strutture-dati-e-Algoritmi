#include"elemtype.h"
#include"list.h"


extern Item* Rotate(Item* i, int n)
{
	
	Item* prev = NULL;
	Item* cont = i;
	Item* testa = i;
	Item* head = i;

	for (size_t j = 0; j < n; j++)
	{
		prev = i;
		i = ListGetTail(i);
	}
	cont = i;

	while (!i->next==NULL)
	{
		head = i;
		i = ListGetTail(i);
	}
	head = ListGetTail(i);

	i->next = testa;
	prev->next = NULL;
	return cont;
}
//void main(void)
//{
//	ElemType s[] = { 1,3,4,7,8};
//	ElemType v[] = { 7, 8, 0, 4, 6 };
//	Item* l = ListCreateEmpty();
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		l = ListInsertBack(l, &s[i]);
//	}
//	ListWriteStdout(l);
//	l=Rotate(l, 2);
//}