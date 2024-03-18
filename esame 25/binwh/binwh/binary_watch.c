#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

bool ceck(int* v, int* vcurr,int size )
{
	int so = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (vcurr[i] == 1)
		{
			so = so + v[i];
		}

	}
	if (so > 23)
	{
		return false;
	}
	int sm = 0;
	for (size_t i = 5; i < 11; i++)
	{
		if (vcurr[i] == 1)
		{
			sm = sm + v[i];
		}

	}
	if (sm > 59)
	{
		return false;
	}


	return true;

}



void ValidTimesrec(uint8_t n,int i,int *vcurr,int lp,int *vl,int size)
{
	if (i == 11)
	{
		int lp1= 0;

		if (lp == n)
		{
			if (ceck(vl, vcurr, size))
			{

					int so = 0;
					for (size_t i = 0; i < 5; i++)
					{
						if (vcurr[i] == 1)
						{
							so = so + vl[i];
						}
					}
					printf("%d", so);

				printf(":");

					int sm = 0;
					for (size_t i = 5; i < 11; i++)
					{
						if (vcurr[i] == 1)
						{
							sm = sm + vl[i];
						}
					}
					printf("%d", sm);
			
			}
			printf(" ");
		}
		return;

	}






	vcurr[i] = 1;
	ValidTimesrec(n, i + 1, vcurr, lp+1, vl, size);
	vcurr[i] = 0;
	ValidTimesrec(n, i + 1, vcurr, lp, vl, size);
}


void ValidTimes(uint8_t n)
{
	int vl[] = {16,8,4,2,1,32,16,8,4,2,1};
	int* vcurr = calloc(11, sizeof(int));
	int size = 11;
	ValidTimesrec(n, 0, vcurr, 0, vl, 11);
}




void main(void)
{
	ValidTimes(3);
}