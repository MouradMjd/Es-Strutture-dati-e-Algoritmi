#include"elemtype.h"
#include"tree.h"

bool TreeIsMirrorrec(const Node* t1, const Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || !TreeIsEmpty(t2))
	{
	
		return false;
	}

  

	return (ElemCompare(TreeGetRootValue(t1),TreeGetRootValue(t2)) == 0) && TreeIsMirrorrec(t1->left,t2->right) && TreeIsMirrorrec(t1->left, t2->right);

	

}

bool TreeIsMirror(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return true;
	}

	return TreeIsMirrorrec(t->left, t->right);
	

}


/*int main(void) {
	int v[] = { 0, 1, 7, 4, 2, 5, 6, 7, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = 
		TreeCreateRoot(&v[0], 
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL)))
		;

	TreeWritePreOrder(tree, stdout);
	int s = 10;
	bool n = TreeIsMirror(tree);
	TreeWritePreOrder(tree, stdout);


}*/