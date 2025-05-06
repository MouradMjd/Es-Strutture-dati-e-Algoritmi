#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

bool power4(int n,int *i)
{
	if (n == 1)
	{
		return true;
	}
	if (n % 4 != 0)
	{
		return false;
	}

	*i = *i + 1;
	return power4(n / 4,i);
}





int main(int argv, char* argc[])
{
	if (argv != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argc[1], &s, 0);
	int i = 0;
	bool so=power4(n, &i);
	if (so == true)
	{
		printf("4^%d = %d", i,n);
	}
	else
	{
		printf("!p4");
	}
	return 0;
}