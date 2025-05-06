#include<stdio.h>
#include<stdlib.h>



void hail(int n, int* nsol)
{
	if (n == 1)
	{
		*nsol = *nsol + 1;
		printf("1");
		return;
	}


	printf("%d, ", n);
	*nsol = *nsol + 1;
	if (n % 2 == 0)
	{
		n = n / 2;
	}
	else
	{
		n = (3 * n) + 1;
	}

	hail(n, nsol);


}



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return -1;
	}
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n <= 0)
	{
		return 0;
	}

	int nsol = 0;

	hail(n, &nsol);

	return nsol;


}