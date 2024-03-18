#include<stdlib.h>
#include<stdio.h>

extern void GolaCrestarec(size_t n, int i, int* vcurr)
{

	if (i == n )
	{
		int l = 0;
		for (size_t i = 0; i + 2 <= n-1; i++)
		{
			if ((vcurr[i]>vcurr[i + 1] && vcurr[i + 1]<vcurr[i + 2])|| (vcurr[i] < vcurr[i + 1] && vcurr[i + 1] > vcurr[i + 2]))
				{
				l = 1;
				}
			else
			{
				l = 0;
				break;
			}
		}
		if (l == 1)
		{
			printf("(");
			for (size_t i = 0; i < n; i++)
			{
				if (i == n - 1)
				{
					printf("%d", vcurr[i]);
					continue;
				}
				printf("%d, ", vcurr[i]);
				
			}
			printf("), ");
			
		}
	

		return;
	}



	for (size_t j = 0; j < 3; j++)
	{
			vcurr[i] = j;
			GolaCrestarec(n, i + 1, vcurr);
	}

}


void GolaCresta(size_t n)
{
	if (n < 3)
	{
		return;
	}
	int* vcurr = calloc(n, sizeof(int));
	GolaCrestarec(n, 0, vcurr);
	free(vcurr);
}

//void main(void)
//{
//	GolaCresta(4);
//}