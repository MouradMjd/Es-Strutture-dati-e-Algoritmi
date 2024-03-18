#include"elemtype.h"
#include"tree.h"



extern Node* BstInsertRec(const ElemType* e, Node* n)
{
    if (TreeIsEmpty(n))
    {
        return TreeCreateRoot(e,NULL,NULL);
    }




    if (ElemCompare(n,e) < 0)
    {
       return TreeCreateRoot(TreeGetRootValue(n), n->left, BstInsertRec(e, n->right));
    }
    else
    {
      return TreeCreateRoot(TreeGetRootValue(n), BstInsertRec(e, n->left), n->right);
    }


}


extern Node* BstInsert(const ElemType* e, Node* n)
{
	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e,NULL,NULL);
	}
	
    Node* rad = TreeGetRootValue(n);


    while (1)
    {
        if (ElemCompare(n,e)<0)
        {
            if (n->right==NULL)
            {
               n->right=TreeCreateRoot(e, NULL, NULL);
                break;
            }
            n = n->right;
        }
        else
        {
            if (n->left==NULL)
            {
                n->left = TreeCreateRoot(e, NULL, NULL);
                break;
            }
            n = n->left;
        }

    }
     
    return rad;


}


int main(void) {
    int v[] = { 4, 3, 7, 1, 4, 5, 6, 7, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1],TreeCreateRoot(&v[3],NULL,NULL),NULL), TreeCreateRoot(&v[2],NULL,NULL))
    ;

    TreeWritePreOrder(tree, stdout);
    int s = 10;
    Node* newt = BstInsert(&s, tree);
    TreeWritePreOrder(newt, stdout);


    
}