#include"elemtype.h"
#include"tree.h"

bool TreeContainsNode(const Node* tree, const Node* node,bool *n,int i)
{
	if ((tree != NULL&&i!=0)||TreeIsLeaf(tree))
	{
		if (ElemCompare(TreeGetRootValue(tree), TreeGetRootValue(node)) == 0)
		{
			*n = true;
			return ;
		}
		return;
	}

	 TreeContainsNode(TreeLeft(tree), node,n,i+1);
	 TreeContainsNode(TreeRight(tree), node,n,i+1);
	 return n;
}

const Node* LowestCommonAncestorrec(const Node* t, const Node* n1, const Node* n2,Node**anc)
{

	if (t != NULL)
	{
		bool n11 = false;
		bool n22 = false;
		TreeContainsNode(t, n2, &n11,0);
		TreeContainsNode(t, n1, &n22,0);
		if ( n11&&n22 )
		{
			*anc= t;
		}
	}
	if (TreeIsLeaf(t))
	{
		return;
	}

	LowestCommonAncestorrec(TreeLeft(t), n1,n2,anc);
	LowestCommonAncestorrec(TreeRight(t), n1,n2,anc);
	return anc;
}
const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2)
{
	ElemType i = NULL;
	Node* anc=TreeCreateRoot(&i,NULL,NULL);
	LowestCommonAncestorrec(t, n1, n2, &anc);
	return anc;
}


void main(void)
{
	ElemType v[] = { 'a','b','c','d','e','f','g'};
	ElemType n = 'd';
	ElemType n3 = 'e';
	Node* n1 = TreeCreateRoot(&n,NULL,NULL);
	Node* n2 = TreeCreateRoot(&n3, NULL, NULL);
	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1],TreeCreateRoot(&v[3],NULL,NULL), TreeCreateRoot(&v[4], NULL, NULL)), TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
	TreeWriteStdoutInOrder(t);
	LowestCommonAncestor(t, n1, n2);

}
