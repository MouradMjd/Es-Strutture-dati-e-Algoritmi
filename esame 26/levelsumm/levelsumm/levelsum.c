#include"elemtype.h"
#include"tree.h"






void LevelSumrec(const Node* t, size_t level,int i,int*som)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (i == level)
	{
		*som = *som + *TreeGetRootValue(t);
		return;
	}

	LevelSumrec(t->left, level, i + 1, som);
	LevelSumrec(t->right, level, i + 1, som);
}

int LevelSum(const Node* t, size_t level)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}
	int som = 0;
	LevelSumrec(t, level, 0,&som);
	return som;
}
