#include"elemtype.h"
#include"tree.h"
#include<stdlib.h>




void LowestCommonAncestorrecrec(const Node* t, const Node* n1, const Node* n2,int i,int *r1, int *r2)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (ElemCompare(t, n1) == 0&&i!=0&&ElemCompare(n1,n2)!=0)
	{
		*r1 =  1;
	}
	if (ElemCompare(t, n1) == 0 &&ElemCompare(n1, n2) == 0 && i != 0)
	{
		*r1 = 1;
	}
	if (ElemCompare(t, n2) == 0&&i!=0 && ElemCompare(n1, n2) != 0)
	{
		*r2 =  1;
	}
	if (ElemCompare(t, n2) == 0 && ElemCompare(n1, n2) == 0 && i != 0)
	{
		*r2 = 1;
	}

	LowestCommonAncestorrecrec(t->left, n1, n2, i + 1, r1,r2);
	LowestCommonAncestorrecrec(t->right, n1, n2, i + 1, r1,r2);

}


void LowestCommonAncestorrec(const Node* t, const Node* n1, const Node* n2,Node **best,int *lb,int i)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	int w1 = 0;
	int w2 = 0;
	LowestCommonAncestorrecrec(t, n1, n2, 0,&w1,&w2);
	if ((w1 == 1||w2==1) && (ElemCompare(n1, n2) == 0))
	{
		if (i > *lb)
		{
			*best = t;
			*lb = i;
		}
	}
	if (w1==1&&w2==1&&(ElemCompare(n1,n2)!=0))
	{
		if (i > *lb)
		{
			*best = t;
			*lb = i;
		}
	}


	LowestCommonAncestorrec(t->left, n1, n2, best, lb,i+1);
	LowestCommonAncestorrec(t->right, n1, n2, best, lb,i+1);


}
Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2)
{
	Node* best = TreeCreateEmpty();
	int  lb = -1;
	LowestCommonAncestorrec(t, n1, n2, &best, &lb,0);
	return best;
}








