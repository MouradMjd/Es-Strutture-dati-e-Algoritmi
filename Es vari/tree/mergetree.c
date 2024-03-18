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
extern Node* MergeTreerec(const Node* t1, const Node* t2)
{
    if (TreeIsEmpty(t1) && !TreeIsEmpty(t2))
    {
        return TreeCopy(t2);
    }
    if (TreeIsEmpty(t2) && !TreeIsEmpty(t1))
    {
        return TreeCopy(t1);
    }

    int somma = ((*TreeGetRootValue(t1)) + (*TreeGetRootValue(t2)));

    if (TreeIsLeaf(t1)&&TreeIsLeaf(t2))
    {
        return TreeCreateRoot(&somma, NULL, NULL);
    }

        


   return  TreeCreateRoot(&somma, MergeTreerec(TreeLeft(t1),TreeLeft(t2)),MergeTreerec(TreeRight(t1),TreeRight(t2)));

}


extern Node* MergeTree(const Node* t1, const Node* t2)
{
    if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
    {
        return NULL;
    }


    Node* tree = TreeCreateEmpty();
    return MergeTreerec(t1, t2);
}


void main(void)
{
    ElemType v[] = { 2,1,1,1,3,3,1};
    ElemType v1[] = { 2,1,1,1,3,3};

    Node* t1 = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, NULL)), TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
    

    Node* t2 = TreeCreateRoot(&v1[0], TreeCreateRoot(&v1[1], TreeCreateRoot(&v1[3], NULL, NULL), TreeCreateRoot(&v1[4], NULL, NULL)), TreeCreateRoot(&v1[2], TreeCreateRoot(&v1[5], NULL, NULL), NULL));
  
    Node * s=MergeTree(t1,t2);


}

