#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>

void  ReverseStringrec(const char* str,int *i,char **new,int j,int n_size)
{
	
	if (j==n_size)
	{
		return;
	}

	*new[(j-1)] = str[n_size - j];
	ReverseStringrec(str, i, new, j + 1,n_size);
	return new;

}
char* ReverseString(const char* str)
{
	if (str == NULL)
	{
		return NULL;
	}
	size_t i = 0;
	size_t n = strlen(str);
	char* s = malloc(n*sizeof(char));
	ReverseStringrec(str, &i, &s, 1,n);
	return s;
}

//void main(void)
//
//{
//	char s[] = "striga da invertire";
//	ReverseString(s);
//}