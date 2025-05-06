#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



int cost(int* vcurr,int n)
{
	int costante = 1;
	for (size_t i = 0; i < n; i++)
	{
		costante = costante * vcurr[i];
	}

	for (size_t r = 0; r < n; r++)
	{
		int c2 = 1;
		for (size_t c = 0; c < n; c++)
		{
			c2 = c2 * vcurr[r * n + c];
		}
		if (c2 != costante)
		{
			return 0;
		}
	}
	for (size_t c = 0; c < n; c++)
	{
		int c1 = 1;
		for (size_t r = 0; r < n; r++)
		{
			c1 = c1 * vcurr[r * n + c];
		}
		if (c1 != costante)
		{
			return 0;
		}
	}


	return 1;

}

void* RisolviProdottor(int n, const int* s, int* vcurr, int i, int size, bool* usato,int *nsol)
{
	if (i == (n * n))
	{
		if (cost(vcurr, n) == 1)
		{
			for (size_t r = 0; r < n; r++)
			{
				for (size_t c = 0; c < n; c++)
				{
					printf("%d ",vcurr[r * n + c]);
				}
				printf("\n");
			}
			printf("\n");
			*nsol = *nsol + 1;
		}
		return;

	
	}




	for (size_t j = 0; j < size+1; j++)
	{
		if (usato[j] != true)
		{
			usato[j] = true;
			vcurr[i] = s[j];
			RisolviProdottor(n, s, vcurr, i + 1, size,usato,nsol);
			usato[j] = false;
		}
	}


}

int* RisolviProdotto(int n, const int* s)
{
	int* vcurr = calloc(n * n, sizeof(int));
	int size = sizeof(s);
	bool* usati = calloc((size+1), sizeof(bool));//creeo un vettore di bool per tenere presente quali gia presi 
	int nsol = 0;
	RisolviProdottor(n, s, vcurr, 0,size,usati,&nsol);
	free(usati);
	if (nsol == 0)
	{
		return NULL;
	}
	return vcurr;
}


