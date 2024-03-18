#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int sc(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return 2;
	}
	int n1 = ((6 * n - 3) * sc(n - 1)) / (n + 1);
	int n2 = ((n - 2) * sc(n - 2)) / (n + 1);
	return (n1 - n2);


}




int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
     }
	char* s;
	int n = strtol(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}
	int n1=sc(n);
	printf("%d", n1);
	return 0;
}