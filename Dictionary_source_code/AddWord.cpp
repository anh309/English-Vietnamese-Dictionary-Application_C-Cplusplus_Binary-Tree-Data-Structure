void ThemTu(tree t);


void MenuEChoice(tree t,_Word p){//hoi khi them xong

	char choice;
	do{
		choice= getch();
		switch(choice){
			case 43 : ThemTu(t);choice =8;break;
			case 13 : _Text_To_Speech(p.NghiaGoc);break;
			case 45 : t=deleteNode(t, p);choice =8;break;
		}
	}while (choice != 8);
	
		
	
		
}
void ThemTu(tree t){
	system("cls");
	setcolor(15 + 0 * 16);
	UI_add();//UI
		_Word p;

		GoToXY(14,8);
		setcolor(15+3*16);
		printf("Nhap Nghia Goc: ");//nghia goc
		do{
		GoToXY(30,8);
		fflush(stdin);
		gets(p.NghiaGoc);
		}while (EmptyChar(p.NghiaGoc)==true);
		
		
			GoToXY(14,9);
			printf("Nhap Phien Am: ");//phien am
		do{
			GoToXY(30,9);
			fflush(stdin);
			gets(p.PhienAm);
		}while (EmptyChar(p.PhienAm)==true);
		
		
			GoToXY(14,10);
			printf("Nhap so luong Tu Loai(0;1;2)");//ntu loai
		do{
			
			char t= getch(); 
			p.nTuLoai=t-'0';
		}while (p.nTuLoai<0 || p.nTuLoai>2);
		unsigned int j,i,ln=0;//ln: dem so dong
	
		for(i= 2; i<p.nTuLoai+2;i++){
				GoToXY(14,10+i+ln);
				printf("Nhap ten Tu Loai [%d]: ",i-2);//nhap tu loai i
			do{
				
				GoToXY(36,10+i+ln);
				fflush(stdin);
				gets(p.TuLoai[i-2].Ten);	
			}while (EmptyChar(p.TuLoai[i-2].Ten)==true);
			
			ln++;
				GoToXY(14,10+i+ln);
				printf("Nhap so luong nghia tu loai %s(0;1;2)",p.TuLoai[i-2].Ten);//n nghia
			do{	
				char t= getch(); 
				p.TuLoai[i-2].nNghia=t-'0';
			}while (p.TuLoai[i-2].nNghia<0 ||p.TuLoai[i-2].nNghia>2);	//dieu kien nhap
			
			ln++;
		
			for(j =1;j<p.TuLoai[i-2].nNghia+1;j++){
					GoToXY(14,10+i+ln);
					printf("Nhap Nghia [%d]: ",j-1);//nhap nghia
				do{
					GoToXY(30,10+i+ln);
					fflush(stdin);
					gets(p.TuLoai[i-2].Nghia[j-1]);
				}while (EmptyChar(p.TuLoai[i-2].Nghia[j-1])==true);
				
				ln++;
			}
		}

	
	t=insert(t, p);
	setcolor(15+0*16);
	after_add();
	setcolor(15+3*16);
	XuatDanhSachWord(p,24,8,90);
	MenuEChoice(t,p);
	setcolor(15+0*16);
}