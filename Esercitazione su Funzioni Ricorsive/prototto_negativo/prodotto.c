int Prodottorec(int a, int b)
{
	if (a == 1)
	{
		return b;
	}


	return Prodottorec(a - 1, b) + b;
}


int Prodotto(int a, int b)
{
	if (a <0&&b>0)
	{
		a = -a;
		return -Prodottorec(a, b);
	}
	if (a > 0 && b<0)
	{
		b = -b;
		return -Prodottorec(a, b);
	}
	if ((a < 0 && b < 0)||(a >= 0 && b >= 0))
	{
		return Prodottorec(a, b);
	}
	
}

void main(void)
{
	int a = -4;
	int b = 5;
	Prodotto(a, b);
}