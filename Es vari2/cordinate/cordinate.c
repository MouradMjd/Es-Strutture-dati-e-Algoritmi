#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"elemtype.h"
#include"list.h"


extern Item* listload(const char* filename)
{
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		return ListCreateEmpty();
	}
	Item* l = ListCreateEmpty();
	struct cord c;
	int s = 0;
	while (1)
	{
		ElemRead(f, &c.x);
		s=ElemRead(f, &c.y);
		l = ListInsertBack(l, &c);
		if (s != 1)
		{
			break;
		}
	}


	return l;

}



void main(void)
{
	Item* l = listload("txt.txt");
}