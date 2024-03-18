#include<stdlib.h>
#include<stdio.h>


int som(int* v,int size)
{
	int s = 0;
	for (size_t i = 0; i <size ; i++)
	{
		s = s + v[i];
	}
	return s;
}
size_t size(int* v, int size)
{
	size_t s = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (v[i] != 0)
		{
			s++;
		}
	}
	return s;
}

void* SolarCutrec(int A, size_t* sol_size,int *vcurr,int i,size_t n)
{
	if (A==0)
	{
		return;
	}



	int r = A / 4;
	if (r==0&&(A%4)!=0)
	{
		r = 1;
	}
	int d = r * r;
	if (d <= A)
	{
		vcurr[i] = d;
		SolarCutrec(A-d, sol_size, vcurr, i + 1,n);
	}
}

int* SolarCut(int A, size_t* sol_size)
{
	if (A % 4 == 0)
	{
		*sol_size = (A / 4) + 1;
	}
	else
	{
		*sol_size = (A / 4) + 2;
	}
	int* vcurr = calloc(*sol_size, sizeof(int));
	SolarCutrec(A, sol_size, vcurr, 0,A);
	return(vcurr);

}


