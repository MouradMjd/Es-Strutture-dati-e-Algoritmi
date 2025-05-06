#include"elemtype.h"
#include"tree.h"



bool iso(const Node* t1, const Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
	
		return false;
	}

	return ElemCompare(t1, t2) == 0 && iso(t1->right, t2->left) && iso(t1->left, t2->right);

}



int main(void) {
	          //0,1,2,3,4,5,6
	int v[] = { 4,2,6,3,1,7,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));
	Node* tree1 = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[4], TreeCreateRoot(&v[4], NULL, NULL), NULL), TreeCreateRoot(&v[3], NULL, NULL)),
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[6], NULL, NULL), TreeCreateRoot(&v[5], NULL, NULL)));
	Node* tree2 = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)),

		TreeCreateRoot(&v[1], TreeCreateRoot(&v[2], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[4], NULL, NULL))));

	bool r = iso(tree1,tree2);
}