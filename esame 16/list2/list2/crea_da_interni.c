#include"elemtype.h"
#include"list.h"
#include<math.h>

Item* CreaDaInterni(const Item* i, double r)
{
	Item* nl = ListCreateEmpty();
	Item* i1 = i;

	while (!ListIsEmpty(i1))
	{
		double d=sqrt(pow(i1->value.x, 2) + pow(i1->value.y, 2));
		if (d < r)
		{
			nl = ListInsertBack(nl, i1);
		}

		i1 = ListGetTail(i1);

	}


	return nl;
}