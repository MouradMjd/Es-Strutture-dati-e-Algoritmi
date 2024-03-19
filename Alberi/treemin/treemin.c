#include"elemtype.h"
#include"tree.h"

const ElemType* BstTreeMin(const Node* n)
{
	Node* tree = n;
	while (true)
	{
		if (TreeLeft(tree) == NULL)
		{
			return TreeGetRootValue(tree);
		}
		tree = TreeLeft(tree);

	}
}

void TreeMinRec(const Node* n, ElemType **best)
{
	if (TreeIsLeaf(n))
	{
		if (!TreeIsEmpty(n) && ElemCompare(TreeGetRootValue(n), *best) < 0)
		{
			*best = TreeGetRootValue(n);
		}
		return;
	}
	if (ElemCompare(TreeGetRootValue(n), *best) < 0)
	{
		*best = TreeGetRootValue(n);
	}
	TreeMinRec(TreeRight(n), best);
	TreeMinRec(TreeLeft(n), best);
}

ElemType* TreeMin(const Node* n)
{
	if (n == NULL)
	{
		return NULL;
	}

	ElemType* best = TreeGetRootValue(n);
	TreeMinRec(n, &best);
	return best;
}

