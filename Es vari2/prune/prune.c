#include"elemtype.h"
#include"tree.h"
#include<stdlib.h>


Node* tprunerec(Node* t, const ElemType* cut_value)
{
	if (TreeIsLeaf(t))
	{
		return;
	}

	tprunerec(t->left, cut_value);
	tprunerec(t->right, cut_value);
	if (t->right!=NULL&&ElemCompare(t->right, cut_value) == 0)
	{
		TreeDelete(t->right);
		t->right = NULL;
	}
	if (t->left!=NULL&&ElemCompare(t->left, cut_value) == 0)
	{
		TreeDelete(t->left);
		t->left = NULL;
	}
}
Node* tprune(Node* t, const ElemType* cut_value)
{
	if (TreeIsEmpty(t) || ElemCompare(t, cut_value) == 0)
	{
		return TreeCreateEmpty();
	}
	tprunerec(t, cut_value);
	return t;
}


Node* tprune(Node* t, const ElemType* cut_value)
{
	if (TreeIsEmpty(t))
	{
		return t;
	}
	
	if (ElemCompare(t, cut_value) == 0)
	{
		TreeDelete(t);
		return TreeCreateEmpty();
	}

	t->left = tprune(t->left, cut_value);//se lo trovo e torno indietro metto la t.left a null
	t->left = tprune(t->right, cut_value);//stessa cosa ma con right
}


int main(void){
	          //0,1,2,3,4,5,6
	int v[] = { 6,2,9,3,8,3,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[2], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[5], NULL, NULL)));
	Node* tree2 = TreeCreateRoot(&v[0], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[3], NULL, TreeCreateRoot(&v[6], NULL, NULL)));
	int n = 3;
	Node* t = tprune(tree, &n);




}