#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void div_sett(int n)
{
	if (n == 0||n==7)
	{
		printf("Multiplo di 7.");
		return;
	}
	if (n >= 0 && n < 10)
	{
		printf("Non multiplo di 7.");
		return;
	}


	int s = fabs((n / 10) - ((n % 10) * 2));
	div_sett(s);
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

	div_sett(n);


	return 0;
}