#include<stdlib.h>
#include<math.h>
#include<stdio.h>
float pi(int n)
{
	if (n == 0)
	{
		return 4;
	}

	return ((4 * pow(-1, n)) / ((2 * n) + 1)) + (pi(n - 1));
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
	float p = pi(n);
	printf("%f", p);
	return 0;
}