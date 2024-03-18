#include"elemtype.h"
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>





void PercorsoSommarec(Node* t, const ElemType* target,int *r,int som,int i)
{
	if (ElemCompare(target, &som) == 0&&i!=1)
	{
		*r = 1;
	}
	if (TreeIsEmpty(t))
	{
		return;
	}


	PercorsoSommarec(t->left, target, r, som + t->value,i+1);
	PercorsoSommarec(t->right, target, r, som + t->value,i+1);

}




bool PercorsoSomma(Node* t, const ElemType* target)
{

	if (TreeIsEmpty(t))
	{
		return false;
	}
	int r = 0;

	PercorsoSommarec(t, target, &r, 0,0);
	if (r == 0)
	{
		return false;
	}
	return true;

}





