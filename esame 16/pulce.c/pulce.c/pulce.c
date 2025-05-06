#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

bool pospro(int s,int *v,size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (s == v[i])
		{
			return false;
		}

	}
	return true;
}

bool ck(int* v, int size,int n,size_t *pas,int b,int *pos,size_t s_pos)
{
	int som = 0;
	int s = 0;
	size_t pass = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (v[i] != 0)
		{
			pass++;
		}
		if (v[i] == b )
		{
			s++;
		}
		if (s == 2)
		{
			return false;
		}
		if (s > 0 || v[i] != b)
		{
			s--;
		}
		som = som + v[i];
		if (som < 0)
		{
			return false;
		}
		if (pospro(som, pos, s_pos) == false)
		{
			return false;
		}
	}
	*pas = pass;
	if (som == n)
	{
		return true;
	}
	return false;
}

char* GuidaLaPulcerec(const int* f, size_t f_size,
	int a, int b, int n,
	int h, size_t* ret_size, int* vcurr, int** vbest, int* pass,
	int i,int som)
{
	if(i==n||som==h)
	{
		size_t pass = 0;
		bool c = ck(vcurr, n, h, &pass,b,f,f_size);
		if (c == true)
		{
			if (pass < *ret_size)
			{
				for (size_t i = 0; i < n; i++)
				{
					vbest[0][i] = vcurr[i];
				}
				*ret_size = pass;
			}
		}
		return;
	}
	if (vcurr[i - 1] == b && vcurr[i] == b)
	{
		return;
	}

	for (size_t j = 0; j < 2; j++)
	{
		vcurr[i] = pass[j];
		GuidaLaPulcerec(f, f_size, a, b, n, h, ret_size, vcurr, vbest, pass, i + 1,som+pass[j]);
		vcurr[i] = 0;
		GuidaLaPulcerec(f, f_size, a, b, n, h, ret_size, vcurr, vbest, pass, i + 1, som);
	}




}
char* GuidaLaPulce(const int* f, size_t f_size,
	int a, int b, int n,
	int h, size_t* ret_size)
{
	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));
	int* pass = calloc(2, sizeof(int));
	pass[0] = a;
	pass[1] = -b;
	size_t s = UINT64_MAX ;
	GuidaLaPulcerec(f,f_size,a,b,n,h,&s,vcurr,&vbest,pass,0,0);
	if (s == UINT64_MAX)
	{
		*ret_size = 0;
		return NULL;
	}
	*ret_size = s;
	char* vett = calloc(s, sizeof(char));
	for (size_t i = 0,j=0; i < n; i++)
	{
		if (vbest[i] != 0)
		{
			if (vbest[i] == a)
			{
				vett[j] = 'a';
				j++;
		    }
			else
			{
				vett[j] = 'b';
				j++;
			}
	    }
	}
	free(vcurr);
	free(vbest);
	free(pass);
	return vett;

}


