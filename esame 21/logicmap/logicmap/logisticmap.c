#include<stdlib.h>
#include<math.h>
#include<stdio.h>

double lm(double x,int r,int n,int i)
{
	if (i==n-1)
	{
		return (r * x)*(1 - x);
	}

	return lm((r * x) * (1 - x), r, n, i + 1);
}








int main(int argv, char* argc[])
{
	if (argv != 4)
	{
		return 1;
	}
	char* s;
	double x = strtod(argc[1], &s);
	if (x < 0||x>1)
	{
		return 1;
	}
	char* s1;
	int r = strtol(argc[2], &s, 0);
	if (r < 0)
	{
		return 1;
	}
	char* s2;
	int n = strtol(argc[3], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	

	double q = lm(x, r, n, 0);
	printf("%f", q);

	return 0;



}