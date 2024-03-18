#include"elemtype.h"
#include"tree.h"


const ElemType* BstTreeMax(const Node* n)
{
  
	if (TreeIsLeaf(n))
	{
		return TreeGetRootValue(n);
	}
    if (n->right==NULL)
    {
        return TreeGetRootValue(n);
    }



	return BstTreeMax(n->right);

}

const ElemType* TreeMaxrec(const Node* n,ElemType **max)
{
    if (TreeIsEmpty(n))
    {
        return;
    }

    if (ElemCompare(n, *max) == 0|| ElemCompare(n, *max) > 0)
    {
        if (ElemCompare(n,*max)>0)
        {
         *max = TreeGetRootValue(n);
        }
    }
     TreeMaxrec(n->left, max);
     TreeMaxrec(n->right, max);
     


}
const ElemType* TreeMax(const Node* n)
{
    if (TreeIsEmpty(n))
    {
        return NULL;
    }
    ElemType* max = n;
    TreeMaxrec(n, &max);
    return max;
}

/*int main(void) {
    int v[] = { 4, 3, 7, 1, 2, 5, 6, 7, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL),NULL), TreeCreateRoot(&v[2], NULL, NULL))
        ;

    TreeWritePreOrder(tree, stdout);
    int s = 10;
   TreeMax(tree);
}*/