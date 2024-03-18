#include"cc.h"
#include"elemtype.h"
#include"list.h"



bool isin(ElemType* e, ElemType *v,size_t n)
{
	for (size_t i = 0; i < n ; i++)
	{
		if (ElemCompare(e,&v[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size)
{
	int sol = 0;
	int in = 0;
	Item* tmp = i;
	while (!ListIsEmpty(tmp))
	{

		while (isin(ListGetHeadValue(tmp), v,v_size) == true)
		{
			tmp = ListGetTail(tmp);
			in = 1;
			if (tmp == NULL)
			{
				break;
			}
		}
		if (in == 1)
		{
			sol++;
			in = 0;
			continue;
		}
		else
		{
			tmp = ListGetTail(tmp);
		}
		
	
	}
	return sol;


}


//void main(void)
//{
//	ElemType s[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
//	ElemType v[] = { 7, 8, 0, 4, 6 };
//	Item* l=ListCreateEmpty();
//
//	for (size_t i = 0; i < 8; i++)
//	{
//		l = ListInsertBack(l, &s[i]);
//	}
//
//	ComponentiConnesse(l, v, 5);
//}