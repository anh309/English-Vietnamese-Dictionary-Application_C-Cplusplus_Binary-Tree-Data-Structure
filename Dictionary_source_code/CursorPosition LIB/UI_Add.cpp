
void UI_add()//UI them tu
{
	system("cls");
	setcolor(15 + 0 * 16);
	TittleOfProgram();
	//o tu hien tai
		SetBackGroundRange ( 0 + 3 * 16, 12, 5, 95, 22);
		
		draw_rectangel(12,5,93,21);
		//thanh giua 
		GoToXY(12,7);
		printf("%s",MiddleTurnRight);
		for(int i = 0; i<93;i++)
			printf("%s",H_line);
		printf("%s",MiddleTurnLeft);
		//Tieu de them tu
		GoToXY(54,6);
		printf("THEM TU MOI");
		
		
		
		
		GoToXY(55,30); 
		setcolor(15 + 0 * 16);
}

void after_add(){//xuat tt tu sau khi them
	system("cls");
	TittleOfProgram();
	//o tu hien tai
		SetBackGroundRange ( 0 + 3 * 16, 22, 5, 77, 19);
		
		draw_rectangel(22,5,75,18);
		//thanh giua 
		GoToXY(22,7);
		printf("%s",MiddleTurnRight);
		for(int i = 0; i<75;i++)
			printf("%s",H_line);
		printf("%s",MiddleTurnLeft);
		//tu da them
		GoToXY(53,6);
		printf("TU DA THEM");
		
		//thao tac
		SetBackGroundRange ( 0 + 3 * 16, 30, 25, 60, 5);//khung mau
		draw_rectangel(30,25,59,4);
		
			GoToXY(59,25);//chia phan
			printf("%s",MiddleDown);
			GoToXY(59,29);
			printf("%s",MiddleUp);
			
				GoToXY(59,26);
				printf("%s",V_line);
				GoToXY(59,28);
				printf("%s",V_line);
			GoToXY(30,27);
			printf("%s",MiddleTurnRight);
			for(int i=0;i<59;i++){
				GoToXY(31+i,27);
				printf("%s",H_line);
			}
			printf("%s",MiddleTurnLeft);
			GoToXY(59,27);
			printf("%s",PlusSym);

		
		//ds menu
		GoToXY(35,26);
		printf("Backspace : Quay ve");
		GoToXY(65,26);
		printf("+ : Them tu moi");
		GoToXY(35,28);
		printf("- : Xoa");
		GoToXY(65,28);
		printf("Enter : nghe tu nay");
		
		
		GoToXY(55,30);
		setcolor(15 + 0 * 16);
	
}