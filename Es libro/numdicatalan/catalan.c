#include<stdlib.h>
#include<stdio.h>


long long num_catalan(long long n)
{
	if (n == 0 )
	{
		return 1;
	}

	long long result = 0;
	for (size_t i = 0; i < n; i++)//per rapresentare una sommatoria 
	{
		result = result + (num_catalan(i) * num_catalan(n - 1 - i));
	}
	return result;
}





int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	char* s;
	long long n = strtoll(argv[1], &s, 0);
	if (n < 0)
	{
		return 1;
	}

	long long succ = num_catalan( n);
	printf("%d", succ);
	return 0;

}