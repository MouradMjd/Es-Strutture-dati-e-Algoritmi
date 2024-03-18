#include"elemtype.h"
#include"tree.h"




extern Node* DeleteBstNoderec(Node* n,Node *Prev)
{
	if (TreeIsLeaf(n))
	{
		if (ElemCompare(n, Prev->left) == 0)
		{
			TreeDelete(n);
			Prev->left = NULL;
	    }
		else
		{
			TreeDelete(n);
			Prev->right = NULL;
		}
		return n;
	}

	ElemSwap(n, n->left);
	Prev = n;
	DeleteBstNoderec(n->left,Prev);

}


extern Node* DeleteBstNode(Node* n, const ElemType* key)
{
	if (TreeIsEmpty(n))
	{
		return TreeCreateEmpty();
	}
	Node* rad = TreeGetRootValue(n);
	Node* prev=n;
	int i = 0;
	while (1)
	{
	
		if (ElemCompare(n,key)==0)
		{
			DeleteBstNoderec(n,prev);
			break;
		}
		if (i != 0)
		{
			prev = n;
		}
		if (ElemCompare(n,key)<0)
		{
			n = n->right;
		}
		else
		{
			n = n->left;
		}
		i++;
	}
	return rad ;
}



/*int main(void) {
	int v[] = { 4, 3, 7, 1, 2, 5, 6, 7, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL),NULL), TreeCreateRoot(&v[2], NULL, NULL))
		;

	TreeWritePreOrder(tree, stdout);
	int s = 3;
	tree=DeleteBstNode(tree, &s);
	TreeWritePreOrder(tree, stdout);


}*/