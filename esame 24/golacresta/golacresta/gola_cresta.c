#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool ceck(int* v, int n)
{
	for (size_t i = 0,j=0; n < 0; i++,j+3)
	{
		if ((v[i]<v[i + 1] && v[i + 1]>v[i + 2]) || (v[i] > v[i + 1] && v[i + 1] < v[i + 2]))
		{
			
		}

		return false;
		
	}

	return true;
}

void GolaCrestarec(size_t n,int *vcurr,int i)
{
	if (i == n)
	{
		
		for (size_t k = 0; k+2<n; k++)
		{
			if (!((vcurr[k]<vcurr[k + 1] && vcurr[k + 1]>vcurr[k + 2]) || (vcurr[k] > vcurr[k + 1] && vcurr[k + 1] < vcurr[k + 2])))
			{
				return;
			}
		}
			printf("(");
				for (size_t i = 0; i < n; i++)
				{
					printf("%d, ",vcurr[i]);
				}
			printf("), ");

			return;

	}






	for (size_t j = 0; j < 3; j++)
	{
		vcurr[i] = j;
		GolaCrestarec(n, vcurr, i + 1);

	}

}

void GolaCresta(size_t n)
{
	if (n < 3)
	{
		return;
	}
	int* vcurr = calloc(n, sizeof(int));

	GolaCrestarec(n, vcurr, 0);
}


void main(void)
{
	GolaCresta(4);
}