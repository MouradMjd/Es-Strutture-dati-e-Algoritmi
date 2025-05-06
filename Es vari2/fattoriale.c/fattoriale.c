unsigned long long Fattorialerec(int n)
{
	if (n == 1)
	{
		return 1;
	}

	return Fattorialerec(n - 1) * n;

}



unsigned long long Fattoriale(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return Fattorialerec(n);

}


void main(void)
{
	int n = -1;
	unsigned long long i = Fattoriale(n);
}


