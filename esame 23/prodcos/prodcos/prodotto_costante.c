#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



bool ceck(int* v, int n)
{
	int cos = 1;
	for (size_t i = 0; i < n; i++)
	{
		cos = cos *(v[i]);
	}
     
	for (size_t r = 0; r < n; r++)
	{
		int cos1 = 1;
		for (size_t c = 0; c < n; c++)
		{
				cos1 = cos1 * v[r * n + c];
		}
		if (cos != cos1)
		{
			return false;
		}

	}


	for (size_t c = 0; c < n; c++)
	{
		int c2 = 1;
		for (size_t r = 0; r < n; r++)
		{
			c2 = c2 * v[r* n + c];
		}
		if (c2 != cos)
		{
			return false;
		}

	}



	return true;



}




int* RisolviProdottorec(int n, const int* s,int i,int *vcurr,int *pres,int *nsol,int **best)
{
	if (i == (n*n))
	{
		if (ceck(vcurr, n))
		{
			for (size_t i = 0,j=0; i < n*n; i++)
			{
				best[j][i] = vcurr[i];
			}
			*nsol = *nsol + 1;
		}
		return;

	}





	for (size_t j = 0; j < (n*n); j++)
	{
		if (pres[j] == 0)
		{
			vcurr[i] = s[j];
			pres[j] = 1;
			RisolviProdottorec(n, s, i + 1, vcurr, pres, nsol, best);
			pres[j] = 0;
		}

	}




}

int* RisolviProdotto(int n, const int* s)
{
	int* vcurr = calloc(n*n, sizeof(n));
	int* vbest = calloc(n * n, sizeof(n));
	int* pres = calloc(n*n, sizeof(int));
	int nsol = 0;
	RisolviProdottorec(n, s, 0, vcurr, pres, &nsol,&vbest);
	if (nsol == 0)
	{
		return NULL;
	}

	free(pres);
	free(vcurr);
	return vbest;
}



