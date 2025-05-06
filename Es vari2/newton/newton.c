#include"newton.h"
#include<math.h>
#include<stdlib.h>
#include <stdio.h>


double f(Polinomio* p, double xn)
{
	double r = 0;

	for (size_t i = 0; i <p->size ; i++)
	{
		r = r + (p->coeff[i] * pow(xn, i));
	}
	return r;
}

extern double newtonrec(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter,int i)
{
	double xnn = xn - (f(p,xn) / f(d,xn));
	if (fabs(xnn - xn) <= t)
	{
		return xnn;
	}
	if (i==max_iter)
	{
		return xnn;
	}


	return newtonrec(p, d, xnn, t, max_iter,i+1);
}

extern double newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter)
{

	return newtonrec(p, d, xn, t, max_iter,0);
}



void main(void)
{
	Polinomio p;
	p.coeff = malloc(4 * sizeof(int));
	int y = 4;
	p.size = y;

	Polinomio d;
	d.coeff = malloc(4 * sizeof(int));
	int y1 = 4;
	d.size = y1;

	p.coeff[0] = 0;
	p.coeff[1] = -2;
	p.coeff[2] = 0;
	p.coeff[3] = 1;

	d.coeff[0] =-2;
	d.coeff[1] = 0;
	d.coeff[2] = 3;
	d.coeff[3] = 0;

	double i = newton(&p, &d, 1, 0.00001, -1);
	

}
