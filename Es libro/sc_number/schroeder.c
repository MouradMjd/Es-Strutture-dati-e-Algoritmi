#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sch_num(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return 2;
	}
	return (((6 * n) - 3) * (sch_num(n - 1)) / (n + 1)) - ((n - 2) * (sch_num(n - 2)) / (n + 1));
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

	int succ= sch_num(n);

	printf("%d", succ);
	return 0;

}