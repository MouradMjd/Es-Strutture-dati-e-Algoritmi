#include"cc.h"
#include"elemtype.h"
#include"list.h"


bool init(ElemType *e,int *v,size_t s)
{
	for (size_t i = 0; i < s; i++)
	{
		if (ElemCompare(e, &v[i])==0)
		{
			return true;
		}

	}

	return false;

}

extern int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size)
{
	if (ListIsEmpty(i) || v == NULL)
	{
		return 0;
	}
	int n = 0;
	int c = 0;
	Item* i1 = i;
	while (!ListIsEmpty(i1))
	{
		if (init(i1, v, v_size)&&c==0)
		{
			n++;
			c = 1;
			i1 = ListGetTail(i1);
			continue;
		}
		if (init(i1, v, v_size))
		{
			i1 = ListGetTail(i1);
			continue;
		}
		if (!init(i1, v, v_size))
		{
			c = 0;
			i1 = ListGetTail(i1);
	    }
	}


	return n;



}



void main(void)
{
	ElemType s[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	ElemType v[] = { 7, 8, 0, 4, 6 };
	Item* l = ListCreateEmpty();

	for (size_t i = 0; i < 8; i++)
	{
		l = ListInsertBack(l, &s[i]);
	}

	ComponentiConnesse(l, v, 5);
}

