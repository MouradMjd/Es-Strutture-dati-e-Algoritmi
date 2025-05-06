#include<stdlib.h>
#include<stdio.h>

extern void SubsetEqualrec(int n, int s,int i,int*vcurr,int som)
{
	if (som > s)
	{
		return;
	}
	if (i == n||som==s)
	{
		if(som == s)
		{
			printf("{");
			for (size_t j = 0; j < n; j++)
			{
				if (vcurr[j]==1)
				{
					printf(" %d ",(j + 1));
				}
			}
			printf("}");
		}
		return;
	}

	vcurr[i] = 1;
	SubsetEqualrec(n, s, i + 1, vcurr, som = som + (i + 1));
	vcurr[i] = 0;	SubsetEqualrec(n, s, i + 1, vcurr, som=som-(i+1));
}

void SubsetEqual(int n, int s)
{
	if (!(n <= 0 || s <= 0))
	{
		int* vcurr = calloc(n,sizeof(int));
		SubsetEqualrec(n, s, 0, vcurr, 0);
		free(vcurr);
	}
	
}

void main(void)
{
	SubsetEqual(5,7);
}