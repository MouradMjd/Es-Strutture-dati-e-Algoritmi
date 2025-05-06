#include<stdlib.h>

int iscont(int* v,int size)
{
	int cont = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (cont == 0 && v[i] == 0)
		{
			continue;
		}
		if (cont == 0 && v[i] == 1)
		{
			cont = 1;
		}
		if (cont == 1 && v[i] == 0)
		{
			cont = 0;
			break;
		}
	}
	return cont;
	
}
int OptimalSubarrayrec(const int* v, size_t n,int *vcurr,int i,int somma,int *somma_best)
{
	if (i == n)
	{
		int con = iscont(vcurr, n);
		if (con)
		{
			if (somma > (*somma_best))
			{
				(*somma_best) = somma;
			}
		}
		return;
	}

	vcurr[i] = 1;
	OptimalSubarrayrec(v, n, vcurr, i + 1, somma + v[i], somma_best);
	vcurr[i] = 0;
	OptimalSubarrayrec(v, n, vcurr, i + 1, somma, somma_best);
}









int OptimalSubarray(const int* v, size_t n)
{
	if (n == 0)
	{
		return 0;
	}

	int* vcurr = calloc(n,sizeof(int));
	int sommabest = 0;
	OptimalSubarrayrec(v, n,vcurr, 0,0,&sommabest);

	free(vcurr);
	return sommabest;
}


void main(void)
{
	int v[] = { -1, -2, -3, -4, -5, -6 };
	OptimalSubarray(v, 6);
}