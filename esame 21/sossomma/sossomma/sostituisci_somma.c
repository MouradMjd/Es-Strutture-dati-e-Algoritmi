#include"elemtype.h"
#include"tree.h"




void som(int* s, Node* t)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	*s = *s + *TreeGetRootValue(t);


	som(s, t->left);
	som(s, t->right);
}

void SostituisciSomma(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return;
	}


	int s = 0;
	som(&s, t);
	ElemSwap(TreeGetRootValue(t), &s);

	SostituisciSomma(t->left);
	SostituisciSomma(t->right);
}