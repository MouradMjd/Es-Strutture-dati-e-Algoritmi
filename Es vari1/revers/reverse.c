#include"list.h"
#include"elemtype.h"

Item* Reverse(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item* prec = NULL;
	Item* next = i->next;
	Item* curr = i;
	Item* head;
	while (1)
	{
		if (prec == NULL)
		{
			prec = ListGetHeadValue(curr);
			curr= ListGetTail(curr);
			next = curr->next;
			prec->next = NULL;
			continue;
		}
		curr->next = prec;
		prec = curr;
		curr = next;
		if (curr == NULL)
		{
			head = prec;
			break;
		}
		next = curr->next;
	}
		i = head;
		ListWriteStdout(i);
		return i;

}

void main(void)
{
	ElemType s[] = {1,2,3,4,5,6,7,8,9};
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 9; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}
	Reverse(l);
	
}