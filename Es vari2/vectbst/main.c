#include"elemtype.h"
#include"tree.h"


Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
	if (i >= (int)v_size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

	return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
	return TreeCreateFromVectorRec(v, v_size, 0);
}

void nric(Node *t,ElemType *n)
{
	if (t->right==NULL&& (ElemCompare(t, n) < 0|| ElemCompare(t, n) == 0))
	{
		if (ElemCompare(t, n) == 0)
		{
			return;
		}
		t->right = TreeCreateRoot(n, NULL, NULL);
			return;
	}
	if (t->left == NULL && (ElemCompare(t, n) > 0 || ElemCompare(t, n) == 0))
	{
		if (ElemCompare(t, n) == 0)
		{
			return;
		}
		t->left = TreeCreateRoot(n, NULL, NULL);
		    return;
	}



	if (ElemCompare(t, n) < 0)
	{
		nric(t->right, n);
	}
	else
	{
		nric(t->left, n);
	}

}

Node *vtobst(const ElemType* v, size_t v_size)
{
	if (v == NULL)
	{
		return TreeCreateEmpty();
	}
	Node* tree = TreeCreateRoot(&v[0], NULL, NULL);
	Node* rad = tree;
	for (size_t i = 1; i < v_size; i++)
	{
		nric(tree, &v[i]);

	}

	TreeWritePreOrder(rad,stdout);
		return rad;
}



void ins(ElemType* t, Node** tree,Node**rad) {
	if (TreeIsEmpty(*tree)) {
		*tree = TreeCreateRoot(t, NULL, NULL);
		*rad = *tree;//mi salvo la radice 
		
	}
	else
	{
		*tree = *rad;//reimposto la tree sulla radice 
		while (1)//faccio un while per scorrere l'albero
		{
			if (ElemCompare(TreeGetRootValue(*tree), t) < 0 || ElemCompare(TreeGetRootValue(*tree), t) == 0)//controllo se mx o min
			{
				if (TreeRight(*tree) == NULL) //se la posizione dx e vuota faccio l'inserimeto 
				{
					(*tree)->right = TreeCreateRoot(t, NULL, NULL);
					break;
				}

				*tree = (*tree)->right;//se no scorro a desta;

			}
			else 
			{
				if ((*tree)->left == NULL) //visto che min faccio inserimeto se la posizione e disponibile
				{
					(*tree)->left = TreeCreateRoot(t, NULL, NULL);
					break;;
				}

				*tree = (*tree)->left;//la posizione non e disponibile e quindi scorro a sinistra

			}
		}
	}
}

Node* t2bstrec(Node* t, Node** tree,Node **rad) {
	if (TreeIsEmpty(t)) {
		return;
	}

	t2bstrec(t->left, tree, rad);

		ins(t, tree, rad);
	
	t2bstrec(t->right, tree,rad);
}

Node* t2bst(Node* t) {
	Node* tree = TreeCreateEmpty();
	Node* rad = TreeCreateEmpty;
	t2bstrec(t, &tree,&rad);
	return rad;
}








int main(void) {
	int v[] = { 6,2,9,3,8,3,5};
	Node* t1 = vtobst(v, 7);
	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0], 
		TreeCreateRoot(&v[1],TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], NULL, NULL))),
		TreeCreateRoot(&v[2], NULL, TreeCreateRoot(&v[3], NULL, NULL)));
	Node* t = t2bst(tree);
	TreeWritePreOrder(t, stdout);



}