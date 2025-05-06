#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prezzo.h"


void Trovaarticolirec(const struct Articolo* a, size_t size_a, int sum,int *vcurr,int sumcor,int k)
{
	if (k == size_a)
	{
		if (sumcor == sum)
		{
			for (size_t i = 0; i < size_a; i++)
			{
				if (vcurr[i] == 1) 
				{
 					printf("%s, ", a[i].nome);
				}
			}
			printf("\n");
		}
		return;
	}



	vcurr[k] = 1;
	Trovaarticolirec(a, size_a, sum, vcurr, sumcor + a[k].prezzo, k + 1);
	vcurr[k] = 0;
	Trovaarticolirec(a, size_a, sum, vcurr, sumcor, k + 1);
}

void Trovaarticoli(const struct Articolo* a, size_t size_a, int sum)
{
	int* vcurr = calloc(size_a, sizeof(int));
	Trovaarticolirec(a, size_a, sum, vcurr, 0, 0);
}


void main(void)
{
	struct Articolo v[3];
	char n="a";

	strcpy(v[0].nome, "a");
	v[0].prezzo = 1;

	// Copia la stringa nell'array
	strcpy(v[1].nome, "a");
	v[1].prezzo = 3;

	// Copia la stringa nell'array
	strcpy(v[2].nome, "c");
	v[2].prezzo = 2;


	size_t s = 3;
	Trovaarticoli(v, s, 3);
    
}