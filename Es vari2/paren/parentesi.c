#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int view(char *v,int n)
{
	int balance = 0;
	int c = 0;
	int s = 0;

	for (size_t i = 0; i < n*2; i++)
	{
		if (v[i] == '(')
		{
			balance++;
			c++;
		}
		if (v[i] == ')')
		{
			balance--;
			s++;
		}
		if (balance < 0)
		{
			return 0;
		}
	}
	if (s==n&&c==n)
	{
		return 1;
	}
	return 0;

}



void Parentesir(int n,char *vcurr,int i,char *s,int *nsol)
{
	if(i==(n*2))
	{
		if (view(vcurr,n)==1&&(vcurr[0]=='('&& vcurr[n*2-1] == ')'))
		{
			for (size_t i = 0; i < (n*2); i++)
			{
				printf("%c", vcurr[i]);

			}
			printf("\n");
			*nsol = *nsol + 1;
		}
		return;
	}





	for (size_t j = 0; j < 3; j++)
	{
		vcurr[i] = s[j];
		Parentesir(n, vcurr, i + 1, s,nsol);
	}
}

int Parentesi(int n)
{
	if (n < 0)
	{
		return -1;
	}
	char* vcurr = calloc(n*2, sizeof(char));
	char* s = "()";
	int nsol = 0;
	Parentesir(n, vcurr, 0,s,&nsol);
	free(vcurr);
	return nsol;
}
void main(void)
{
	int n = 4;
	Parentesi(n);
}

