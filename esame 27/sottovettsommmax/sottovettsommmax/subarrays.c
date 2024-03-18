#include<stdio.h>
#include<stdlib.h>


int som(int* v, int* v1,size_t n)
{
	int s = 0;
	int som = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (v1[i] == 1&&(s==0||s==1))
		{
			som = som + v[i];
			s = 1;
		}
		if (i != 0 && v1[i] == 0)
		{
			s = 2;
		}
		if (s == 2&&v1[i]==1)
		{
			som = 0;
			s = 0;
		}

	}
	return som;
}


int OptimalSubarrayrec(const int* v, size_t n, int* vcurr, int i, int* vbest,int *somb)
{
	if (i == n)
	{
		int somvc = som(v, vcurr, n);
		if (somvc > *somb)
		{
			vbest = vcurr;
			*somb = som(v, vcurr, n);
		}

		return;
    }


	vcurr[i] = 1;
	OptimalSubarrayrec(v, n, vcurr, i + 1,vbest,somb);
	vcurr[i] = 0;
	OptimalSubarrayrec(v, n, vcurr, i + 1, vbest, somb);
}

int OptimalSubarray(const int* v, size_t n)
{
	int* vcurr = calloc(n, sizeof(int));
	int *vbest= calloc(n, sizeof(int));
	int* somb = 0;
	OptimalSubarrayrec(v, n, vcurr, 0,vbest,&somb);
	free(vcurr);
	free(vbest);
	return somb;
}


void main(void)
{
	int v[] = { 1, 2, 3, 4, 5, 6 };
	OptimalSubarray(v, 6);



}
