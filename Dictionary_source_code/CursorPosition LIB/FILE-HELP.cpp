#include <stdio.h>
#include "CursorPosition.cpp"
int main(int argc, char *argv[])
{
/*color your text in Windows console mode
  0    Black
  1    Blue
  2    Green
  3    Cyan
  4    Red
  5    Magenta
  6    Brown
  7    White
  8    Grey
  9    Light Blue
 10    Light Green
 11    Light Cyan
 12    Light Red
 13    Light Magenta
 14    Yellow
 15    High-intensity white
// colorattribute = foreground + background * 16 - ----- -> cong thuc
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236*/


	DisableMaximize();
	setcolor(15 + 0 * 16); //default nen` den chu~ trang = 15 + 0 * 16
	
	SetBackGroundRange (0 + 3 * 16, 10, 4, 50, 4); //arg: color = 63, left: 15, top:10, width: 50, height: 10
		GoToXY(12,5);
		setcolor(15 + 3 * 16);
		printf("Chuong trinh tu dien anh viet\n");
	GoToXY(10,4);	
	for (int i=1; i<= 50; i++){
		setcolor(15 + 3 * 16);
		printf("=");
		
	}
		
		
	SetBackGroundRange (0 + 8 * 16, 10, 7, 50, 6);

	
	GoToXY(10,15);
	setcolor(15 + 0 * 16);
	system("pause");
	return 0;
}