#define _CRT_SECURE_NO_WARNINGS
#include"elemtype.h"
#include"tree.h"

Node* treereadrec( FILE* f)
{
	ElemType n;
	int s=fscanf(f, " %c", &n);


	if (s != 1)
	{
		return TreeCreateEmpty();
	}
	if (n == '.')
	{
		fscanf(f, " %c", &n);
		return TreeCreateRoot(&n, TreeCreateEmpty(), TreeCreateEmpty());

	}
    
	Node* l = treereadrec(f);
	Node* r = treereadrec(f);
	return TreeCreateRoot(&n, l,r);

}


Node* treeread(const* filename)
{
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL)
	{
		return TreeCreateEmpty();
	}
	Node* tree = TreeCreateEmpty();
	tree=treereadrec(f);

	fclose(f);
	return tree;

}



void treewriterec(Node* t,int d)
{

	if (TreeIsLeaf(t))
	{
		char r = TreeGetRootValue(t)[0];
		printf("%*s", 4 * d, " ");
		printf(".%c\n", r);
		return;
	}
	char  s= TreeGetRootValue(t)[0];
	printf("%*s", 4 * d, " ");
	printf("%c\n", s);



	treewriterec(t->left,d+1);
	treewriterec(t->right,d+1);

}
void treewrite(Node* t)
{
	treewriterec(t, 0);
}



	


void main(void)
{

	Node* tree = treeread("txt.txt");
	treewrite(tree);

}