#include"torrecartoni.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int gia_preso(int i,int n,int *vcurr)
{
	for (size_t j = 0; j < n; j++)
	{
		if(vcurr[j]==i)
		{
			return 1;
		}
	}
	return 0;

}
void TorreCartonirec(const Cartone* c, size_t n,int *vcurr,int *v_best,int *altezza_best,int altezza,int i,int peso,int *q )
{

	if (*altezza_best < altezza) {
		*altezza_best = altezza;
		memcpy(v_best, vcurr, n * sizeof(int));
		*q = i;

	}
	if (i == n)
	{
		return;
	}

	for (size_t j = 0; j < n; j++)
	{

	
		if (i>0&& gia_preso(j,n,vcurr))
		{
			continue;
		}
		if (peso>c[j].l)
		{
			continue;
		}

		vcurr[i] = j;

		TorreCartonirec(c, n, vcurr, v_best, altezza_best, altezza+c[j].a, i + 1,peso+c[j].p,q);
	}

}

void TorreCartoni(const Cartone* c, size_t n)
{
	int *vcurr = malloc(n * sizeof(int));
	int* v_best = malloc(n * sizeof(int));
	int altezza_best = 0;
	int q = 0;
	TorreCartonirec(c, n, vcurr, v_best, &altezza_best, 0,0,0,&q);
	for (size_t j = 0; j <q; j++)
	{
		printf("%i", v_best[j]);
		printf("\n");
	}
	printf("Altezza: %dcm", altezza_best);
	free(vcurr);
	free(v_best);
}
