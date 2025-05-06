#include"elemtype.h"
#include"tree.h"


void livelli(Node *t, int i, int* n)//ritorno i livelli che ha l'albero
{
	if (TreeIsLeaf(t))
	{
		*n = i;
		return;
	}

	livelli(t->left, i + 1, n);
	livelli(t->right, i + 1, n);
}

void lev_orrec(const Node *t,int n,int i)//per ogni livello stampo gli elementi li
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if (i == n)
	{
		printf("%d ", *TreeGetRootValue(t));
	}

	lev_orrec(t->left,n , i + 1);
	lev_orrec(t->right, n, i + 1);
}


void lev_or(const Node* t)
{

	int liv = 0;
	livelli(t, 0, &liv);

	for (size_t i = 0; i <= liv; i++)//uso un for per andare a stampare per ogni livello gli elementi voluti
	{
		lev_orrec(t, i, 0);
		printf("\n");
	}
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
	lev_or(tree2);


}