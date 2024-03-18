#include<stdlib.h>
#include<stdio.h>


 void SommaKrec(int n, int k,int *vcurr,int somm,int *nsol,int i)
{
	 if (i == n)
	 {
		 int somm1 = 0;
		 for (size_t i = 0; i < n; i++)
		 {
			 if (vcurr[i] == 1)
			 {
				 somm1 = somm1 + (i+1);
			 }
		 }

		 if (somm1 == k)
		 {
			 *nsol = *nsol + 1;
			 printf("{");
			 for (size_t i = 0; i < n; i++)
			 {
				 if (vcurr[i] == 1)
				 {
					 printf("%d, ", i+1);
				 }
			 }
			 printf("} ");
			
		 }
		 return;
	 }



		 vcurr[i] = 1;
		 SommaKrec(n, k, vcurr, somm, nsol, i + 1);
		 vcurr[i] = 0;
		 SommaKrec(n, k, vcurr, somm, nsol, i + 1);
	 


}

extern int SommaK(int n, int k)
{
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	SommaKrec(n, k, vcurr, 0,&nsol,0);
	free(vcurr);
	return nsol;
}



