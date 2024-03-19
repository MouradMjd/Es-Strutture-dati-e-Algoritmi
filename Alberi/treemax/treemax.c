#include"elemtype.h"
#include"tree.h"

const ElemType* BstTreeMax(const Node* n)
{
	Node* tree = n;
	while (true)
	{
		if (TreeRight(tree) == NULL)
		{
			return TreeGetRootValue(tree);
		}
		tree= TreeRight(tree);

	}
}

const ElemType* TreeMaxRec(const Node* n,ElemType **best)
{
	if (TreeIsLeaf(n))
	{
		if (!TreeIsEmpty(n)&&ElemCompare(TreeGetRootValue(n),*best) > 0)
		{
			*best = TreeGetRootValue(n);
		}
		return;
	}
	if (ElemCompare(TreeGetRootValue(n), *best) > 0)
	{
		*best= TreeGetRootValue(n);
	}
	
	TreeMaxRec(TreeLeft(n), best);
	TreeMaxRec(TreeRight(n), best);
}

 const ElemType* TreeMax(const Node* n)
{
	 if (n == NULL)
	 {
		 return NULL;
	 }

	ElemType  * best= TreeGetRootValue(n);
	TreeMaxRec(n, &best);
	return best;
    
}






