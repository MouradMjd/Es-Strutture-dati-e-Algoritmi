#include"elemtype.h"
#include"tree.h"




int CountDominantrec(const Node* t,int *n)
{
    if (TreeIsLeaf(t))
    {
        return;
    }


    ElemType* l = t->left;
    ElemType* r = t->right;
    if (l != NULL && r != NULL)
    {
        int sum = (*l + *r);
        if (ElemCompare(t, &sum) > 0)
        {
            *n = *n + 1;
        }
    }
    CountDominantrec(t->left, n);
    CountDominantrec(t->right, n);

}

int CountDominant(const Node* t)
{
    if (TreeIsEmpty(t))
    {
        return 0;
    }

    int n = 0;
    CountDominantrec(t, &n);
    return n;
}












/*int main(void) {
    int v[] = { 15, 3, 7, 1, 2, 5, 6, 7, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL),NULL), TreeCreateRoot(&v[2], NULL, NULL))
        ;

    TreeWritePreOrder(tree, stdout);
    int s = 10;
    int n = CountDominant(tree);


    
}*/