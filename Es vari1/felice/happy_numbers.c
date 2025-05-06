#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

bool Felice(int n)
{
	int som = 0;
	while (!n/10==0)
	{
		if (n == 0)
		{
			break;
		}
		som = som + pow((n%10),2);
		n = n / 10;
	}
	n = som;
	if (n == 1)
	{
		return 1;
	}
	if (n/10==0)
	{
		return 0;
	}
	

    
	return Felice(n);
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
	bool res=Felice(n);
	if (res == 1)
	{
		printf("Felice");
		return 0;
	}
	if(res==0)
	{
		printf("Infelice");
		return 0;
	}

}