#include<stdlib.h>
#include<math.h>


double fattoriale(int n)
{

	if (n == 0)
	{
		return 1;
	}

	return fattoriale(n - 1) * n;

}


double bonomialerec(int n, int k)
{
	if (k == 0 || k == n)
	{
		return 1;
	}
	
	return bonomialerec(n - 1, k - 1) + bonomialerec(n - 1, k);
}

double bonomiale(int n, int k)
{
	if (n == 0 || k > n)
	{
		return -1;
	}
	return bonomialerec(n, k);
}

int  fibonacci(int n)
{
	if (n < 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}


	return fibonacci(n - 1) + fibonacci(n - 2);

}



double senrec(double x, int i)
{
	if (i == 0)
	{
		return x;
	}
	double n = pow(-1, i)* pow(x, 2 * i + 1);
	double d = fattoriale((2 * i) + 1);
	return  (n/d)+senrec(x, i - 1);

}

double sen(double x, int i)
{
	if (i < 0)
	{
		return 0;
	}

	return senrec(x, i,0);


}






void main(void)

{
	double s = fattoriale(4);
	double n = bonomiale(7, 2);
	int c = fibonacci(4);
	int r = sen(2, 2);
}