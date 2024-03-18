#include<string.h>
#include<stdio.h>
#include<stdlib.h>

float logisticmap(float x0, float r, int n)
{

	if (n == 0)
	{
		return x0;
	}
	x0 = (r * x0) * (1 - x0);
	


	logisticmap(x0, r, n - 1);

}








int main(int argv, char* argc[])
{
	if (argv != 4)
	{
		return 1;
	}
	char* s;
	char* v;
	char* h;
	float x0 = strtof(argc[1], &v);
	float r = strtof(argc[2], &s);
	int n = strtol(argc[3], &h, 0);

	if (x0 < 0||x0>1||r<0||n<0)
	{
		return 1 ;
	}
	float xn1 = 0;
	float xn = logisticmap(x0, r, n);
	printf("%f", xn);
	
}