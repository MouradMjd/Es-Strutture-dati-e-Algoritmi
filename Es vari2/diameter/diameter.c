#include"elemtype.h"
#include"tree.h"


void profrrec(const Node* t,int *b,int i)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (i > *b)
	{
		*b = i;
	}
    
	profrrec(t->left, b, i + 1);
	profrrec(t->right, b, i + 1);
}

int diameter(const Node* t)
{
	int l1 = 0;
	int r2 = 0;
	profrrec(t->left, &l1, 1);
	profrrec(t->right, &r2, 1);
	int diam = l1 + r2 + 1;
	return diam;

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



	int r = diameter(tree1);
}