#include<stdlib.h>
#include<stdio.h>











double conc(int n)
{
	if (n==0)
	{
		return 0;
	}

	return (0.3 * conc(n - 1)) + 0.2;

}




int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	char *s;
	int n = strtol(argv[1], &s, 0);
	if (n < 1)
	{
		return 1;
	}


	double c = conc(n-1);//faccio il -1 visto che voglio sapere la concentrazione prima della n 
	printf("%f", c);
	return 0;




}