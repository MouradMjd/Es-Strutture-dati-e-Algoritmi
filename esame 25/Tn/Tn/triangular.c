#include<stdio.h>
#include<stdlib.h>



int tr(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 3;
	}


	return (3 * tr(n - 1)) - (3 * tr(n - 2)) + tr(n - 3);

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

	
	int a = tr(n);
	printf("%d", a);
	return 0;




}