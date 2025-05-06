#include<math.h>

double senrec(double x, int i,int n)
{
	if (n > i)
	{
		return 0;
	}
	double e = ((pow(-1, n) / tgamma(((2 * n) + 2))) * pow(x, ((2 * n) + 1)));
	return e + senrec(x, i ,n+1);

}
double sen(double x, int i)
{
	if (i < 0)
	{
		return-1;
	}
	int n = 0;
	return senrec(x, i,n);
}

void main(void)
{
	double i = sen(4, 2);
	return;
}