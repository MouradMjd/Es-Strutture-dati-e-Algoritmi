#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

bool prime(int n,int n1)
{
	if (n <2)
	{
		return false;
	}
	if (n1 == n)
	{
		return true;
	}
	if ((n % n1) == 0)
	{
		return false;
	}


	return prime(n, n1 + 1);

}





int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	bool i = prime(n, 2);
	if (i == false)
	{
		printf("false");
	}
	else
	{
		printf("true");
	}
	return 0;

}