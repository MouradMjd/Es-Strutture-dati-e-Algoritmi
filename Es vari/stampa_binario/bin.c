#include<stdlib.h>
#include<stdio.h>
void bin(int n)
{

	int d = 0;
	if (n % 2 != 0)
	{
		d = 1;
	}
	if (n == 0)
	{
		return;
	}


	bin(n / 2);
	
	printf("%d", d);


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
	if (n == 0)
	{
		printf("%d", n);
		return 0;
	}
	bin(n);
	return 0;

}