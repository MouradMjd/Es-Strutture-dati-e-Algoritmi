#include<stdlib.h>
#include<stdio.h>




void tiro_funerec(int n, int* num_interi, int* vcurr, int* vcurr1,int *vcurr2,int *vbest1,int *vbest2,int *diff_best,int nump,int i,int diff,int som1,int som2)
{
	if (nump == n / 2)
	{
		for (size_t j = 0,v1=0,v2=0; j < n; j++)
		{
			if (vcurr[j])
			{
				vcurr1[v1] = num_interi[j];
				v1++;
			}
			else
			{
				vcurr2[v2] = num_interi[j];
				v2++;
			}
		}
		for (size_t d = 0; d < n / 2; d++)
		{
			som1 = som1 + vcurr1[d];
		}
		for (size_t l = 0; l < n - n / 2; l++)
		{
			som2 = som2 + vcurr2[l];
		}
		if (som1 < 0)
		{
			som1 = -som1;
		}
		if(som2<0)
		{
			som2 = -som2;
		}

		diff = som1 - som2;

		if (diff < 0)
		{
			diff = -diff;
		}
		if (diff < *diff_best)
		{
			for (size_t s = 0; s < n/2; s++)
			{
				vbest1[s] = vcurr1[s];
			}
			for (size_t q= 0; q < n-n/2; q++)
			{
				vbest2[q] = vcurr2[q];
			}
			*diff_best = diff;
		}
		return;
	}


	if (i ==n)
	{
		return;
	}



	vcurr[i] = 0;
	tiro_funerec(n, num_interi, vcurr, vcurr1, vcurr2, vbest1, vbest2, diff_best, nump,i+1,diff,som1,som2);
	vcurr[i] = 1;
	tiro_funerec(n, num_interi, vcurr, vcurr1, vcurr2, vbest1, vbest2, diff_best, nump+1, i+1,diff,som1,som2);
	vcurr[i] = 0;

}


void tiro_fune(int n,int *num_interi,int somtot)
{
	int* vcurr = calloc(n, sizeof(int));
	int* vcurr1 = malloc(n / 2 * sizeof(int));
	int* vcurr2 = malloc((n - n/2) * sizeof(int));
	int* vbest1 = malloc(n / 2 * sizeof(int));
	int* vbest2= malloc((n - n / 2) * sizeof(int));
	int* diff_best = somtot;
	
	tiro_funerec( n,num_interi,vcurr,vcurr1,vcurr2,vbest1,vbest2,&diff_best,0,0,0,0,0);
		
	printf("{ ");
		for (size_t i = 0; i<(n/2); i++)
		{
			printf("%d, ",vbest1[i]);
		}
	printf("}, ");

	printf("{ ");
	for (size_t i = 0; i < (n - n / 2); i++)
	{
		printf("%d, ", vbest2[i]);
	}
	printf("},");
	return;
}

int main(int argc, char * argv[])
{
	int* num_int = malloc((argc - 1) * sizeof(int));
	char* fine;
	int somtot = 0;
	for (size_t i = 1,h=0; i <= (argc-1); i++,h++)
	{
		int j = strtol(argv[i], &fine, 10);
		num_int[h] = j;
		somtot = somtot + j;
	}
	tiro_fune((argc - 1), num_int,somtot);
	return;
}