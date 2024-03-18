#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void ParoleT9rec(const char* str,char *vcurr,size_t size,int i,int n,int *nsol,bool *pres)
{
	if (i == n)
	{
		*nsol = *nsol+1;
		for (size_t i = 0; i < n; i++)
		{
			printf("%c", vcurr[i]);
		}
		printf("\n");
		return;
    }


	for (size_t j = 0; j < size; j++)
	{
		if (pres[j] == false)
		{
			vcurr[i] = str[j];
			pres[j] = true;
			ParoleT9rec(str, vcurr, size, i + 1, n, nsol, pres);
			pres[j] = false;
		}
	}

}
int ParoleT9(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t s = strlen(str);
	int* vcurr = calloc(2 , sizeof(char));
	bool* pres = calloc(s, sizeof(bool));
	int nsol = 0;
	ParoleT9rec(str, vcurr, s, 0, 2, &nsol,pres);
	free(vcurr);
	return nsol;
}




