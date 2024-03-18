#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void Passwordrec(const char* str, int n,char *vcurr,int i,int *nsol,int size)
{
	if (i == n)
	{
		for (size_t i = 0; i < n; i++)
		{
			printf("%c", vcurr[i]);
		}
		printf("\n");
		*nsol = *nsol + 1;
		return;
	}

	


	for (size_t j = 0; j <size; j++)
	{
		vcurr[i] = str[j];
		Passwordrec(str, n, vcurr, i + 1, nsol, size);

	}

}
int Password(const char* str, int n)
{
	if (str == NULL)
	{
		return 0;
	}
	char* vcurr = calloc(n ,sizeof(char));
	int nsol = 0;
	int size = strlen(str);
	Passwordrec(str, n, vcurr, 0, &nsol,size);
	free(vcurr);
	return nsol;

}










