#include<math.h>
unsigned long long factorial(int n) {
    // Inizializza il fattoriale a 1
    unsigned long long fact = 1;

    // Calcola il fattoriale
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    // Restituisci il risultato
    return fact;
}

void trilingrec(int n,int *z)
{
    int b = 0;
    if (n % 2 != 0)
    {
        b = 1;
    }
    if (n == 0)
    {
        return;
    }

    trilingrec(n / 2, z);
    if (b == 0)
    {
        *z = *z + 1;
    }
    else
    {
        *z = 0;
    }

}



int trailing(int n)
{
	int z = 0;
    int e = factorial(n);
	trilingrec(e, &z);
    return z;
}


void main(void)
{
	int n=trailing(6);
}