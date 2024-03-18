#include"elemtype.h"
#include"tree.h"
#include<stdbool.h>



bool equivalenti(Node *t1,Node *t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		return false;
	}
	
	bool s = true;
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2))
	{
		int v1 = 0;
		int v2 = 0;
		if (ElemCompare(t1, t2) < 0)
		{
			v1 = *TreeGetRootValue(t2);
			v2 = *TreeGetRootValue(t1);
		}
		else
		{
			v1 = *TreeGetRootValue(t1);
			v2 = *TreeGetRootValue(t2);
		}
		if (v1 % v2 != 0)
		{
			s = false;
		}
	}
	else
	{
		if (ElemCompare(t1, t2) != 0)
		{
			s = false; 
	    }
	}

	return s && equivalenti(t1->left, t2->left) && equivalenti(t1->right, t2->right);

}































int main(void) {
	          //0,1,2,3,4,5,6 7  8  9
	int v[] = { 4,2,6,3,1,7,5,8,12,21 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));

	
	Node* tree1 = TreeCreateRoot(&v[4],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[0], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[7], NULL, NULL)), TreeCreateRoot(&v[6], NULL, NULL)),

		TreeCreateRoot(&v[3], TreeCreateRoot(&v[2], NULL, NULL), NULL));

	Node* tree2 = TreeCreateRoot(&v[4],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[0], TreeCreateRoot(&v[9], NULL, NULL), TreeCreateRoot(&v[1], NULL, NULL)), TreeCreateRoot(&v[6], NULL, NULL)),

		TreeCreateRoot(&v[3], TreeCreateRoot(&v[5], NULL, NULL), NULL));



	bool r = equivalenti(tree1,tree2);
}