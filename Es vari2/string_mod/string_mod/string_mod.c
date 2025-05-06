#include<stdio.h>
#include<stdlib.h>




backtackmodrec(int n, int k,char *vcurr,int j)
{
	if (j == n)
	{
		printf("{");
		   for (size_t u = 0; u < n; u++)
		   {
			   printf("%c", vcurr[u]);
		   }
		   printf("} ");

		return;
	}


	for (char i = 'a'; i < 'a'+k; i++)
	{
		vcurr[j] = i;
		backtackmodrec(n, k, vcurr, j + 1);

	}
}

backtackmod(int n, int k)
{
	if (k <= 0 || k > 20 || n <= 0)
	{
		return;
	}
	char* vcurr = calloc(n, sizeof(char));
	backtackmodrec(n, k, vcurr, 0);

}

void main(void)
{
	int n = 3;
	int k = 2;
	backtackmod(n, k);
}