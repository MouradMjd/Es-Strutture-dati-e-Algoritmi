#include"elemtype.h"
#include"tree.h"



void CheckSumNrec(const Node* t, int n, bool* answer, int num, int i, int *w,int som)
{
	if (t == NULL||num>=n)
	{
		return;
	}
	i++;
	int r = *TreeGetRootValue(t) + num;
	if ( r == n&&(*TreeGetRootValue(t)!=num||i!=*w))
	{
		*answer =true;
	}


	CheckSumNrec(t->left, n, answer, num,i,w,som);
	CheckSumNrec(t->right, n, answer,num,i,w,som);
}

extern bool CheckSumNb(const Node* t, int n,bool *i,Node *tree,int w)
{
	if (tree == NULL)
	{
		return;
	}
	w=w+1;
	bool ans = false;
	int num = *TreeGetRootValue(tree);
	CheckSumNrec(t, n,&ans,num,0,&w,0);

	if (ans == true)
	{
	 return *i=true;
	}

	CheckSumNb(t, n,i,tree->left,w);
	CheckSumNb(t, n,i,tree->right,w);
}
extern bool CheckSumN(const Node* t, int n)
{
	bool ans = false;
	Node* tree = t;
	CheckSumNb(t, n, &ans, tree,0);
	return ans;

}
//void main(void)
//{
//	ElemType v[] = { 3,2,4,2,5,1,1 };
//
//	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
//		      TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
//	Node* r = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], NULL, NULL),
//		TreeCreateRoot(&v[2], NULL, NULL));
//
//	TreeWriteStdoutInOrder(t);
//	CheckSumN(r, 8);
//}