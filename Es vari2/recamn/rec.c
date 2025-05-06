#include <math.h>
#include<stdio.h>



void frazioneegi(int n, int d)
{
	if (d % n == 0)
	{
		return;
	}

	

	

	frazioneegi(1, (n / d));

}

void Recamanrec(int n,int i,int an,int *nvol)
{
	if (i == n)
	{
		*nvol = an;
		return;
	}
	int ann = 0;
	if (an%i == 0)
	{
		ann = an / i;
	}
	if(an%i)
	{
		ann = an * i;
	}

	Recamanrec(n, i + 1, ann, nvol);

}


int Recaman(int n)
{
	int* vol = 0;
	Recamanrec(n, 1, 1, &vol);
	return vol;
}


void main(void)
{
	Recaman(7);
	frazioneegi(7, 24);
}