#include"elemtype.h"
#include"tree.h"
#include<float.h>

void n_elem(Node* t,int *size)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	*size = *size + 1;
	if (TreeIsLeaf(t))
	{
		return;
	}

	n_elem(t->left, size);
	n_elem(t->right,size);
}



void medianorecp(const Node* t, int* i, int ind_v, int* val1,int*val2)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	medianorecp(t->left, i, ind_v, val1,val2);
	*i = *i + 1;
	if (*i == (ind_v-1))
	{
		*val1 = *(TreeGetRootValue(t));
	}
	if (*i == ind_v)
	{
		*val2 = *(TreeGetRootValue(t));
	}
	medianorecp(t->right, i, ind_v,val1,val2);

}
void medianorecd(const Node* t,int *i,int ind_v,double *med)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	medianorecd(t->left, i , ind_v, med);
	*i = *i + 1;
	if (*i == ind_v)
	{
		*med = *(TreeGetRootValue(t));
	}
	medianorecd(t->right, i , ind_v, med);
}

extern double mediano(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return DBL_MAX;
	}

	int size = 0;
	n_elem(t, &size);
	int r = 0;
	r = (size / 2) + 1;
	double med = 0;
	int n = 0;
	if (size % 2 != 0)
	{
	  	medianorecd(t, &n, r, &med);
	}
	else
	{
		double val1 = 0;
		double val2 = 0;
		medianorecd(t, &n, r, &val1,&val2);
	    med = (val1 + val2) / 2; 
	}
	return med;
}


int main(void) {
	          //0,1,2,3,4,5,6
	int v[] = { 4,2,6,3,1,7,5 };

	size_t v_size = sizeof(v) / sizeof(int);
	Node* tree = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[3], NULL, NULL), TreeCreateRoot(&v[4], NULL, TreeCreateRoot(&v[6], TreeCreateRoot(&v[3], NULL, NULL), NULL))),
		TreeCreateRoot(&v[2], NULL, NULL));
	Node* tree2 = TreeCreateRoot(&v[0], 
		TreeCreateRoot(&v[1], TreeCreateRoot(&v[4], NULL, NULL), NULL),
		TreeCreateRoot(&v[2], TreeCreateRoot(&v[6], NULL, NULL), TreeCreateRoot(&v[5], NULL, NULL)));
	double m=mediano(tree2);


}