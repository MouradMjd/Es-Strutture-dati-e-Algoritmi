#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int i, int som, int* vcurr, int* nsol, int pa, int* vbest, int pa_best, int som_best)
{
	if (i == pacchi_size)
	{
		if (som <= p)
		{
			if (pa > pa_best && som > som_best)
			{
				for (size_t j = 0; j < pacchi_size; j++)
				{
					vbest[j] = vcurr[j];
				}
				pa_best = pa;
				som_best = som;
			}
		}

		return;

	}

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, som + pacchi[i], vcurr, nsol, pa + 1, vbest, pa_best, som_best);

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, som, vcurr, nsol, pa, vbest, pa_best, som_best);






}




void BabboNatale(const int* pacchi, size_t pacchi_size, int p)
{
	int* vcurr = calloc(pacchi_size, sizeof(int));
	int* vbest = calloc(pacchi_size, sizeof(int));
	int nsol = 0;
	int som = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, som, vcurr, &nsol, 0, vbest, 0, 0);
	for (size_t j = 0; j < pacchi_size; j++)
	{
		printf("%d ", vbest[j]);
	}
	free(vcurr);
}

void main(void)
{
	int p = 20;
	int pacchi[] = { 10, 11, 1, 3, 3 };
	BabboNatale(pacchi, 5, p);
}