#include"elemtype.h"
#include"list.h"
#include"next_greater.h"
#include<stdint.h>
#include<stdlib.h>
#include <limits.h>


ElemType* NextGreater(const Item* list, size_t* answer_size)
{
	if (ListIsEmpty(list))
	{
		return NULL;
	}
	int i = 0;
	int j = 0;
	ElemType* answer = malloc( j* sizeof(ElemType));
	const Item* tmp1 = list;
	const Item* tmp2 = list->next;
	int isdone = 0;
	while (!ListIsEmpty(tmp1))
	{
		while (!ListIsEmpty(tmp2))
		{
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0)
			{
				isdone = 1;
				j++;
				answer = realloc(answer, j * sizeof(ElemType));
				answer[i] = *ListGetHeadValue(tmp2);
				i++;
				break;
			}
			tmp2 = ListGetTail(tmp2);
		}
		if (isdone == 0)
		{
			j++;
			answer = realloc(answer, j * sizeof(ElemType));
			answer[i] = INT_MIN;
			i++;
		}
		tmp1 = ListGetTail(tmp1);
		tmp2 = tmp1;
		isdone = 0;
	}
	*answer_size = j;
	return answer;

}


void main(void)
{
	int a[] = { 2, 3, 1, 4, 7, 2 };
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < 6; i++)
	{
		l = ListInsertBack(l, &a[i]);
	}
	size_t an;
	ElemType*k=NextGreater(l, &an);
	ListWriteStdout(l);

}
