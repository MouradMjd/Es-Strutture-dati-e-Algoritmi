#include<stdlib.h>
#include<stdio.h>






int CombinaMoneterec(int b, const int* m, size_t m_size,int *vcurr,int i,int som,int *nsol)
{
	if (som > b)
	{
		return;
	}
	if (i == m_size)
	{
		if (som == b)
		{
			*nsol = *nsol + 1;
			for (size_t i = 0; i < m_size; i++)
			{
				printf("%d", vcurr[i]);
			}
			printf(" ");

		}


		return;
	}






	for (size_t j = 0; j <=b; j++)
	{
		vcurr[i] = j;
		CombinaMoneterec(b, m, m_size, vcurr, i+1, som + (m[i] * j), nsol);
	}




}

int CombinaMonete(int b, const int* m, size_t m_size)
{
	int* vcurr = calloc(m_size, sizeof(int));
	int nsol = 0;
	CombinaMoneterec(b, m, m_size, vcurr, 0, 0, &nsol);
	free(vcurr);
	return nsol;
}

