#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void happy(int n, bool* i)
{
	if (n == 1)
	{
		*i = true;
		return;
	}
	if ((n / 10)==0)
	{
		return;
	}
	int som = 0;
	while (n!=0)
	{
		som = som + pow((n % 10),2);
		n = n / 10;
	}
	happy(som, i);

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

	bool i = false;
	happy(n, &i);
	if (i == false)
	{
		printf("Infelice");
	}
	else
	{
		printf("Felice");
	}
	return 0;
}