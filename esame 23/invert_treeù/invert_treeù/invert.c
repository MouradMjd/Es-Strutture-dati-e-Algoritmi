#include"elemtype.h"
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>


void Invertrec(Node* l,Node*r)
{
	if (TreeIsEmpty(l) || TreeIsEmpty(r))
	{
		return;
	}
	ElemSwap(l, r);




	Invertrec(l->left,r->right);
	Invertrec(l->right, r->left);

}
extern Node* Invert(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return TreeCreateEmpty();
	}

	Invertrec(t->left,t->right);
	return t;
}


