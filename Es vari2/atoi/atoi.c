#include<stdlib.h>
#include<string.h>
#include<math.h>

void atoirec(const char* str,int size,int *z,int i)
{
	if (size == 0)
	{
		return;
	}
	if (str[size-1] != '0' && str[size - 1] != '1' && str[size - 1] != '2' && str[size - 1] != '3' && str[size - 1] !=
		'4' && str[size - 1] != '5' && str[size - 1] != '6' && str[size - 1] != '7' && str[size - 1] != '8' && str[size - 1] != '9' && str[size - 1] != 
		'+' && str[size - 1] != '-')
	{
		*z = 0;
		return;
	}
	if (str[size - 1] == '+')
	{
		return;
	}
	if (str[size-1] == '-')
	{
		*z = -(*z);
		return;
	}
	*z = *z + pow(10, i)* (str[size - 1]-'0');
	atoirec(str, size - 1, z,i+1);
}
int atoi_(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	size_t size = strlen(str);
	int z = 0;
	atoirec(str, size, &z,0);
	return z;
}



void main(void)
{
	char riga[] = "-45a";
	int i = atoi_(riga);

}