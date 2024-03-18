#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int passwordrec(char* vett, int* vcurr, int* nsol, int i,int n,int size)
{
	if (i==n)
	{
		for (size_t k = 0; k <n; k++)
		{
			printf("%c", vett[vcurr[k]]);
		}
		printf("\n");
		*nsol=*nsol+1;
		return;
	}


	for (size_t j = 0; j <size; j++)
	{
		vcurr[i] = j;
		passwordrec(vett, vcurr, nsol, i + 1, n,size);
	}


}


int Password(const char* str, int n)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t size = strlen(str);
	char* vett = malloc(size * sizeof(char));

	for (size_t i = 0; i < size; i++)
	{
		vett[i] = str[i];
	}
	int n_sol = 0;
	int* vcurr = calloc(size, sizeof(int));
	 passwordrec(vett, vcurr, &n_sol, 0,n,size);
	 free(vcurr);
	 free(vett);
	 return n_sol;

}



