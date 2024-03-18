#include<stdlib.h>


extern int Recamanrec(int n)
{
	if (n == 1)
	{
		return 1;
	}

	if (Recamanrec(n - 1) % (n - 1) == 0)
	{
		int an = Recamanrec(n - 1) / (n - 1);
	}
	else
	{
		int an = Recamanrec(n - 1) * (n - 1);
	}
}
extern int Recaman(int n)
{
	if (n < 0)
	{
		return - 1;
	}
	int i = Recamanrec(n);
	return i;
}



//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		return -1;
//	}
//	char* s;
//	int n = strtol(argv[1], &s, 0);
//	if (n < 0)
//	{
//		return -1;
//	}
//	int r=Recaman(n);
//}