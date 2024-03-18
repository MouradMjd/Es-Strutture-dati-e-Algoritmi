#include"elemtype.h"
#include"list.h"
#include<math.h>

extern Item* CreaDaInterni(const Item* i, double r)
{
	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}
	Item * newlist = ListCreateEmpty();

	while (!ListIsEmpty(i))
	{
		int x = ListGetHeadValue(i)->x;
		int y = ListGetHeadValue(i)->y;

		int s = ((x) * (x)) + ((y) * (y));
		int dis =sqrt(s);
		if (dis < r)
		{
			newlist = ListInsertBack(newlist, ListGetHeadValue(i));
		}
		i=ListGetTail(i);
	}

	return newlist;
}

//void main(void)
//{
//	Item* t = ListCreateEmpty();
//	ElemType s;
//	s.x = 4;
//	s.y = 4;
//	t = ListInsertBack(t, &s);
//	CreaDaInterni(t, 20);
//	
//}