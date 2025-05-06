#include<stdio.h>
#include<stdlib.h>

void subsetsummrec(int n, int s,int *vcurr,int *numsol,int k,int som)
{
	if (som == s||k==n)
	{
		if (som == s)
		{
			printf("{");
			for (size_t j = 0; j < n; j++)
			{
				if (vcurr[j] == 1)
				{
					printf("%d", j+1);
				}
				
			}
			printf("}");
		}
		return;
	}



	vcurr[k] = 1;
	subsetsummrec(n, s, vcurr, numsol, k + 1, som + (k+1));
	vcurr[k] = 0;
	subsetsummrec(n, s, vcurr, numsol, k + 1, som);

}


int subsetsumm(int n, int s)
{
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	subsetsummrec(n, s, vcurr, &nsol,0,0);
}


void main(void)
{
	int n = 4;
	int s = 6;
	subsetsumm(n, s);

}