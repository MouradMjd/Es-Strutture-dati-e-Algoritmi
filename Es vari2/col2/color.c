#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct sm {
	size_t size;
	bool * data;
};



int colormapr(const struct sm* m, const char* c,char *vcurr,int *nsol,int n,int size)
{

	if (n==m->size)
	{
		for (size_t j = 0; j < size; j++)
		{
			for (size_t g = 0; g < size; g++)
			{
				if (vcurr[j] == vcurr[g] && m[j].data[g] == 1&&j!=g)//fermi uno dei dati nella vcurr lo vai a comparare con gli altri se sono uguali vedi se sono adiacenti 
				{
					return;
				}
			}
		}
		*nsol = *nsol + 1;
		for (size_t k = 0; k < size ; k++)
		{
			printf("%c ", vcurr[k]);
		}
		printf("\n");
		return;
		
	}





	for (size_t i = 0; i < strlen(c); i++)
	{
		vcurr[n] = c[i];
		colormapr(m, c, vcurr, nsol, n + 1,size);
	}


}


int colormap(const struct sm* m, const char* c)
{
	char* vcurr = calloc(m[0].size, sizeof(char));
	int nsol = 0;
	int size = m->size;
	colormapr(m, c, vcurr, &nsol, 0,size);
	return nsol;
}

void main(void)
{
	struct sm* m = malloc(3 * sizeof(struct sm));
	m[0].size = 3;
	m[1].size = 3;
	m[2].size = 3;
	m[0].data = malloc(m[0].size * sizeof(bool));
	m[1].data = malloc(m[1].size * sizeof(bool));
	m[2].data = malloc(m[2].size * sizeof(bool));
	int t = 1;
	int f = 0;
	m[0].data[0] = t;
	m[0].data[1] = t;
	m[0].data[2] = t;

	m[1].data[0] = t;
	m[1].data[1] = t;
	m[1].data[2] = f;


	m[2].data[0] = t;
	m[2].data[1] = f;
	m[2].data[2] = t;


	char c[] = "rv";


	int s=colormap(m, c);


}