#include"elemtype.h"
#include"tree.h"
#include<stdlib.h>

Node* bst(Node* t, ElemType* e)
{
	if (TreeIsEmpty(t))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}
	while (true)
	{
		if (ElemCompare(e, t) <= 0)
		{
			if (t->left == NULL)
			{
				t->left = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			t = t->left;
			continue;
		}
		if (ElemCompare(e, t) > 0)
		{
			if (t->right == NULL)
			{
				t->right=TreeCreateRoot(e, NULL, NULL);
				break;
			}
			t=t->right;
		}
	}
	return t;

}

void Tree2Bstrec(const Node* t, Node** ppt, int* l, Node** rad)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	Tree2Bstrec(TreeLeft(t), ppt, l, rad);
	if (*l == 0)
	{
		*ppt = bst(*ppt, t);
	}
	else
	{
		*ppt = bst(*rad, t);
	}
	 
	 if (*l == 0)
	 {
		 * rad = ppt[0];
		 *l = 1;
	 }
	Tree2Bstrec(TreeRight(t), ppt, l,rad);

}


extern Node* Tree2Bst(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return TreeCreateEmpty();
	}
	Node** stack = malloc(1*sizeof(Node*));
	stack[0] = TreeCreateEmpty();
	Node** rad = malloc(1 * sizeof(Node*));
	rad[0] = TreeCreateEmpty();
	int l = 0;
	Tree2Bstrec(t, stack,&l,rad);
	Node* tree = rad[0];
	free(stack);
	free(rad);
	return tree;
}

//void main(void)
//{
//	ElemType v[] = { 6,2,9,3,8,5,3 };
//
//	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[5],NULL,NULL))),
//			  TreeCreateRoot(&v[2], NULL, TreeCreateRoot(&v[6], NULL, NULL)));
//	TreeWriteStdoutInOrder(t);
//	Tree2Bst(t);
//
//
//}