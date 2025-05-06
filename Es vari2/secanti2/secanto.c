#include"secanto.h"
#include<math.h>
#include<stdlib.h>
double f(Polinomio* p, double xn)
{
	double r = 0;

	for (size_t i = 0; i < p->size; i++)
	{
		r = r + (p->coeff[i] * pow(xn, i));
	}
	return r;
}

double secantirec(const Polinomio* p, double x0, double x1, double t, int max_iter,int i)
{
	double xnn = x1 - (((x1 - x0) / (f(p, x1) - f(p, x0))) * f(p, x1));
	if (fabs(xnn - x1) <= t)
	{
		return xnn;
	}
	if (i == max_iter)
	{
		return xnn;
	}


	secantirec(p, x1, xnn, t, max_iter, i + 1);

}


double secanti(const Polinomio* p, double x0, double x1, double t, int max_iter)
{
	return secantirec(p, x0, x1, t, max_iter,0);
}


void main(void)
{
	Polinomio p;
	p.coeff = malloc(4 * sizeof(int));
	int y = 4;
	p.size = y;

	p.coeff[0] = 1;
	p.coeff[1] = -12;
	p.coeff[2] = -3;
	p.coeff[3] = 2;

	double n = secanti(&p, -2, 4, 0.00001, -1);
}