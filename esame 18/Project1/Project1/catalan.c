#include<stdlib.h>
#include<stdio.h>


long long cat(int n)
{
	if (n == 0)
	{
		return 1;
	}

	long long r = 0;
	for (size_t i = 0; i < n; i++)
	{
		r = r +(cat(i) * cat(n - 1 - i));
		
	}
	return r;
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

	long long n1 = cat(n);


	return 1;



}