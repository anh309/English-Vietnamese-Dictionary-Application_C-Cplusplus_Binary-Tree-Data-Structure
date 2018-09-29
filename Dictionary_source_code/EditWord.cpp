void SuaTu(_Word &x);

using namespace std;
bool EmptyChar(char *x){//kiem tra xau  rong, true: co; false : khong
	if(strcmp(x,"")==0) return true;
	for(unsigned i=0;i<strlen(x);i++){
		if( x[i]!=32)
			return false;
	}
	return true;
}	
char *wordFun(){ //ham nhap tra ve 1 chuoi ki tu 
	char *tChar = (char *) malloc (sizeof(char) * 30);
	
	
	setcolor(15 + 3 * 16);
	do{
		GoToXY(6,11);
		setcolor(15 + 3 * 16);
		fflush(stdin);
		gets(tChar);
		GoToXY(40,29);
		setcolor(15 + 0 * 16);	
	}while (strcmp(tChar,"")==0||strcmp(tChar," ")==0);
	
	return tChar;
}
void Limit_input(char *s,int x){//gioi han so tu nhap
	char c;
	for(int i=0;i<x;i++){
		if(c==13) break;
		
	c=getche();
	strcat(s, Convert_Char_To_String(c));
	}
}
bool Confirm(char *x){//xác nhan
	Confirm_box(x);
	char s;
	do{	
		s=getch();
	}while (!(s=='y' || s=='Y' || s=='n' || s=='N'));
	
	if (s=='y' || s=='Y')
		return true;
	else return false;
}
void EditNghiaGoc(_Word	&x){
		setcolor(15 + 3 * 16);
	do{
		GoToXY(56,27);
		fflush(stdin);
		gets(x.NghiaGoc);
		//strcpy(x.NghiaGoc,"");
		//Limit_input(x.NghiaGoc,30);
	}while (EmptyChar(x.NghiaGoc)==true); //rong~ hay 
	

}
void EditPhienAm(_Word	&x){
	setcolor(15 + 3 * 16);
	do{
	GoToXY(56,27);
	fflush(stdin);
	gets(x.PhienAm);
	
	}while (EmptyChar(x.PhienAm)==true);
	

}
void EditTuLoai(_Word &x){
	
	int c_Int;
	//in ds tu loai
	setcolor(15 + 3 * 16);
	for(int i =0 ; i< x.nTuLoai; i++){
		GoToXY(31,8+i);
		printf("%d)%s\n",i,x.TuLoai[i].Ten);
	}
		

	//chon 
		SetBackGroundRange ( 0 + 3 * 16, 45, 17, 31, 3);
		draw_rectangel(45,17,30,2);
		GoToXY(46,18);
		printf("Chon tu loai: ");
	do{
		GoToXY(60,18);
		scanf("%d",&c_Int);
	}while (c_Int<0||c_Int>=x.nTuLoai);
	
	//Nhap 
		SetBackGroundRange ( 0 + 3 * 16, 35, 21, 52, 3);
		draw_rectangel(35,21,51,2);
		GoToXY(36,22);
		printf("Nhap TU LOAI moi: ");
	do{	
		GoToXY(55,22);
		fflush(stdin);
		gets(x.TuLoai[c_Int].Ten);
	}while (EmptyChar(x.TuLoai[c_Int].Ten)==true);
	
	char a[50]="*  ";

	strcat(a,x.TuLoai[c_Int].Ten);
	strcpy(x.TuLoai[c_Int].Ten,a);

	
}
void EditNghia(_Word &x){
	setcolor(15 + 3 * 16);
	GoToXY(23,8);
	int ln=0;
	for (int k=0; k < x.nTuLoai; k++){
			GoToXY(23,8+ln);
			printf("Tu loai (%d): %s",k, x.TuLoai[k].Ten);
			ln++;
			for (int m=0; m<x.TuLoai[k].nNghia; m++){
				GoToXY(23,8+ln);
				printf("  Nghia %d: %s", m, x.TuLoai[k].Nghia[m]);
				ln++;
			}			
		}
	char c,c2;
	int c_Int,c2_Int;
	//chon tu loai
	
	do{
		GoToXY(36,23);
		printf("Chon TU LOAI chua NGHIA(int): ");
		c=	getch();
		c_Int = c -'0';
	}while (c_Int<0||c_Int>=x.nTuLoai);
	//in tu loai
	GoToXY(36,24);
	printf("TU LOAI da chon: %s",x.TuLoai[c_Int].Ten);
	
	//chon nghia
	
			
	do{
		GoToXY(36,25);
		printf("Chon NGHIA(int): ");
		c2=	getch();
		c2_Int = c2 -'0';
	}while (c2_Int<0||c2_Int>=x.TuLoai[c_Int].nNghia);
	//in nghia
	GoToXY(36,26);
	printf("NGHIA da chon: %s",x.TuLoai[c_Int].Nghia[c2_Int]);	
	
	do{	
		//Nhap nghia
		GoToXY(36,27);
		printf("Nhap NGHIA  moi: ");
		fflush(stdin);
		gets(x.TuLoai[c_Int].Nghia[c2_Int]);
	}while (EmptyChar(x.TuLoai[c_Int].Nghia[c2_Int])==true);

	char a[50]=" - ";

	strcat(a,x.TuLoai[c_Int].Nghia[c2_Int]);
	strcpy(x.TuLoai[c_Int].Nghia[c2_Int],a);

}
void SuaTu(_Word &x){
	system("cls");
	char choice; 
	
	do{
		
		UI_edit(); //ui
		setcolor(15 + 3 * 16);	//in tu
		XuatDanhSachWord(x,27,10,87);
		GoToXY(6,24);
		
		choice = getch();
		
		switch(choice)	{
		case '1':{setcolor(15 + 0 * 16);
			if (Confirm("Da chon sua Nghia Goc!")==true) {//Nghia goc
				
				ui_NghiaGoc();
				setcolor(15 + 3 * 16);
				XuatDanhSachWord(x,23,8,77);
				EditNghiaGoc(x);
				setcolor(15 + 0 * 16);
				break;
			}
			else{

				break;
			}
		}
		case '2': {setcolor(15 + 0 * 16);
			if (Confirm("Da chon sua Phien Am!")==true) {//Phien am
				
				ui_PhatAm();
				setcolor(15 + 3 * 16);
				XuatDanhSachWord(x,23,8,77);
				EditPhienAm(x);
				setcolor(15 + 0 * 16);
				break;
			}
			else{

				break;
			}
		}
		case '3': {setcolor(15 + 0 * 16);
			if (Confirm("Da chon sua Tu Loai!")==true) {//tu loai
			
				ui_TuLoai();
				setcolor(15 + 0 * 16);
				EditTuLoai(x);
				setcolor(15 + 0 * 16);
				break;
			}
			else{

				break;
			}
		}
		case '4': {setcolor(15 + 0 * 16);
			if (Confirm("Da chon sua Nghia!")==true) {//nghia
				ui_Nghia();
				setcolor(15 + 0 * 16);
				EditNghia(x);
				setcolor(15 + 0 * 16);
				break;
			}
			else{

				break;
			}
		}
	}
	}while(choice !=27);//esc
	setcolor(15 + 0 * 16);
	
	
}