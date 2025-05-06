#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct sqmat {
	size_t size;
	bool* data;
};

void colormaprec(const struct sqmat* m, const char* c, char* vcurr, int *numsol,int k)
{
	if (k==m->size)
	{
		for (size_t i = 0; i < m->size; i++)
		{
			for (size_t j = 0; j < m->size; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (vcurr[i] == vcurr[j] && m[i].data[j] == 1)
				{
					return;
				}
			}

		}	
		for (size_t i = 0; i < m->size; i++)
		{
			printf("%zd->%c, ", i, vcurr[i]);
		}
		printf("\n");
		*numsol = *numsol + 1;
		return;

	}




	for (size_t i = 0; i < strlen(c); i++)
	{
		vcurr[k] = c[i];
		colormaprec(m, c, vcurr, numsol, k + 1);
	}

}

int colormap(const struct sqmat* m, const char* c)
{
	int n = m[0].size;
	char* vcurr = calloc(m->size, sizeof(char));
	int nsol = 0;
	colormaprec(m, c, vcurr, &nsol, 0);
	return nsol;
}

void main(void)
{
	struct sqmat* m = malloc(3 * sizeof(struct sqmat));
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
	printf("%d", m[1].data[2]);

	m[2].data[0] = t;
	m[2].data[1] = f;
	m[2].data[2] = t;

	
	char c[] = "rv";

	int nsol=colormap(m, c);


}






