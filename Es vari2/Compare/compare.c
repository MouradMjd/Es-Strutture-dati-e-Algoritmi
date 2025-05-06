#include"elemtype.h"
#include"tree.h"





bool Treeareidrec(const Node* t1, const Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		return false;
	}



	return (ElemCompare(t1, t2) == 0 && Treeareidrec(t1->left, t2->left) && Treeareidrec(t1->right, t2->right));


}


bool Treeareid(const Node* t1, const Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		return false;
	}
	if (ElemCompare(t1, t1) != 0)
	{
		return false;
	}
    

	return Treeareidrec(t1, t2);
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
	bool n = Treeareid(tree, tree1);
	TreeWritePreOrder(tree, stdout);


}