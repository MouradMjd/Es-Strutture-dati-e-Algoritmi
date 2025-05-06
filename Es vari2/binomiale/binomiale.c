double Binomialerec(unsigned int n, unsigned int k)
{
	if (k==0|| k == n)
	{
		return 1;
	}


	return Binomialerec(n - 1, k - 1) + Binomialerec(n - 1, k);

}
double Binomiale(unsigned int n, unsigned int k)
{
	if (k > n||n==0)
	{
		return -1;
	}
	Binomialerec(n, k);
}
void main(void)
{
	int n = 12;
	int k = 5;
	double i = Binomiale(n, k);
}