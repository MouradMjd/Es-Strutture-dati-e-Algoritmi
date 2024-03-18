#include<stdlib.h>
#include<stdio.h>

int triangnum(int n)
{

	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 3;
	}

	return 3 * triangnum(n - 1) - 3 * triangnum(n - 2) + triangnum(n - 3);
	
}


int main(int argv, char *argc[])
{
	if (argv != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argc[1],&s, 0);
	if (n < 0)
	{
		return 1;
	}
	int sn1 = triangnum(n);
	printf("%d",sn1);
	
}