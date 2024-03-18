#include"elemtype.h"
#include"tree.h"

bool TreeIsMirrorrec(Node* t1,Node* t2)
{
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
	{
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2))
	{
		return false;
	}



	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2))==0 && TreeIsMirrorrec(TreeLeft(t1), TreeRight(t2)) && TreeIsMirrorrec(TreeRight(t1), TreeLeft(t2));

}





bool TreeIsMirror(Node* t)
{
	if (TreeIsEmpty(t) || (TreeLeft(t) == NULL && TreeRight(t) == NULL))
	{
		return true;
	}


	return TreeIsMirrorrec(TreeLeft(t), TreeRight(t));
}

//
//void main(void)
//{
//	ElemType v[] = { 0,1,1,1,3,3,1 };
//	
//	Node* t = TreeCreateRoot(&v[0], TreeCreateRoot(&v[1],TreeCreateRoot(&v[3],NULL,NULL), TreeCreateRoot(&v[4], NULL, NULL)), TreeCreateRoot(&v[2], TreeCreateRoot(&v[5], NULL, NULL), TreeCreateRoot(&v[6], NULL, NULL)));
//	TreeWriteStdoutInOrder(t);
//	TreeIsMirror(t);
//
//
//}