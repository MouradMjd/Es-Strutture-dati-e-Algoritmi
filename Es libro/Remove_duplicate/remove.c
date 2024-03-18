#include"elemtype.h"
#include"list.h"
#include"remove.h"


extern Item* RemoveDuplicates(Item* i)
{
	if (i == NULL)
	{
		return NULL;
	}
	Item *prev = NULL;
	Item* r = i;
	Item* curr = i;

	while (curr!=NULL&&curr->next!=NULL)
	{
		
			if (ElemCompare(curr->next,curr) == 0)
			{
				while (true)
				{
					
					Item* prev2=prev;
					Item* curr1 = curr;
					if (ElemCompare(curr1, curr->next)!=0)
					{
						if (prev == NULL)
						{
							r = curr->next;
							free(curr);
							i = r;
							curr = i;
							break;
						}
						else
						{
							prev->next = curr->next;
							free(curr);
							curr = prev;
							i = curr;
							break;
						}
					
					
					}
					curr = ListGetTail(curr);
				
				}
			}
			else
			{
				prev = curr;
				curr = ListGetTail(curr);
			}
		


	}
	return i;


}

Item* listcreatefromvector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list =ListInsertBack(list,&v[i]);
		
	}
	return list;
}
int main(void) {
	int v[] = { 1,1,1,2,2,6 };
	size_t v_size = sizeof(v) / sizeof(int);
	Item* list = listcreatefromvector(v, v_size);


	list = RemoveDuplicates(list);
	ListWriteStdout(list);
}