#include<limits.h>

int Divisionerec(int a, int b)
{
	if ((a - b) < b)
	{
		return 1;
	}

	return Divisionerec(a-b,b) + 1;

}

int Divisione(int a, int b)
{
	if (a < b)
	{
		return INT_MAX;
	}
	//controlo per negativi.
	Divisionerec(a, b);

}

void main(void)
{
	int a = 20;
	int b = 3;
	Divisione(a, b);
}