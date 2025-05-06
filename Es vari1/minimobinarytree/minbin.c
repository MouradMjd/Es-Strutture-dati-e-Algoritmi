

#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

int min_(const ElemType* v, size_t s)
{
	int indice_min = 0;
	for (size_t i = 0; i < s; i++)
	{
		if (v[i] < v[indice_min])
		{
			indice_min = i;
		}
	}
	return indice_min;
}

extern Node* CreateMinBinTreerec(const ElemType* v, size_t v_size, Node* t, int i)
{
	if (v_size == 0)
	{
		return NULL;
	}
	if (v_size == 1)
	{
		return TreeCreateRoot(&v[0], NULL, NULL);
	}
	int ind_min = min_(v, v_size);
	int val_min = v[ind_min];
	size_t vl_size = ind_min;
	size_t vr_size = v_size - (ind_min + 1);
	int* vl = malloc(vl_size * sizeof(ElemType));
	int* vr = malloc(vr_size * sizeof(ElemType));
	if (vl_size != 0)
	{
		for (size_t i = 0; i < vl_size; i++)
		{
			vl[i] = v[i];
		}
	}
	if (vr_size != 0)
	{
		for (size_t i = ind_min + 1, j = 0; i < v_size; i++, j++)
		{
			vr[j] = v[i];
		}
	}

	t = TreeCreateRoot(&v[ind_min], CreateMinBinTreerec(vl, vl_size, t, i), CreateMinBinTreerec(vr, vr_size, t, i));
	free(vl);
	free(vr);

	return t;
}

extern Node* CreateMinBinTree(const ElemType* v, size_t v_size)
{
	Node* t = TreeCreateEmpty();
	t=CreateMinBinTreerec(v, v_size, t, 0);
	return t;

}

void main(void)
{
	const ElemType s[] = { 3,2,1,6,8,5 };
	CreateMinBinTree(s, 6);
	return;
}