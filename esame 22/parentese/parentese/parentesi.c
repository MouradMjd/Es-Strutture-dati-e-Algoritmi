#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool cek(char *v,int size)
{
	int a = 0;
	 
	for (size_t i = 0; i < size; i++)
	{
		if (v[i] == '(')
		{
			a++;
		}
		if (v[i] == ')')
		{
			a--;
		}
		if (a < 0)
		{
			return false;
		}

	}

	if (a != 0)
	{
		return false;
	}


	return true;



}



void Parentesirec(int n,char *vcurr,int *nsol,int i,char *v)
{
	if (i == (n * 2))
	{
		if (cek(vcurr, n * 2))
		{
			for (size_t i = 0; i < n*2; i++)
			{
				printf("%c", vcurr[i]);
			}
			printf("\n");
			*nsol = *nsol + 1;
		}
		return;

	}


	for (size_t j = 0; j < 2; j++)
	{
		vcurr[i] = v[j];
		Parentesirec(n, vcurr, nsol, i+1, v);
	}




}
int Parentesi(int n)
{
	if (n < 0)
	{
		return -1;
	}
	char* vcurr = calloc(n * 2, sizeof(char));
	char *v= calloc(2,sizeof(char));
	v[0] = '(';
	v[1] = ')';
	int sol = 0;
	Parentesirec(n, vcurr, &sol, 0, v);
	free(vcurr);
	free(v);
	return sol;
}




