#include"elemtype.h"
#include"tree.h"
#include<stdint.h>
#include<stdlib.h>

ElemType mint(ElemType* v, size_t s)
{

	ElemType s1=INT32_MAX;
	int j = 0;

	for (size_t i = 0; i < s; i++)
	{
		if (v[i] < s1)
		{
			s1 = v[i];
			j = i;
		}

	}

	return j;
}


Node* CreateMinBinTreerec(const ElemType* v, 
	size_t v_size)
{
	if (v_size == 0)
	{
		return TreeCreateEmpty();
	}

	size_t ind = mint(v, v_size);
	int* lv = calloc(ind, sizeof(int));
	int* rv = calloc((v_size - ind) - 1, sizeof(int));
	for (size_t i = 0; i < ind; i++)
	{
		lv[i] = v[i];
	}
	for (size_t i = ind + 1, j = 0; i < v_size; i++, j++)
	{
		rv[j] = v[i];
	}


	Node* l = CreateMinBinTreerec(lv, ind);
	Node* r = CreateMinBinTreerec(rv, (v_size - ind) - 1);
	return TreeCreateRoot(&v[ind], l, r);



	
}


void main(void)
{
	int v[] = { 3, 2, 1, 6, 8, 5 };
	Node* t = CreateMinBinTreerec(v, 6);
}