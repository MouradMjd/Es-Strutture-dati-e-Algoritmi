#include<math.h>
#include<stdlib.h>
#include<stdio.h>

void numfel(int n)
{
	if (n == 4||n==0)
	{
		printf("Infelice");
		return;
	}
	if (n == 1)
	{
		printf("Felice");
		return;
	}
	int new = 0;
	while (n!=0)
	{
		new = new + (pow(n % 10, 2));
		n = n / 10;
	}

	numfel(new);
}



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	char* s;
	int n = strtol(argv[1], &s, 0);
	if(n < 0)
	{
		return 1;
	}

	numfel(n);

	return 0;



}