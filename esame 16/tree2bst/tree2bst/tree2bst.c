#include"elemtype.h"
#include"tree.h"

void* Tree2Bstrec(const Node* t,Node **tree,Node **rad)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	Tree2Bstrec(t->left, tree,rad);
	if (TreeIsEmpty(*tree))
	{
		*tree = TreeCreateRoot(t, NULL, NULL);
		*rad=*tree;
	}
	else
	{
		*tree = *rad;
		while (1)
		{
			
			if ((*tree)->left != NULL&&(ElemCompare(t,*tree)<0 || ElemCompare(*tree, t) == 0))
			{
					(*tree) = (*tree)->left;
			}
			if ((*tree)->right != NULL && ElemCompare(t, *tree) > 0)
			{
				(*tree) = (*tree)->right;
			}
			if ((ElemCompare(*tree, t) > 0 || ElemCompare(*tree, t) == 0)&& (*tree)->left==NULL)
			{
				(*tree)->left = TreeCreateRoot(t, NULL, NULL);
				break;
			}
			if ((ElemCompare(*tree, t) < 0) && (*tree)->right == NULL)
			{
				(*tree)->right = TreeCreateRoot(t, NULL, NULL);
				break;
			}
		}

	}
	Tree2Bstrec(t->right, tree,rad);


}
Node* Tree2Bst(const Node* t)
{
	Node* tree = TreeCreateEmpty();
	Node* rad = NULL;
	Tree2Bstrec(t, &tree,&rad);
	return rad;
}

