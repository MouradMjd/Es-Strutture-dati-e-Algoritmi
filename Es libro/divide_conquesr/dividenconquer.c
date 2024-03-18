#include<string.h>
#include<stdlib.h>
#include<stdio.h>




int div_con(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n==1)
	{
		return 1;
	}




	return div_con(n / 2) + div_con(n / 2) + n;
}

int main(int argv, char* argc[])
{

	if (argv != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argc[1], &s, 0);
	int c= div_con(n);
	printf("%d", c);
	return 0;
}