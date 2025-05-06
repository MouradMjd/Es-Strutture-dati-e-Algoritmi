#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>

bool prime(int n,int i)
{

	if (n == 0||n==1)
	{
		return false;
	}
	if (i == n)
	{
		return true;
	}
	if (n % i == 0)
	{
		return false;
	}

	prime(n, i + 1);


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
	bool r = prime(n, 2);
	if (r == true)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	

	return 0;
}
