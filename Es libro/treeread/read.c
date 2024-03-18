#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"elemtype.h"
#include"tree.h"

 Node* TreeReadrec(FILE* filename)
{
	 ElemType c;
	 if (fscanf(filename, " %c",&c) != 1)
	 {
		 return TreeCreateEmpty();
	 }
	 if (c == '.')
	 {
		 fscanf(filename, " %c", &c);
		 return TreeCreateRoot(&c, NULL, NULL);
	 }
	 

	 Node* l = TreeReadrec(filename);
	 Node* r = TreeReadrec(filename);
	 return TreeCreateRoot(&c, l, r);


}



 Node* TreeRead(const char* filename)
{
	 FILE* f = fopen(filename, "r");
	 if (!f)
	 {
		 return TreeCreateEmpty();
	 }

	 Node* t = TreeReadrec(f);
	 fclose(f);
	 return t;

}

 //void main(void)
 //{
	//Node*t= TreeRead("albero1.txt");
	//TreeWriteStdoutPostOrder(t);
 //}
