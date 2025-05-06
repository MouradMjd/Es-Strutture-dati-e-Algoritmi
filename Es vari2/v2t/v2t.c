#include"elemtype.h"
#include"tree.h"
#include"v2t.h"

Node* find(Node* tree, ElemType* v)
{
	if (TreeIsEmpty(tree))
	{
		return;
	}
	if (ElemCompare(tree, v) == 0)
	{
		return tree;
	}



	 find(tree->left, v);
	 find(tree->right, v);

}



Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
	if (i >= (int)v_size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

	return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
	return TreeCreateFromVectorRec(v, v_size, 0);
}







void main(void)
{
	ElemType v ="abcde-f";
	Node* t = TreeCreateFromVector("abcde-f", 7);

}