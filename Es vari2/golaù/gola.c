#include<stdlib.h>
#include<stdio.h>



void golacrestar(size_t n,int *vcurr,int i,int num)
{
	if (i==n)
	{
		for (size_t k = 0; k < n-2; k++)
		{
			if (!((vcurr[k]<vcurr[k + 1] && vcurr[k + 1]>vcurr[k + 2]) || (vcurr[k] > vcurr[k + 1] && vcurr[k + 1] < vcurr[k + 2])))
			{
				return;
		    }
		}
		printf("(");
		for (size_t e = 0; e < n; e++)
		{
			if (e != n - 1)
			{
				printf("%d,", vcurr[e]);
			}
			else
			{
				printf("%d", vcurr[e]);
			}
			
		}
		printf(") ");
		return;

	}

	for (size_t j = 0; j < num; j++)
	{
		vcurr[i] = j;
		golacrestar(n, vcurr, i + 1, num);
	}

}
void golacresta(size_t n)
{
	if (n < 3)
	{
		return;
	}
	int* vcurr = calloc(n, sizeof(int));
	golacrestar(n, vcurr, 0, 3);


}

int main(void)
{
	int n = 4;
	golacresta(n);
}