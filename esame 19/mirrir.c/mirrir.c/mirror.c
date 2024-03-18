#include<stdlib.h>
#include<stdbool.h>
#include"elemtype.h"
#include"tree.h"
void TreeIsMirrorrec(Node* t1,Node *t2,bool *ri)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		*ri = false;
		return;
	}
	if (ElemCompare(t1, t2) != 0)
	{
		*ri = false;
	}

	TreeIsMirrorrec(t1->left, t2->right,ri);
	TreeIsMirrorrec(t1->right, t2->left, ri);
}

bool TreeIsMirror(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return true;
	}
	if (t->left == NULL && t->right == NULL)
	{
		return true;
	}
	bool r = true;
	TreeIsMirrorrec(t->left, t->right, &r);
	return r;
}





