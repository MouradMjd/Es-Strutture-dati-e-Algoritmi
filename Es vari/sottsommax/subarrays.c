#include<stdlib.h>



int cont(int* v,size_t size)
{
	int b = 0;
	int r = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (v[i] == 1 && b == 0)
		{
			b = 1;
			continue;
		}
		if (v[i] == 1 && b == 1&&r==0)
		{
			b = 2;
			r = 1;
		}
		if (v[i] == 0 && b == 2)
		{
			b = 1;
			
		}
		if (v[i] == 1 && b == 1)
		{
			b = 0;
			break;
		}

	}
	return b;
}

 int OptimalSubarrayrec(const int* v, size_t n,int *som,int *vcurr,int i,int *som_best)
{
	 if (i == n)
	 {
		 if ((* som > *som_best)&&(cont(vcurr,n)!=0))
		 {
			 *som_best = *som;
		 }
		 return;
	 }


	 vcurr[i] = 1;
	 *som = *som + v[i];
	 OptimalSubarrayrec(v, n,som , vcurr, i + 1,som_best);
	 vcurr[i] = 0;
	 *som = *som - v[i];
	 OptimalSubarrayrec(v, n, som, vcurr, i + 1,som_best);
}

int OptimalSubarray(const int* v, size_t n)
{
	if (n == 0)
	{
		return 0;
	}

	int* vcurr = calloc(n, sizeof(int));
	int som = 0;
	int som_best = 0;
	OptimalSubarrayrec(v, n, &som, vcurr,0,&som_best);
	free(vcurr);
	return som_best;
}

void main(void)
{
	int v[] = { 1,2,1,-100,5,6};
	OptimalSubarray(v, 6);

}