#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char **a = new char*[10];
	for (int i=0; i<10; i++)
		a[0] = new char[50];
	strcpy(a[0], "a");
	puts(a[0]);
	return 0;
}