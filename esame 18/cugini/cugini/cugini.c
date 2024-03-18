#include"elemtype.h"
#include"tree.h"


void Cuginirec(const Node* t, int a, int b,int *pa,int *pb,int *pad,int i )
{

	if (TreeIsEmpty(t))
	{
		return;
	}
	if (ElemCompare(t, &a) == 0)
	{
		*pa = i;
	}
	if (ElemCompare(t, &b) == 0)
	{
		*pb = i;
	}
	if (t->left != NULL && t->right != NULL)
	{
		if ((ElemCompare(t->left, &a) == 0 || ElemCompare(t->right, &a) == 0) && (ElemCompare(t->left, &b) == 0 || ElemCompare(t->right, &b) == 0))

		{
			*pad = 1;
		}

	}

	Cuginirec(t->left, a, b, pa, pb, pad, i + 1);
	Cuginirec(t->right, a, b, pa, pb, pad, i + 1);

}
bool Cugini(const Node* t, int a, int b)
{
	int pa = 0;
	int pb = 0;
	int pad = 0;
	Cuginirec(t, a, b, &pa, &pb, &pad, 0);
	if (pad != 0)
	{
		return false;
	}
	if (pa != pb)
	{
		return false;
	}

	return true;

}

