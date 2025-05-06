#define _CRT_SECURE_NO_WARNINGS
#include"elemtype.h"
#include"tree.h"
#include<stdio.h>
#include<stdlib.h>

Node* TreeReadrec(FILE *f)
{
	char c = "\0";
	int r1=fscanf(f, " %c", &c);
	if (r1 != 1)
	{
		return;
	}
	if (c == '.')
	{
	    fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, NULL, NULL);
	}
	Node* l = TreeReadrec(f);
	Node* r = TreeReadrec(f);

	return TreeCreateRoot(&c, l,r );
}

Node* TreeRead(const char* filename)
{
	FILE *f=fopen(filename,"r");
	if (f == NULL)
	{
		return TreeCreateEmpty();
	}

	Node* t = TreeReadrec(f);

}

void main(void)
{
	TreeRead("d.txt");
}

