


int Fibonaccirec(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}


	return Fibonaccirec(n - 1) + Fibonaccirec(n -2);

}

int Fibonacci(int n)
{
	if (n < 0)
	{
		return -1;
	}
	return Fibonaccirec(n);
}

void main(void)
{
	int n = 12;
	int i = Fibonacci(n);
}