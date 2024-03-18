#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

 void ValidTimesrec(uint8_t n,int i,int *vcurr,int *ore,int *min,int size,uint8_t numled)
{
	 if (numled == n)
	 {
		 int sumore = 0;
		 int summin = 0;
		 size_t i;
		 for ( i = 0; i < size/2; i++)
		 {
			 if (vcurr[i] == 1)
			 {
				 sumore = sumore + ore[i];
			 }
		 }
		 for (int j=0;i<size;i++,j++)
		 {
			 if (vcurr[i]==1)
			 {
				 summin = summin + min[j];
			 }
		 }
		 if (sumore <= 23 && summin <= 59)
		 {
			 if (sumore / 10 != 0)
			 {
				 printf("%d:", sumore);
			 }
			 else
			 {
				 printf("0%d:", sumore);
			 }
			 if (summin / 10 != 0)
			 {
				 printf("%d, ", summin);
			 }
			 else
			 {
				 printf("0%d, ", summin);
			 }
		 }
	
		 return;
		 
	 }
	 if (i == size)
	 {
		 return;
	 }



	 vcurr[i] = 1;
	 ValidTimesrec(n, i + 1, vcurr, ore, min, size, numled = numled + 1);
	 vcurr[i] = 0;
	 ValidTimesrec(n, i + 1, vcurr, ore, min, size,numled=numled-1);
	

}

extern void ValidTimes(uint8_t n)
{
	if (!(n > 11)&&!(n<0))
	{
		int ore[] = { 16,8,4,2,1 };
		int min[] = { 32,16,8,4,2,1 };
		int* vcurr = calloc(11, sizeof(int));
		ValidTimesrec(n, 0, vcurr, ore, min, 11, 0);
		free(vcurr);
	}


}

//void main(void)
//{
//	uint8_t n = 9
//		;
//	ValidTimes(n);
//}