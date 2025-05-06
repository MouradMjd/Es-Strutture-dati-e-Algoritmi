#include<stdbool.h>
#include<string.h>

bool is_palindromarec(const char* str,size_t size,bool *answ,int i)
{
	if (size == 0)
	{
		return;
	}
	if (str[i] != str[size - 1])
	{
		*answ = false;
		return;
	}
	is_palindromarec(str, size - 1, answ, i + 1);

}

bool is_palindroma(const char* str)
{
	size_t size = strlen(str);
	bool s = true;
	is_palindromarec(str, size, &s, 0);
	return s;
}

void main(void)
{
	char frase[] = "bitumiera";
	bool ris = is_palindroma(frase);
	return;
}