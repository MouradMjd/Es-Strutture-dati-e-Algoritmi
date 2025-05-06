#include<stdint.h>
#include"secanti.h"
#include<math.h>
#include<stdlib.h>

double funz(Polinomio* p, double xn)
{
	double fuz = 0;
	for (int i = 0; i < p->size; i++)
	{
		fuz = fuz + (pow(xn, i) * p->coeff[i]);
	}
	return fuz;
}



double secanti(const Polinomio* p, double x0, double x1, double t, int max_iter)
{
	double fxn = funz(p, x1);
	double fxn_prev = funz(p, x0);


	double xn_1 = (x1)-((x1-x0)/(fxn-fxn_prev))*fxn;

	if (fabs(xn_1 - x1)<=t)
	{
		return xn_1;
	}
	if (max_iter == 1)
	{
		return xn_1;
	}

	return secanti(p, x1, xn_1, t, max_iter - 1);
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

