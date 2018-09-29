void MenuFChoice(tree t,char choice);
node *TimTu(tree t, char *wordF){ 	// ham tim ki tu trong tu dien

	while (t!=NULL)
		if(strcmp(t->data.NghiaGoc,wordF) == 0){
			return t;
		}						
		else
			if(strcmp(wordF, t->data.NghiaGoc) < 0)
				t = t ->pleft;		
			else t = t ->pright;
	
	return NULL;
}


void XuatTimTu(tree &t){
	system("cls");
	//inputFirstly();
	UI_searching();
	node* p = TimTu(t,wordFun());
	char choice;

	if(p!=NULL){
		
		
		do{
		system("cls");
		UI_searching();
		
		setcolor(15 + 3 * 16);
		XuatDanhSachWord(p->data,27,10,90);
		
		GoToXY(6,24);
		setcolor(15 + 0 * 16);
		choice = getch();
		switch(choice){
			case '1': {
				
				_Text_To_Speech(p->data.NghiaGoc);
				break;	
			}
			case '2':{
				if (Confirm("Tim tu khac")==true){
					XuatTimTu(t);
					choice ='0';
					break;
				}
				else{
					system("cls");	
					break;
				}	
			} 
			case '3': {
				if (Confirm("Sua tu")==true){
					SuaTu(p->data);
					system("cls");
					break;
				}
				else{
					system("cls");	
					break;
				}
			}
			case '4': {
				if (Confirm("Xoa tu")==true){
					t=deleteNode(t, p->data);
					MenuFChoice(t,choice);	
					break;
				}
				else{	
					system("cls");	
					break;
				}
			}
			
		}
		}while (choice!=27);
	}else{
		GoToXY(27,11);
		printf("KHONG TIM THAY!");
		
		MenuFChoice(t,choice);
	}
}

void MenuFChoice(tree t,char choice){

	char x;
	Done_Del();
	do{
		
		x= getch();
	}while (x!=8);
}
