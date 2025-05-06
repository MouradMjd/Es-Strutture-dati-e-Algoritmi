#include<stdbool.h>
#include<string.h>



bool  palindromorec(const char* str,int i,int n)
{
	if (i > n)
	{
		return true;
	}
	
	bool c = true;
	if (str[i]!=str[n-1])
	{
		c = false;
	}

	return c && palindromorec(str, i + 1, n - 1);
}





bool  palindromo(const char* str)
{
	char s = 0;
	int n = strnlen(str,&s);
	return palindromorec(str, 0, n);

}

void main(void)
{
	palindromo("anna");
}