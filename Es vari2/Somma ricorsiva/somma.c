#include"somma.h"

int sommarec(int n)
{
	//caso base
	if (n == 1)
	{
		return 1;
	}
	//ricorsione
	return somma(n - 1) + n;

}
int somma(int n)
{
	//caso particolare 
	if (n <= 0)
	{
		return -1;
	}
	return sommarec(n);
}


void main(void)
{
	int n = 2;
	int i = somma(n);
}