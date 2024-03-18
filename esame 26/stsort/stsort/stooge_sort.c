#include<stdio.h>
#include<stdlib.h>



void Stoogerec(int* vector, size_t vector_size)
{
	if (vector_size < 2|| vector == NULL)//se il vector_size e <2 torno indietro
	{
		return;
	}
	if (vector[0] > vector[vector_size - 1])//guardo se ultimo eprimo sono swappabili
	{
		int tmp = vector[0];
		vector[0] = vector[vector_size - 1];
		vector[vector_size - 1] = tmp;
	}

	int s1 = 0;
	if (vector_size %3 == 0)
	{
		s1 = (2* vector_size)/3;
	}
	else
	{
		s1= ((2 * vector_size) / 3)+1;
	}

	if (vector_size >= 3)
	{
		Stoogerec(vector, s1);
		Stoogerec(vector + vector_size/3, s1);
		Stoogerec(vector, s1);
	}
		

}


void Stooge(int* vector, size_t vector_size)
{
	if (vector_size == 2)
	{
		if (vector[0] > vector[1])
		{
				int tmp = *vector;
				*vector = vector[vector_size - 1];
				vector[vector_size - 1] = tmp;
		}
		return;
	}

		Stoogerec(vector, vector_size);
	

}


