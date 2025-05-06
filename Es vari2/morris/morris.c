#include"elemtype.h"
#include"tree.h"





void Tmorris(Node* t)
{
	if (t == NULL)
	{
		return;
	}
	Node* curr = t;
	Node* prec = t;

	while (curr!=NULL)
	{
		if (curr->left == NULL)
		{
			prec = curr;
			curr = curr->right;
		}
		else
		{
			if (prec->right == curr)
			{
				prec = NULL;
				curr=curr->right;
			}
			else
			{
				curr = prec->right;
				curr = curr->left;
			}
		}
	}


}