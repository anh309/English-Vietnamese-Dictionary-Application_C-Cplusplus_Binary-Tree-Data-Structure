void inputFirstly(){
	system("cls");
	TittleOfProgram();
	SetBackGroundRange ( 0 + 3 * 16, 5, 9, 20, 5);
	draw_rectangel(5,9,18,4);
	GoToXY(11,10);
	setcolor(0 + 3 * 16);
	printf("Nhap tu:");
	
	SetBackGroundRange ( 0 + 14 * 16, 4, 5, 20, 4);
	setcolor(0 + 14 * 16);
	draw_rectangel(4,5,18,2);
	GoToXY(10,6);
	printf("Tim Kiem");
	
	GoToXY(40,29);
	setcolor(15 + 0 * 16);

}
void UI_searching(){
	system("cls");
	TittleOfProgram();
		
	setcolor(15 + 0 * 16);
	//ve khung lon phai
	SetBackGroundRange ( 0 + 3 * 16, 25, 6, 90, 22);
	//khung be  trai
	SetBackGroundRange ( 0 + 3 * 16, 5, 9, 20, 19);
	setcolor(15 + 3 * 16);
	//===ve khung tong hop
		//thanh trên
		GoToXY(25,6);
		printf("%s",TopLeft);
		for(int i = 0; i<88;i++)
			printf("%s",H_line);
		printf("%s",TopRight);
		//thanh doc
		for(int i = 0; i<2;i++){
			GoToXY(25,7+i);
			printf("%s",V_line);
			GoToXY(114,7+i);
			printf("%s",V_line);
		}
		GoToXY(114,9);
		printf("%s",V_line);
		//goc trai tren
		GoToXY(25,9);
		printf("%s",PlusSym);
		for(int i = 0; i<88;i++)
			printf("%s",H_line);
		printf("%s",MiddleTurnLeft);
		GoToXY(5,9);
		printf("%s",TopLeft);
		for(int i = 0; i<19;i++)
			printf("%s",H_line);
		
		
		//thanh doc
		for(int i = 0; i<16;i++){
			GoToXY(5,10+i);
			printf("%s",V_line);
			GoToXY(114,10+i);
			printf("%s",V_line);
			GoToXY(25,10+i);
			printf("%s",V_line);
		}
		//thanh ngang duoi cung
		GoToXY(5,26);
		printf("%s",BotLeft);
		for(int i = 0; i<108;i++)
			printf("%s",H_line);
		printf("%s",BotRight);
		GoToXY(25,26);
		printf("%s",MiddleUp);
		//thanh ngang menu + tim kiem
		GoToXY(5,13);
		printf("%s",MiddleTurnRight);
		for(int i = 0; i<19;i++)
			printf("%s",H_line);
		printf("%s",MiddleTurnLeft);
		
		
	//===Tieu de : tim kiem
	SetBackGroundRange ( 0 + 14 * 16, 4, 5, 20, 4);
	setcolor(0 + 14 * 16);
	draw_rectangel(4,5,18,2);
	GoToXY(10,6);
	printf("Tim Kiem");
	
	//Nhap tim kiem
	
	GoToXY(11,10);
	setcolor(0 + 3 * 16);
	printf("Nhap tu:");
	//Menu
	GoToXY(13,14);
	printf("Menu");
	GoToXY(6,15);
	for(int  i= 0;i<19;i++)
		printf("%s",High_h);
	GoToXY(6,16);
	printf("1.Phat am");
	GoToXY(6,18);
	printf("2.Tim tu khac");
	GoToXY(6,20);
	printf("3.Chinh sua");
	GoToXY(6,22);
	printf("4.Xoa");
	GoToXY(6,25);
	printf("Esc : Quay lai");		
	//noi dung
	GoToXY(65,7);
	printf("NOI DUNG");
	
	
	
	GoToXY(40,29);
	setcolor(15 + 0 * 16);
}

void Done_Del(){
	system("cls");
	TittleOfProgram();
	//khong tim thay
	setcolor(15 + 3 * 16);
	SetBackGroundRange (0 + 3 * 16, 50, 7, 19, 3);
	draw_rectangel(50,7,18,2);
	
	GoToXY(56,8);
	printf("DA XOA");
	//lua chon
	//1
	SetBackGroundRange (0 + 3 * 16, 25, 10, 20, 3);
	draw_rectangel(25,10,19,2);
	
	
	GoToXY(26,11);
	printf("Backspace: quay lai");

	
	GoToXY(40,29);
	setcolor(15 + 0 * 16);
}
