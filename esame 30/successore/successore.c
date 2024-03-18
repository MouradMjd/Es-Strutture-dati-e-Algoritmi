#include"elemtype.h"
#include"tree.h"
#include<float.h>
#include<stdint.h>

void* Successorerec(const Node* t, const Node* n,Node **nvol )
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (ElemCompare(n, t) < 0)
	{
		if (ElemCompare(*nvol,t) > 0)
		{
			*(nvol) = t;
		}
	}


	Successorerec(t->left, n, nvol);
	Successorerec(t->right, n, nvol);

}

Node* Successore(const Node* t, const Node* n)
{
	if (TreeIsEmpty(t))
	{
		return NULL;
	}
	int s = INT16_MAX;
	Node* t1= TreeCreateRoot(&s,NULL,NULL);
	Successorerec(t, n, &t1);
	if (ElemCompare(t1, &s) == 0)
	{
		TreeDelete(t1);
		return NULL;
	}
	return t1;
}


