#include"elemtype.h"
#include"tree.h"
#include<stdlib.h>

Node* treec(Node* t,Node *e,int *s)
{
	if (TreeIsLeaf(t))
	{
		ElemSwap(t, e);
		free(t);
		*s = 1;
		return TreeCreateEmpty();
	}
	if (*s != 1)
	{
		t->left = treec(t->left, e, s);
	}


	
}


void main(void)
{
	int v[] = { 2,1,3,7,4,2,4 };
	Node* t = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[0], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)));
	ElemType e = 11;
	int d = 0;
	treec(t, t->left,&d);

}