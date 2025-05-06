#include"elemtype.h"
#include"tree.h"


extern Node* Invertrec(Node* tl,Node*tr)
{
	if (tl==NULL || tr==NULL)
	{
		return;
	}

	ElemSwap(tl, tr);
	 Invertrec(TreeLeft(tl), TreeRight(tr));
	 Invertrec(TreeLeft(tr), TreeRight(tl));
	
}


extern Node* Invert(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return TreeCreateEmpty();
	}
	Invertrec(TreeLeft(t), TreeRight(t));
	return t;
}

//
//void main(void)
//{
//	ElemType v[] = { 2,1,3,7,4,2,4 };
//
//	Node* t = TreeCreateRoot(&v[0],
//		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)),
//		TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL,NULL)));
//	TreeWriteStdoutInOrder(t);
//	
//	Invert(t);
//
//}