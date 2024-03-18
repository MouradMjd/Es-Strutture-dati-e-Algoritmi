#include"elemtype.h"
#include"tree.h"


Node* TreeCopy(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	n->left = TreeCopy(TreeLeft(t));
	n->right = TreeCopy(TreeRight(t));
	return n;
}

Node* MergeTree(const Node* t1, const Node* t2)
{
	
	if (TreeIsEmpty(t1)&&TreeIsEmpty(t2))
	{
		return TreeCreateEmpty();
	}
	if (TreeIsEmpty(t1))
	{
		return TreeCopy(t2);
	}
	if (TreeIsEmpty(t2))
	{
		return TreeCopy(t1);
	}




	int s = *TreeGetRootValue(t1) + *TreeGetRootValue(t2);
	return TreeCreateRoot(&s, MergeTree(t1->left, t2->left), MergeTree(t1->right, t2->right));
}

