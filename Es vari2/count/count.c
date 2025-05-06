#include"elemtype.h"
#include"tree.h"


TreecountNodes(const Node* t, int* internal, int* external)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (TreeIsLeaf(t))
	{
		*external = *external + 1;
		return;
	}
	else
	{
		*internal = *internal + 1;
	}
	

	TreecountNodes(t->left, internal, external);
    TreecountNodes(t->right, internal, external);
}


int main(void) {
	int v[] = { 6,2,9,3,8,3,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));
	Node* tree2 = TreeCreateRoot(&v[0], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL));
	int inte = 0;
	int ex = 0;
	TreecountNodes(tree, &inte, &ex);


}