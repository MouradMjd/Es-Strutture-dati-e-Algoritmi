#include<stdio.h>
#include<stdlib.h>


double lm(double x0, double n, double r,int i)
{
	if (i == n-1)
	{
		return r * x0 * (1 - x0);
	}

	double x1 = r * x0*(1 - x0);
	lm(x1, n, r, i + 1);
	
}


int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		return 1;
	}

	char* s;
	double x = strtod(argv[1], &s);
	double r = strtod(argv[2], &s);
	double n = strtod(argv[3], &s);

	double s1 = lm(x, n, r,0);



	return 0;


}