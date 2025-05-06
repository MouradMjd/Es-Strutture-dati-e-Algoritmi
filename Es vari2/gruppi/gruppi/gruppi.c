#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct studente 
{
	char nome[21];

};



bool inizialicons(int* vcurr, struct studente* nomi, int n, int s)
{
	for (size_t i = 0; i < s; i++)
	{
		if (vcurr[i] == 1)
		{
			for (size_t j = i + 1; j < s; j++)
			{
				if (vcurr[j] == 1)
				{
					char* s = nomi[i].nome;
					char* r = nomi[j].nome;

					if ((r[0]==s[0]+1)|| (r[0] ==s[0] -1))
					{
						return false;
					}
				}
			}

		}
	}

	return true;
}



bool iniziali(int* vcurr, struct studente* nomi,int n,int s)
{
	for (size_t i = 0; i < s; i++)
	{
		if (vcurr[i] == 1)
		{
			for (size_t j = i+1; j < s; j++)
			{
				if (vcurr[j] == 1) 
				{
					char* s = nomi[i].nome;
					char* r = nomi[j].nome;
					if (s[0]==r[0])
					{
						return false;
					}
				}
			}

		}
	}

	return true;
}

int Gruppirec(const char* filename, int n,int *vcurr,int size,int k,int pres ,int *nsol,struct studente *nomstud)//se voglio riportare un array di struct 
{
	if (pres==n)
	{

		if (iniziali(vcurr, nomstud, n, size) && inizialicons(vcurr, nomstud, n, size))
		{
			printf("rr");
		}







		return;

	}







	vcurr[k] = 1;
	Gruppirec(filename, n, vcurr,size, k + 1, pres + 1, nsol, nomstud);
	vcurr[k] = 0;
	Gruppirec(filename, n, vcurr,size, k + 1, pres, nsol, nomstud);


}

int Gruppi(const char* filename, int n)
{
	FILE* f= fopen(filename, "r");

	if (!f)
	{
		return 0;
	}
	
	struct studente* stud = NULL;
	int k = 0;
	int lett = 1;
	char j[10];
	for (size_t i = 0; lett != -1; i++)
	{
		
		stud = realloc(stud, sizeof(struct studente) * (k + 1));
		lett = fscanf(f, "%s", stud[i].nome);
		sprintf(j, stud[i].nome, "%s");
		k++;
		if (lett == -1)
		{
			k--;
			break;
		}

	}

	int* vcurr = calloc(k, sizeof(int));
	int nsol = 0;

	Gruppirec("nn", n, vcurr,k, 0,0, &nsol,stud);

	fclose(f);
	free(stud);
}



void main(void)
{
	Gruppi("nome_1.txt", 2);


}
