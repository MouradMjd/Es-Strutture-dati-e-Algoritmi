#include<math.h>


int Quoziente(size_t x, size_t y)
{
	if (y == 0)
	{
		return -1;
	}
	if (x < y)
	{
		return 0;
	}



	return 1 + Quoziente((x - y), y);

}

int powtwo(int n)
{
	if (n%2!=0||n==0)
	{
		return 0;
	}


	return 1 +powtwo(n/2);


}



void main(void)
{
	Quoziente(10, 3);
	powtwo(100);
}