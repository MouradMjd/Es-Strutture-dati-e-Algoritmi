#include<stdio.h>
#include<stdlib.h>


int dc(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	return dc(n / 2) + dc(n / 2) + n;
}





int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	char s;
	int n = strtol(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}

	int a = dc(n);
	printf("%d", a);


	return 0;


}