#include<stdlib.h>
#include<stdio.h>



void hailstonerec(int n,int *s)
{
	*s = *s + 1;
	printf("%d,
		", n);
	if (n == 1)
	{
		return;
	}

	if (n % 2 == 0)
	{
		hailstonerec(n / 2,s);
	}
	else
	{
		hailstonerec((n * 3) + 1,s);
	}


}

size_t hailstone(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	size_t sol = 0;
	hailstonerec(n, &sol);
	return sol;
}



void main(void)
{
	hailstone(5);
}