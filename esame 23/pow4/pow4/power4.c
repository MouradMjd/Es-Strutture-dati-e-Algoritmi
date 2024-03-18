#include<stdlib.h>
#include<stdio.h>

void  pow4(int n,int *s)
{
	if (n == 1)
	{
		return;
	}
	if (n % 4 != 0)
	{
		*s = 0;
		return;
	}
	*s = *s + 1;
	pow4(n / 4,s);
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
	if (n == 0)
	{
		printf("4^0 = 1");

	}
	else
	{
		int r = 0;

		pow4(n, &r);
		if (r == 0)
		{
			printf("!p4");
		}
		else
		{
			printf("4^%d = %d", r, n);
		}
	}


	return 0;

}