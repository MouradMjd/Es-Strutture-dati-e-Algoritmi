#include"elemtype.h"
#include"tree.h"


bool PercorsoSommarec(Node* t, const ElemType* target,int somma,bool *v)
{
	somma = somma + *TreeGetRootValue(t);
	if (TreeIsLeaf(t))
	{
		if (somma == *target)
		{
			*v = true;
			return;
		}
		else
		{
			return;
		}
	

	}

	

	 PercorsoSommarec(TreeLeft(t), target, somma ,v);
	 PercorsoSommarec(TreeRight(t), target, somma ,v);

}



bool PercorsoSomma(Node* t, const ElemType* target)
{
	bool s = false;
	if (TreeIsEmpty(t))
	{
		return false;
	}
	 PercorsoSommarec(t, target, 0,&s);
	 return s;



}


//void main(void)
//{
//
//	elemtype v[] = { 1,2,3,3,4 };
//	node* t = treecreateroot(&v[0], treecreateroot(&v[1], treecreateroot(&v[3], null, null), treecreateroot(&v[4], null, null)), treecreateroot(&v[2], null, null));
//	elemtype s = 23;
//	percorsosomma(t,&s );
//
//}