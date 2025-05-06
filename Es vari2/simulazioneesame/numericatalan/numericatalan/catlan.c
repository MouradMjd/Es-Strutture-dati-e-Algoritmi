#include<stdio.h>
#include<stdlib.h>

long long cata(int n)
{
	if (n == 0)
	{
		return 1;
	}

	long long som = 0;
	for (size_t i = 0; i < n; i++)
	{
	som = som + (cata(i) * cata(n - 1 - i));
	}
	return som;
}


int main(int argc,char* argv[])
{

	char* s = 0;
	int n = strtol(argv[1], &s, 0);
	long long r = cata(n);


}