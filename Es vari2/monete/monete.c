#include<stdio.h>
#include<stdlib.h>


void CombinaMoneter(int b, const int* m, size_t m_size,int *vcurr,int sum,int i,int *nsol)
{
	if (sum > b)
	{
		return;
	}
	if (i == m_size)
	{
		if (sum == b)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				printf("%d ", vcurr[i]);
			}
			printf("\n");
			*nsol = *nsol + 1;
		}
		
		return;
	}





	for (size_t n = 0; n < b+1; n++)
	{
		vcurr[i] = n;
		int s = m[i] * n;
		CombinaMoneter(b, m, m_size, vcurr, sum + s, i + 1,nsol);
	}

}



int CombinaMonete(int b, const int* m, size_t m_size)
{
	int* vcurr = calloc(m_size, sizeof(int));
	int nsol = 0;
	CombinaMoneter(b, m, m_size, vcurr, 0, 0,&nsol);
	free(vcurr);
	return nsol;
	
}



