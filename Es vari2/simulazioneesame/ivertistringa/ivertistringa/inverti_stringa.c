#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void revstrrec(char* str,char *risu,int n,int i)
{
	if (n == 0)
	{
		char c = str[n];
		char* d = &c;
		risu[i] = d[0];
		return;

	}
	char c = str[n];
	risu[i] = c;
	revstrrec(str, risu, n - 1, i + 1);
}



char* revstr(char* str)
{
	size_t s = strlen(str);
	char* v = calloc(s,sizeof(char));
	revstrrec(str, v, s-1,0);

	return v;

}
void main(void)
{

	char *c=revstr("ciao");



}