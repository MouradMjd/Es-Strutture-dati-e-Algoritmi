#include<stdlib.h>
#include<stdio.h>


void radicenumerica(int n)
{
	if (n < 10)//caso base in cui arriviamo ad avere una som ad una singola cifra.
	{
		printf("%d", n);
		return n;
	}
	else
	{
		int sum = 0;//definisco sum
		while (n != 0)//calcolo la sum
		{
			sum = sum + (n % 10);
			n = n / 10;
		}
		radicenumerica(sum);//richiamo la ricorsione su sum che diventa il nuovo n
	}

}


int main(int argv, char* argc[])
{
	if (argv != 2)
	{
		return 1;
	}
	char* s;
	int n = strtol(argc[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	radicenumerica(n);
	return 0;

}