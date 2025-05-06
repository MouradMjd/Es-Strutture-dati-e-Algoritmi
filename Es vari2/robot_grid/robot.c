#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Grid {
	size_t rows, cols;
	int* cell;
};


int print(const struct Grid* g)
{






}

int findpathr(const struct Grid* gcurr,int r,int c,int size,int *nsol,int nstep)
{

	if (r ==gcurr->rows - 1 && c ==gcurr->cols - 1)//caso base
	{
		*nsol = *nsol + 1;
		printf("sol:\n");
		printtgrid(gcurr);
    }
	


	int next_index = (r + 1) * gcurr->cols+c;
	if (r < gcurr->rows - 1 && gcurr->cell[next_index] != -1)
	{
		gcurr->cell[next_index] = nstep;
		findpathr(gcurr, r+1, c, size, nsol, nstep + 1);
		gcurr->cell[next_index] = 0;
	}

	next_index = (r)*gcurr->cols+c+1;
	if (c < gcurr->cols - 1 && gcurr->cell[next_index] != -1)
	{
		gcurr->cell[next_index] = nstep;
		findpathr(gcurr, r, c+1, size, nsol, nstep + 1);
		gcurr->cell[next_index] = 0;
	}



}

int findpath(const struct Grid* g)
{

	int* vcurr = calloc((g->cols * g->rows), sizeof(int));
	for (size_t i = 0; i < (g->cols * g->rows); i++)
	{
		vcurr[i] = g->cell[i];
	}
	struct Grid gcurr = { .rows = g->rows,
						.cols = g->cols,
						.cell = calloc((g->cols * g->rows), sizeof(int)),
	};
	int nsol;
	memcpy(gcurr.cell, vcurr, (g->cols * g->rows), sizeof(int));
	gcurr.cell[0] = 1;
	findpathr(&gcurr, 0,0, (g->cols * g->rows),&nsol,2);

}

int printtgrid(struct Grid *gg)
{
	for (size_t r = 0; r <gg->rows ; r++)
	{
		for (size_t c = 0; c < gg->cols; c++)
		{
			printf("%d ", gg->cell[r * gg->cols+c]);
		}
		printf("\n");
	}
	return 1;
}

void main(void)
{
	struct Grid *g=malloc(sizeof(struct Grid));
	g->cols = 5;
	g->rows = 3;
	g->cell = calloc((g->cols * g->rows) , sizeof(int));
	g->cell[1] = -1;
	g->cell[8] = -1;
	
	printf("gridbase:\n");
	printtgrid(g);

	findpath(g);
}