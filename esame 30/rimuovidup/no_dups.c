#include"elemtype.h"
#include"list.h"
#include"no_dups.h"


bool notinit(Item *i,ElemType *e)
{
	while (!ListIsEmpty(i))
	{
		if (ElemCompare(i, e) == 0)
		{
			return false;
		}
		i = ListGetTail(i);
	}
	return true;

}


 Item* RemoveDuplicates(const Item* i)
{
	 if (ListIsEmpty(i))
	 {
		 return ListCreateEmpty();
	 }
	 Item* newlist = ListCreateEmpty();
	 newlist = ListInsertBack(newlist, i);
	 i = ListGetTail(i);

	 while (!ListIsEmpty(i))
	 {
		 if (notinit(newlist, i))
		 {
		 newlist = ListInsertBack(newlist, i);
		 }
		 i = ListGetTail(i);
	 }
	 return newlist;
}




