#include"elemtype.h"
#include"tree.h"
#include"stdlib.h"

int trova_max(int* v,size_t n)
{
	int max = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (v[i] > v[max])
		{
			max = i;
		}
	}
	return max;
}

extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size)
{
	if (v_size == 0)
	{
		return;
	}
	if (v_size==1)
	{
		return TreeCreateRoot(&v[0],NULL,NULL);
	}

	int ind_max = trova_max(v,v_size);
	int max = v[ind_max];
	int vr_size = (v_size - 1) - ind_max;
	int *vl = malloc(ind_max * sizeof(ElemType));
	int *vr = malloc(((v_size-1)-ind_max )* sizeof(ElemType));
	for (size_t i = 0; i < ind_max; i++)
	{
		vl[i] = v[i];
	}
	for (size_t i =(ind_max+1),j=0; i < v_size; i++,j++)
	{
		vr[j] = v[i];
	}


	Node*t=TreeCreateRoot(&max,CreateMaxBinTree(vl, ind_max),CreateMaxBinTree(vr, vr_size));
	free(vl);
	free(vr);
	return t;
}

//void main(void)
//{
//	int v[] = { 3,2,1,6,0,5 };
//	Node*t=CreateMaxBinTree(v, 6);
//
//
//
//}
