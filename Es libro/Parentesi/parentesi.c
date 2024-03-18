#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Parentesirec(int n,int *vcurr,int i,int *sol)
{

	if (i==n*2)
	{
		if (vcurr[0] == 0 && vcurr[(n * 2) - 1] == 1)
		{
			for (size_t i = 0; i < n * 2; i++)
			{
				if (vcurr[i] == 0)
				{
					printf("(");
				}
				if (vcurr[i] == 1)
				{
					printf(")");
				}	
			}
			printf("\n");
			*sol=*sol+1;
		}
		return;
	}


	vcurr[i] = 0;
	Parentesirec(n,vcurr,i+1,sol);
	vcurr[i] = 1;
	Parentesirec(n, vcurr, i+1, sol);
	vcurr[i] = 0;



}




int Parentesi(int n)
{
	if (n < 0)
	{
		return -1;
	}
	int * vcurr=malloc((n*2)*sizeof(int));
	
	

	int sol = 0;
	Parentesirec(n, vcurr, 0, &sol);
	return sol;
}


//void main(void)
//{
//	Parentesi(3);
//}