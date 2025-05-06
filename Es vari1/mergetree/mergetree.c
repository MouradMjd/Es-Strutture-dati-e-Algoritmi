#include"elemtype.h"
#include"tree.h"

Node* TreeCopy(const Node* t) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
    n->left = TreeCopy(TreeLeft(t));
    n->right = TreeCopy(TreeRight(t));
    return n;
}

extern Node* MergeTree(const Node* t1, const Node* t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    if (t1 == NULL)
    {
        return TreeCopy(t2);
    }
    if (t2 == NULL)
    {
        return TreeCopy(t1);
    }

    int somma = *TreeGetRootValue(t1) + *TreeGetRootValue(t2);

    return TreeCreateRoot(&somma, MergeTree(t1->left, t2->left), MergeTree(t1->right, t2->right));
}


//void main(void)
//{
//    ElemType v[] = { 0,1,1,1,3,3,1 };
//
//    Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)), 
//                                                   TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
//    TreeWriteStdoutInOrder(t);
//    Node* r = MergeTree(t, t);
//
//
//}
