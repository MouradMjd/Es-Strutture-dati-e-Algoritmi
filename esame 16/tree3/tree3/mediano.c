#include"elemtype.h"
#include"tree.h"
#include<float.h>

int size(Node* t, int* i)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	*i = *i + 1;
	size(t->left, i);
	size(t->right, i);
	

}
void Medianorec(const Node* t,int s,int *i,double *n)
{
	if (TreeIsEmpty(t))
	{
		return;
	}



	Medianorec(t->left,s, i,n);
	if (*i == s)
	{
		*n = t->value;
	}
	*i = *i + 1;
	Medianorec(t->right, s, i,n);

}

double Mediano(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return DBL_MAX;
	}
	int s = 0;
	size(t, &s);
	if (s % 2 != 0)
	{
		int e = 0;
		double n = 0;
		Medianorec(t, s / 2, &e, &n);
		return n;
	}
	else
	{
		int e1 = 0;
		double n1 = 0;
		int e2 = 0;
		double n2 = 0;
		Medianorec(t, s / 2, &e1, &n1);
		Medianorec(t, (s / 2)-1, &e2, &n2);
		double ris = (n1 + n2) / 2;
		return ris;
	}
}

void main(void)
{
	int* v[] = { 3,2,4,5 };
	Node* t = TreeCreateRoot(&v[0],
		TreeCreateRoot(&v[1], NULL, NULL),
		TreeCreateRoot(&v[2], NULL, TreeCreateRoot(&v[3], NULL, NULL)));
	Mediano(t);

}

