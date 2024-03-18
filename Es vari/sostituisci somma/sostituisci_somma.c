#include"elemtype.h"
#include"tree.h"


void Somma(Node* t,int *somma)
{
	if (t != NULL)
	{
	*somma = (*somma) + (*TreeGetRootValue(t));
	}
	if (TreeIsLeaf(t))
	{
		return;
	}
	Somma(TreeLeft(t), somma);
	Somma(TreeRight(t), somma);

}





extern void SostituisciSomma(Node* t)
{
	if (TreeIsLeaf(t))
	{
		return;
	}
	int somma = 0;
	Somma(t, &somma);
	ElemType* rad = TreeGetRootValue(t);
	ElemSwap(&somma,rad );


	SostituisciSomma(TreeLeft(t));
	SostituisciSomma(TreeRight(t));
}


//void main(void)
//{
//	ElemType v[] = { 0,1,1,1,3,3,1,9 };
//
//	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL),TreeCreateRoot(&v[4], TreeCreateRoot(&v[7],NULL,NULL), NULL)),
//			  TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
//	TreeWriteStdoutInOrder(t);
//	int somma = 0;
//	SostituisciSomma(t);
//
//
//}