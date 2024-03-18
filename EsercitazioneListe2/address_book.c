#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"elemtype.h"
#include"list.h"



Item* Append(const Item* i1, const Item* i2)
{
	Item* mlis = ListCreateEmpty();
	Item *i11 = i1;
	Item* i22=i2;
	while (!ListIsEmpty(i11))
	{
		mlis = ListInsertBack(mlis, ListGetHeadValue(i11));
		i11 = ListGetTail(i11);
	}
	while (!ListIsEmpty(i22))
	{
		mlis = ListInsertBack(mlis, ListGetHeadValue(i22));
		i22 = ListGetTail(i22);
	}

	free(i11);
	free(i22);
	return mlis;


}

Item* AppendMod(Item* i1, Item* i2)
{
	Item* Head = ListGetHeadValue(i1);
	if (i1 == NULL)
	{
		return i2;
	}
	if (i2 == NULL)
	{
		return i1;
	}
	while (!(i1->next==NULL))
	{
		i1 = ListGetTail(i1);
	}
	i1->next = ListGetHeadValue(i2);
	return Head;
}



Item* Reverse(const Item* i)
{
	Item* i1 = i;
	Item* newlist = ListCreateEmpty();

	while (!ListIsEmpty(i1))
	{
		newlist = ListInsertHead(ListGetHeadValue(i1), newlist);
		newlist = ListGetTail(i1);
	}

	return newlist;
}

/*Item* Filtra(const Item* i, const char* city)
{
	Item* i1 = i;
	Item* newlist = ListCreateEmpty();

	while (!ListIsEmpty(i1))
	{
		if (strcmp(ListGetHeadValue(i1)->city,city)==0)
		{
			newlist = ListInsertBack(newlist, ListGetHeadValue(i1));
		}
		i1 = ListGetTail(i1);
	}

	return newlist;
}*/

/*ElemType* minn(Item* list)
{
	Item* best = ListGetHeadValue(list);
	Item* tmp = list;
	while (!ListIsEmpty(tmp))
	{
	
			if (ElemCompare(ListGetHeadValue(best), ListGetHeadValue(tmp)) > 0)
			{
				best = tmp;
			}
		
		tmp = ListGetTail(tmp);
	}
	return  ListGetHeadValue(best);
}

extern Item* Sort(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item* i1 = i;
	ElemType* s=ListGetHeadValue(i);
	while (!ListIsEmpty(i1))
	{
		s = minn(i1);
		ElemSwap(ListGetHeadValue(i1), s);
		i1= ListGetTail(i1);
	}
	
	return i;


}*/


/*extern Item* Delete(Item* i, const char* name)
{
	Item* i1 = i;

	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item * prec = i;
	while (!ListIsEmpty(i1))
	{
		if (strcmp(name, ListGetHeadValue(i1)->name) == 0)
		{
			prec->next = i1->next;
			ElemDelete(ListGetHeadValue(i1));
			free(i1);
			break;
		}
		prec = i1;
		i1 = ListGetTail(i1);
	}

	return i;

}*/





/*extern const ElemType* Find(const Item* i, const char* name)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}

	while (!ListIsEmpty(i))
	{
		if (strcmp(name,ListGetHeadValue(i)->name) == 0)
		{
			return ListGetHeadValue(i);
		}
		i = ListGetTail(i);
	}

	return NULL;

}*/



 