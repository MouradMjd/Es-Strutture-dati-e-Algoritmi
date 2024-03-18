#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"elemtype.h"
#include"list.h"




Item* ListLoad(const char* filename)
{
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		return ListCreateEmpty();
	}

	Item * s = ListCreateEmpty();
	int n = 0;
	while(ElemRead(f, &n)==1)
	{
		s=ListInsertBack(s,&n);
	}
	return s;

}


void main(void)
{
	Item *s=ListLoad("text.txt");
}