#include<stdio.h>
#include<stdlib.h>
void hailstonerec(int n,size_t *size)
{
	printf("%d", n);
	if (n != 1)
	{
		printf(", ");
	}
	*size = *size + 1;
	if (n == 1)
	{
		return;
	}
	if (n % 2 == 0)
	{
		n = n / 2;
	}
	else
	{
		n = (3 * n) + 1;
	}
	
	hailstonerec(n, size );
}
size_t hailstone(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	size_t size = 0;
	hailstonerec(n, &size);
	return size;

}

void main(void)
{
	size_t n = hailstone(5);

}