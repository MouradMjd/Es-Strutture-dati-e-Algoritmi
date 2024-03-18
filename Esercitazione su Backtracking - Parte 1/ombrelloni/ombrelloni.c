#include<stdlib.h>
#include<stdio.h>

void Ombrellonirec(int k, int n,int *vcurr,int i,int *nsol,int num_rag )
{
	if (num_rag > 2)
	{
		return;
	}

	if (i == n)
	{
		if (k != 0||num_rag!=2)
		{
			return;
		}
		for (size_t j = 0; j < n;j++)
		{
			printf("%d", vcurr[j]);
		}
		printf("\n");
		*nsol = *nsol + 1;
		return;
	}

	vcurr[i] = 0;
	Ombrellonirec(k, n, vcurr, i + 1, nsol ,num_rag);
	vcurr[i] = 1;
	if ((vcurr[i - 1] == 1) && (vcurr[i] == 1))
	{
		vcurr[i] = 0;
		num_rag = num_rag - 1;
	}
	Ombrellonirec(k - 1, n, vcurr, i + 1, nsol,num_rag+1);

}


int Ombrelloni(int k, int n)
{
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	Ombrellonirec(k, n, vcurr, 0, &nsol,0);
	return nsol;
}


