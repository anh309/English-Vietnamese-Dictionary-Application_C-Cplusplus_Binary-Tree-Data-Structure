#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

char *FileName = "output.txt";
char **array;
int countline;
char **NghiaGocExcept;
unsigned long countChar;

#include "MenuList.cpp"		




int main(int argc, char *argv[])
{
	ResizeConsole(120, 30);
	SetCenterConsole();
	DisableMaximize();
	SetConsoleTitle("The RYZEN TEAM's DICTIONANY PROJECT");
	
	//Khoi Tao -----------------------------------
	SetConsoleOutputCP(65001); // go tieng viet
    array = _FileListToArray(FileName);
    countChar = _FileCountChar(FileName);
 	countline = _FileCountLines(FileName);
	NghiaGocExcept = new char*[countline];
	for (int i=0; i<countline; i++)
		NghiaGocExcept[i] = new char[50];
	//--------------------------------------------
	
	tree t;
	init(t);

	printf("Cap nhat danh sach tu dien...");
	_ArrayToTreeWord (array, countline, t); // dua du~ lieu. vao` tree
	

	SetConsoleOutputCP(65001); 
	setcolor(15 + 0 * 16);
	
	do{
		MAINmenu(t);
	}while(true);
	


	return 0;
}