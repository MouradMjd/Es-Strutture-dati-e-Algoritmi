#include"elemtype.h"
#include"tree.h"
#include<stdbool.h>


void TreeIsMirrorrec(Node* r, Node* l,bool *ans)
{
	if (r == NULL && l != NULL)
	{
		*ans = false;
		return;
	}
	if (r != NULL && l == NULL)
	{
		*ans = false;
		return;
	}
	if (TreeIsLeaf(r) && TreeIsLeaf(l))
	{
		if (r != NULL && l != NULL)
		{
			if (ElemCompare(r, l) != 0)
			{
				*ans = false;
			}
		}
		return;
	}
	if (ElemCompare(r, l) != 0)
	{
		*ans = false;
	}

	TreeIsMirrorrec(r->left, l->right, ans);
	TreeIsMirrorrec(r->right, l->left, ans);
}

extern bool TreeIsMirror(Node* t)
{
	bool answer = true;
	if(TreeIsEmpty(t))
	{
		return answer;
	}
	if (t->left == NULL && t->right == NULL)
	{
		return answer;
	}
	TreeIsMirrorrec(t->right, t->left, &answer);
	return answer;
}
//void main(void)
//{
//	ElemType v[] = { 0,5,5,1,5,1,1 };
//	Node* r = TreeCreateEmpty();
//	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], NULL,NULL), 
//		      TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), NULL));
//	TreeWriteStdoutInOrder(t);
//	TreeIsMirror(t);
//
//
//}