#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int ParoleT9rec(const char* str,int *vcurr,char *vettcar,int i,int l,int n,int sizevcurr,int*nsol)
{
	if (l == n||i==sizevcurr)
	{
		if (l == n)
		{
			for (size_t i = 0; i < sizevcurr; i++)
			{

				if (vcurr[i] == 1)
				{
					printf("%c", vettcar[i]);
				}
			}
			*nsol = nsol++;
			printf("\n");
		}
		return;
	}


		vcurr[i] = 1;
		ParoleT9rec(str, vcurr, vettcar, i + 1, l + 1, n, sizevcurr,nsol);
		vcurr[i] = 0;
		ParoleT9rec(str, vcurr, vettcar, i+1, l,n, sizevcurr,nsol);
		
	
}


int ParoleT9(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t size = strlen(str);
	size_t sizevettcar = 0;
	size_t size2 = 0;
	int mem = 0;;
	char vettcar[3][10];

	char* s0 = "";
	char* s1 = "";
	char* s2 = "ABC";
	char* s3= "DEF";
	char* s4 = "GHI";
	char* s5 = "JKL";
	char* s6 = "MNO";
	char* s7 = "PQRS";
	char* s8 = "TUV";
	char* s9 = "WXYZ";

	strcpy(&vettcar[0],	s0);
	strcpy(&vettcar[1], s1);
	strcpy(&vettcar[2], s2);
	strcpy(&vettcar[2], s2);
	strcpy(&vettcar[3], s3);
	strcpy(&vettcar[4], s4);
	strcpy(&vettcar[5], s5);
	strcpy(&vettcar[6], s6);
	strcpy(&vettcar[7], s7);
	strcpy(&vettcar[8], s8);
	strcpy(&vettcar[9], s9);



	for (size_t i = 0; i < size; i++)
	{
		 char n=str[i];
		 char* s;
		 int f = strtol(&n, &s, 0);
		sizevettcar = sizevettcar + strlen(vettcar[f]);
	}
	char* vett = malloc((sizevettcar * 3) * sizeof(char));
	int* vcurr = calloc(sizevettcar, sizeof(int));
	for (size_t i = 0; i < size; i++)
	{
		char n = str[i];
		char* s;
		int f = strtol(&n, &s, 0);
		if (mem == 0)
		{
			strcpy(vett, vettcar[f]);
			mem = 1;
		}
		else
		{
			strcat(vett, vettcar[f]);
		}
	}
	int nsol = 0;
	ParoleT9rec(str, vcurr, vett, 0,0, size,sizevettcar,&nsol);
	free(vcurr);
	free(vett);
	free(vettcar);

}


void main(void)
{
	char s[] = "54";
	ParoleT9(s);
}