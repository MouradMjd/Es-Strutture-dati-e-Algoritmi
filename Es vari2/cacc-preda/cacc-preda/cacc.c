#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int* caccpredarec(const char* v, size_t v_size, int u,int *vcurr,int*vcurrbest,int *nsol,int *presi_best,int k,int presi)
{
	if (k == v_size)
	{

		for (size_t i = 0; i < v_size; i++)
		{
			if (v[i] == 'C' && vcurr[i]!=-1)
			{
				//if (v[vcurr[i]] == 'P')
				//{
				//	printf("ceck p\n ");
				//}
				int num = i - u;
				//if ((vcurr[i] >= num))
				//{
				//	printf("ceck mag\n ");
				//}
				//if ((vcurr[i] <= i + u))
				//{
				//	printf("ceck min\n");
				//}
				if (v[vcurr[i]] == 'P'&& ((vcurr[i]>=num)&&(vcurr[i] <= i + u)))
				{
					vcurr[vcurr[i]] = -2;
					presi++;
				}
				else
				{
					return;
				}

			}
		}

		for (size_t i = 0; i < v_size; i++)
		{
			printf("|%d| ", vcurr[i]);
		}
		printf("\n");
		*nsol = *nsol + 1;
		if (presi > *presi_best)
		{
			for (size_t i = 0; i <v_size; i++)
			{
				vcurrbest[i] = vcurr[i];
			}
		}
		for (size_t g = 0; g < v_size; g++)
		{
			if (v[g]=='P')
			{
				vcurr[g] = -1;
			}

		}
		return;

	}

	if(v[k]=='P')
	{
		caccpredarec(v, v_size, u, vcurr, vcurrbest, nsol, presi_best, k + 1, presi);
	}
	if(v[k] == 'C')
	{
		int j = -1;
		int s = v_size;
		for ( ;j < s; j++)
		{
			vcurr[k] = j;
			caccpredarec(v, v_size, u, vcurr, vcurrbest, nsol, presi_best, k + 1, presi);
		}
	}



}

int* caccpreda(const char* v, size_t v_size, int u)
{
	int* vcurr = calloc(v_size ,sizeof(int));
	int*vcurrbest= calloc(v_size, sizeof(int));
	for (size_t i = 0; i < v_size; i++)
	{
		vcurr[i]=-1;
	}
	int n_sol = 0;
	int presi_best = 0;
	caccpredarec(v, v_size, u, vcurr, vcurrbest, &n_sol, &presi_best, 0, 0);
	return vcurrbest;
}

void main(void)
{
	char s[] = "CPPCP";
	size_t size = 5;
	int u = 1;
	caccpreda(s, size, u);
}