#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double sen(int x, int i,int n)
{
	if (n>i)
	{
		return 0;
	}
	double v = ((pow(-1, n) / tgamma(2 * n + 2)) * pow(x, (2 * n + 1)));
	return v+ sen(x, i, n + 1);

}





int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return  1;
	}
	char s;
	int x = strtol(argv[1], &s, 0);
	char r;
	int i = strtol(argv[2], &r, 0);

	if (i < 0)
	{
		return 1;
	}


	double n = sen(3,14/x, i,0);

	printf("%f", n);
	return 0;


}