#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool cons(int* v, int n)
{
	int cons = 0;

	for ( int j = 0; j < n; j++)
	{
		if (v[j] == v[j + 1])
		{
			cons++;
		}
	}

	if (cons == 0)
	{
		return false;
	}
	return true;
}




void Passwordsrec(int n,int *vcurr,int i)
{
	if ((vcurr[i - 1] > vcurr[i]) && (i != 0)&&(i!=n))
	{
		return;
	}
	if (i == n)
	{
		if (cons(vcurr, n))
		{
			for (size_t i = 0; i < n; i++)
			{
				printf("%d", vcurr[i]);
			}
			printf("\n");
		}
		return;
	}





	for (size_t j = 0; j < 10; j++)
	{
		vcurr[i] = j;
		Passwordsrec(n, vcurr, i + 1);
	}


}

void Passwords(int n)
{
	int* vcurr = calloc(n, sizeof(int));
	Passwordsrec(n, vcurr, 0);
	free(vcurr);
}




