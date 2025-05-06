#include<math.h>

void  inccifrec(int n, int i,int *nc,int r )
{
	if (n==0)
	{
		return;
	}
	int s = pow(10, i);
	int s1 = pow(10, r);
	*nc = *nc + ((n / s) * s1);
	inccifrec(n%s, i - 1, nc,r+1);
}

int  inccif(int n)
{
	int size = 0;
	int n1 = n;
	int nc = 0;
	while (n1 / 10 != 0)
	{
		size++;
		n1 = n1 / 10;
    }
	inccifrec(n, size, &nc,0);


	return nc;
}



void main(void)
{
	inccif(12345678);
}