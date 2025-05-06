#include<stdio.h>
#include<stdlib.h>

int numleo(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}

	return numleo(n - 1)+ numleo(n - 2)+1;
}






int main(int argc,char* argv[])
{
	if ( argc!= 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	for (size_t i = 0; i <= n; i++)
	{
		printf("%d, ", numleo(i));
	}
	numleo(n);
	return 0;


}