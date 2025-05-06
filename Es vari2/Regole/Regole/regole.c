#include<stdlib.h>
#include<stdio.h>
#include<string.h>





void regolerec(const char* r,int *vcurr,int k,int n)
{
	if (k == n)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (r[j] == 'D' || r[j] == 'd')
			{
				if (vcurr[j] <= vcurr[j + 1])
				{
					return;
				}
			}
			if (r[j] == 'I' || r[j] == 'i')
			{
				if (vcurr[j] >= vcurr[j + 1])
				{
					return;
				}
			}
		}
		printf("{");
		for (size_t k = 0; k < n; k++)
		{
			printf("%d", vcurr[k]);
		}
		printf("}\n");
		return;
	}




	for (int  i = 1; i <= n; i++)
	{
		vcurr[k] = i;
		regolerec(r, vcurr, k + 1, n);
	}

}
void regole(const char* r)
{
	size_t s = strlen(r);
	if (r== NULL||s==0)
	{
		printf("1\n");
	}

	int *vcurr = calloc(s + 1, sizeof(int));
	
	regolerec(r, vcurr, 0,s+1);


}

void main(void)
{
	char s[] = "I";
	regole(s);
}