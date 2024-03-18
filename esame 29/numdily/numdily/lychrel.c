#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void nsl(int n,int i,int c)
{
	if (i==0)
	{
		printf("Lychrel");
		return;
	}
	int inv = 0;
	int r = 0;
	int n2 = n;
	while (n2 != 0)
	{
		r++;
		n2 = n2 / 10;
	}
	int n1 = n;
	while (n1 != 0)
	{
		inv = inv + (n1 % 10) * pow(10, r - 1);
		n1 = n1 / 10;
		r--;
	}
	if (inv == n)
	{
		printf("Non di Lychrel");
		return;
	}
	if (c == i)
	{
		printf("Lychrel");
		return;
	}



	nsl(n + inv, i ,c+1);


}





int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	int i = strtol(argv[2], &s, 0);
	nsl(n, i,0);
	return 0;
}