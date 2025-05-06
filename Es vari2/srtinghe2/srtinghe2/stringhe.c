#include<string.h>
#include<stdlib.h>
#include<stdio.h>


void backtrackstrrec(int n,int *vcurr,int k,int *alfabeto,int *presi)
{
	if (k ==n)
	{

			printf("{");
			for (size_t i = 0; i < n; i++)
			{
				printf("%c", vcurr[i]);
			}
			printf("}");
		return;

	}



for (char i = 'a'; i < 'a'+2; i++)
	{
		vcurr[k] = i;
		backtrackstrrec(n, vcurr, k + 1, alfabeto, presi);
	}


}

void backtrackstr(int n)
{
	if (n <= 0 || n > 26)
	{
		return;
	}
	char *vcurr= calloc(n,sizeof(char));
	char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int pres = 0;
	backtrackstrrec(n, vcurr, 0, alfabeto, &pres);

}




void main(void) {
	int n = 2;
	backtrackstr(n);
}

