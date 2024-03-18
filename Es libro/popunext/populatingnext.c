#include"elemtype.h"
#include"tree.h"


//void PopulatingNextrec(Node* t)
//{
//
//	if (TreeIsLeaf(t))
//	{
//		return;
//	}
//
//
//
//	PopulatingNextrec(TreeLeft(t));
//	if (t->next == NULL)
//	{
//		TreeLeft(t)->next = t;
//	}	
//	PopulatingNextrec(TreeRight(t));
//	if (t->next == NULL)
//	{
//		t->next = TreeRight(t);
//	}
//	
//
//}
//
//void PopulatingNext(Node* t)
//{
//	if (TreeIsEmpty(t)||t==NULL)
//	{
//		return TreeCreateEmpty();
//	}
//	Node* tml = t;
//	Node* tmr = t;
//	Node* rad = t;
//	tml = TreeLeft(tml);
//	while (TreeRight(tml)!=NULL)
//	{
//		tml = TreeRight(tml);
//	}
//	tml->next = rad;
//	tmr = TreeRight(tmr);
//	while (TreeLeft(tmr) != NULL)
//	{
//		tmr = TreeLeft(tmr);
//	}
//	rad->next = tmr;
//	PopulatingNextrec(t);
//}



void PopulatingNext(Node* t) {
    if (t == NULL)
        return;

    static Node* prev = NULL;
    // Ricorsione sul sottoalbero sinistro
    PopulatingNext(t->left);

    // Aggiornamento del campo next del nodo corrente
    if (prev != NULL)
        prev->next = t;

    prev = t;

    // Ricorsione sul sottoalbero destro
    PopulatingNext(t->right);
}



void main(void)
{

	ElemType v[] = { 1,2,3,3,4,6,8};
	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)), TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
	ElemType s = 23;
	PopulatingNext(t);

}