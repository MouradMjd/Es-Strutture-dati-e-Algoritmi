#include<stdlib.h>

int Minimo(const int* v, int v_size)
{
	int next_size = v_size - 1;
	int n = v[next_size];

	if (next_size == 0)
	{
		return n;
	}

	int s = Minimo(v, next_size);
	if (s < n)
	{
		return s;
	}
	else
	{
		return n;
	}
}





int main(void)
{
	 int *s = malloc(3 * sizeof(int));
	s[0] = 2;
	s[1] = 4;
	s[2] = 3;

	Minimo(s, 3);
}