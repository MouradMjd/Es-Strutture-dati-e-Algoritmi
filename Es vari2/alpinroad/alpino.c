#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct {
	int s, h;
} Point;

bool per(int* v,int size)
{
	bool d = true;
	if (v[0] != 1)
	{
		return false;
	}
	int s = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (v[i] == 0&&s==0)
		{
			s = 1;
		}
		if (v[i] == 1 && s == 1)
		{
			return false;
		}
		if (v[i] == 0 && s == 1)
		{
			continue;
		}
	}
}


int fpr(const Point* p, size_t p_size, int dh,int *vcurr,int n,int vcurrbest,int lim)
{
	int s = p[n].h - p[n - 1].h;
	if ((((p[n].h-p[n-1].h)>dh)|| ((p[n].h - p[n-1].h) < -dh))&&(n>0)&&(vcurr[n-1]==1&&vcurr[n-2]==1))
	{
		return;
	}
	if (n==p_size)
	{
		if (per(vcurr, p_size))
		{
			for (size_t k = 0; k < p_size; k++)
			{
				if (vcurr[k] == 1)
				{
					printf("%d ", vcurr[k]);
				}
			}
			printf("\n");
		}	
		return;
	}
	




	for (size_t i = 0; i < 2; i++)
	{
		vcurr[n] = i;
		fpr(p, p_size, dh, vcurr, n + 1, vcurrbest, lim);
	}
		
		
}

int fp(const Point* p, size_t p_size, int dh)
{
	int* vcurr = calloc(p_size, sizeof(int));
	int*vcurrbest= calloc(p_size, sizeof(int));
	int lim = p[0].h + dh;
	fpr(p, p_size, dh, vcurr, 0, vcurrbest,lim);



}


void main(void)
{
	Point* s = malloc(5 * sizeof(Point));
	s[0].s = 0;
	s[1].s = 40;
	s[2].s = 60;
	s[3].s = 110;
	s[4].s = 170;

	s[0].h = 10;
	s[1].h = 19;
	s[2].h = 44;
	s[3].h = 25;
	s[4].h = 17;

	fp(s, 5, 10);



}

