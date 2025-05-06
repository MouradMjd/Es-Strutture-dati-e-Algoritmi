#include"prezzo.h"
#include<stdlib.h>
#include<stdio.h>


extern void TrovaArticolirec(const struct Articolo* a, size_t a_size, 
	int sum,int i,int *vcurr,int somnow)
{
	if (i == a_size)
	{
		if (somnow == sum)
		{
			for (size_t k = 0; k < a_size; k++)
			{
				if (vcurr[k] == 1)
				{
					printf("%s, ", a[k].nome);
				}

			}
			printf("\n");
		}
		return;
	}

	vcurr[i] = 1;
	TrovaArticolirec(a, a_size, sum, i + 1, vcurr, somnow+ a[i].prezzo);//rimane costante
	vcurr[i] = 0;
	TrovaArticolirec(a, a_size, sum, i + 1, vcurr, somnow);
	
}
extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum)
{

		int* vcurr = calloc(a_size, sizeof(int));
		TrovaArticolirec(a, a_size, sum, 0, vcurr, 0);
		free(vcurr);

}

