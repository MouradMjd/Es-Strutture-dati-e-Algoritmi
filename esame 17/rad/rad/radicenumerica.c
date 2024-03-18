#include<stdio.h>
#include<stdlib.h>


int radn(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n;
	}


	int n1 = 0;
	while (n!=0)
	{
		n1 = n1 + n % 10;
		n = n / 10;
	}

	return radn(n1);
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
	int w = radn(n);
	printf("%d", w);
	return 0;
}