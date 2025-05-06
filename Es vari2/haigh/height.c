#include"elemtype.h"
#include"tree.h"


void treehightrec(const Node* t,int *a,int i)
{
	if (TreeIsLeaf(t))
	{
		if (i > *a)
		{
			*a = i;
		}
		return;
	}


	treehightrec(t->left, a, i + 1);
	treehightrec(t->right, a, i + 1);;
}



int treehight(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return -1;
	}

	int a = 0;
	treehightrec(t, &a,0);
	return a;

}


int main(void) {
	int v[] = { 0, 1, 7, 4, 2, 5, 6, 7, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree =
		TreeCreateRoot(&v[0],
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL)))
		;
	Node* tree1 =
		TreeCreateRoot(&v[0],
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
			TreeCreateRoot(&v[1],
				TreeCreateRoot(&v[6], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL)))
		;

	TreeWritePreOrder(tree, stdout);
	int s = 10;
	int n = treehight(tree);
	TreeWritePreOrder(tree, stdout);


}