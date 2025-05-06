#include"elemtype.h"
#include"tree.h"



void num_n(Node* t,ElemType *e,int *i,int *serc )
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	num_n(t->left, e, i,serc);
	*i = *i + 1;
	if (ElemCompare(t, e) == 0)
	{
		*serc=*i;
	}
	num_n(t->right, e, i,serc);

}


Node* Predecessorerec(const Node* t, const ElemType* e,int *i,int v_size,Node **tn)
{
	if (TreeIsEmpty(t))
	{
		return t;
	}

	Predecessorerec(t->left, e, i, v_size,tn);
	*i = *i + 1;
	if (*i==v_size)
	{
		return *tn=t;
	}
	Predecessorerec(t->right, e, i, v_size,tn);
}

Node *Predecessore(const Node* t, const ElemType* e)
{
	int n = 0;
	int n_cer = 0;
	num_n(t, e, &n,&n_cer);
	if (n_cer == 1)
	{
		return TreeCreateEmpty();
	}
	int n1 = 0;
	Node* prec;
    Predecessorerec(t, e, &n1, n_cer - 1,&prec);
	return prec;
}
Node* Successorerec(const Node* t, const ElemType* e, int* i, int v_size, Node** tn)
{
	if (TreeIsEmpty(t))
	{
		return t;
	}

	Successorerec(t->left, e, i, v_size, tn);
	*i = *i + 1;
	if (*i == v_size)
	{
		return *tn = t;
	}
	Successorerec(t->right, e, i, v_size, tn);
}

Node* Successore(const Node* t, const ElemType* e)
{
	int n = 0;
	int n_cer = 0;
	num_n(t, e, &n, &n_cer);
	int size = 0;
	if (n_cer == n)
	{
		return TreeCreateEmpty();
	}
	int n1 = 0;
	Node* succ;
	Successorerec(t, e, &n1, n_cer + 1, &succ);
	return succ;
}



int main(void) {
	          //0,1,2,3,4,5,6
	int v[] = { 4,2,6,3,1,7,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));
	Node* tree2 = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[4], NULL, NULL), TreeCreateRoot(&v[3], NULL, NULL)),
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[6], NULL, NULL), TreeCreateRoot(&v[5], NULL, NULL)));
	Predecessore(tree2, &v[5]);
	Successore(tree2, &v[5]);


}