#include<stdlib.h>
#include<stdio.h>

float somm_farmaco(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return (0.3 * somm_farmaco(n-1)) + 0.2;

}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n < 1)
	{
		return 1;
	}
	float conc=somm_farmaco(n-1);
	printf("%f", conc);
	return 0;


}