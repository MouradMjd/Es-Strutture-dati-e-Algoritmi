#include"elemtype.h"
#include"tree.h"
#include<math.h>



void Getbrec(Node* n,int *c,int i)
{
	if (TreeIsEmpty(n))
	{
		if (i > *c)
		{
			*c = i;
		}
		return;
    }

	Getbrec(n->left, c, i+1);
	Getbrec(n->right, c, i+1);
}
int Getb(Node* n)
{
	if (TreeIsEmpty(n))
	{
		return 0;
	}
	int c = 0;
	Getbrec(n, &c, 0);
	return c;
}

bool treeidb(Node *n)
{
	if (TreeIsEmpty(n))
	{
		return true;
    }

	int r = (fabs(Getb(n->left) - (Getb(n->right))));


	if (treeidb(n->left) && treeidb(n->right) && (r <= 1))//faccio le tre condizioni
	{
		return true;
	}
	 
	return false;
}









int main(void) {
	int v[] = { 6,2,9,3,8,3,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));
	Node *tree2 = TreeCreateRoot(&v[0], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL));
	bool t = treeidb(tree2);




}