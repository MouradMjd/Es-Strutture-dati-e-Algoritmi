#include"elemtype.h"
#include"tree.h"




bool TreesAreTwins(const Node* t1, const Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}

	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		return false;
	}

	return TreesAreTwins(t1->left, t2->left) && TreesAreTwins(t1->right, t2->right);
}






