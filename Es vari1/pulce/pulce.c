#include<stdlib.h>
#include<string.h>
#include<limits.h>

int saltiind(int *v,int n)
{
	int s = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (v[i] == 0 && s == 0)
		{
			s = 1;	
			continue;
		}
		if (v[i] == 0 && s == 1)
		{
			s = 2;
			break;
		}
		if (v[i] == 1 && s == 1)
		{
			s = 0;
		}

	}
	return s;
}

extern int* GuidaLaPulcerec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size,int i,int sol,int *solbest,int *vcurrbest,int *vcurr,int som)
{
	if (i == n)
	{
		return;
	}
	for (size_t r = 0; r < i; r++)
	{
		if (vcurr[r] == 1)
		{
			som = som + a;
			if (som < 0)
			{
				return;
			}
			for (size_t i = 0; i < f_size; i++)
			{
				if (som == f[i])
				{
					return;
				}
			}
		}
		else
		{
			som = som - b;
			if (som<0)
			{
				return;
			}
			for (size_t i = 0; i < f_size; i++)
			{
				if (som == f[i])
				{
					return;
				}
			}
		}
	}

	if (i==n||som==h)
	{
		if ((i < *solbest)&&(saltiind(vcurr,i)!=2)&&(som==h))
		{
			*solbest = i;
			memcpy(vcurrbest, vcurr, n);
		}
		return;
	}

	for (size_t j = 0; j < 2; j++)
	{
		vcurr[i] = j;
		GuidaLaPulcerec(f, f_size, a, b, n, h, ret_size, i+1, sol, solbest,vcurrbest, vcurr, 0);
	}
	*ret_size=*solbest;
}


extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size)
{
	int* vcurr = calloc(n, sizeof(int));
	int* vcurrbest = calloc(n, sizeof(int));
	int sol_best = INT_MAX;
	int i = 0;
	GuidaLaPulcerec(f, f_size, a, b, n, h, ret_size, 0, 0, &sol_best, vcurrbest, vcurr,0);
	char* vb = malloc(sol_best * sizeof(char));
	if (sol_best == INT_MAX)
	{
		vb = NULL;
		sol_best = 0;
	}
	for (size_t i = 0; i < sol_best; i++)
	{
		if (vcurrbest[i] == 1)
		{
			vb[i] = 'a';
		}
		else
		{
			vb[i] = 'b';
		}
	}
	free(vcurr);
	free(vcurrbest);
	*ret_size = sol_best;
	return vb;
}

void main(void)
{

	int f[] = { 12, 4, 7, 1, 15 };
	size_t r = 0;
	char *s=GuidaLaPulce(f, 5, 3, 15, 5, 9,&r);
}