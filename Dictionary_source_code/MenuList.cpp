#include "CursorPosition LIB/CursorPosition.cpp"
#include "TreeWord.cpp"
#include "CursorPosition LIB/Symbol.cpp"
#include "CursorPosition LIB/UI_Main.cpp"
#include "CursorPosition LIB/UI_Searching.cpp"
#include "CursorPosition LIB/UI_Edit.cpp"
#include "CursorPosition LIB/UI_Confirm.cpp"
#include "CursorPosition LIB/UI_Add.cpp"
#include "TextToSpeech.cpp"
#include "EditWord.cpp"
#include "DelWord.cpp"
#include "FindWord.cpp"
#include "AddWord.cpp"


void Menu1_print(tree t){
	system("cls");
	nlr(t);
	system("pause");
}

void Menu2_find(tree t){
	XuatTimTu(t);
}
void Menu3_add(tree t){
	ThemTu(t);
}
void ending(){
	system("cls");
	}
	
	
//===================================================Generate_Box=======================
int iMaxFilter = 14; //-> de xoa dua vao height
int iMaxLenAline = 18; //do dai lon nhat cua cac filter ->de xoa dua vao` width
COORD posNhapTu = {16, 6};  // posNhapTu.X = 0, posNhapTu.Y = 1;

COORD pos_list_filter ={16, 8}; 

int i_ListFilter;
short tempFilterY;

char FirstFilter[1];
char tempFirstFilter[1];
bool FlagFirstFulter = true;

_Word WordUpDown[14]; // move _Word up down

int n_WordUpDown = 14;

int maxEx = 0;
bool checkStringLeftToRight (char *str, char* Filter){
	if (Filter[0] == '\0') return false;
	for (int i=0; i<strlen(Filter); i++)
		if (Filter[i] != str[i] )
			return false;
	return true;
}

void Xuat_WordUpDown(_Word WordUpDown[], int i_WordUpDown, COORD pos_list_filter){
	for (int i=0; i<i_WordUpDown; i++){
		GoToXY(pos_list_filter.X, pos_list_filter.Y++);
		printf ("%s",WordUpDown[i].NghiaGoc); 
	}
}

int i_CheckStartWordUpDown = 0;
int iStartWordUpDown = 1;
bool FilterMatch = false;
void nlrForBox_Generate(tree t, char *Filter){
	if(t != NULL)
	{
	    nlrForBox_Generate(t->pleft, Filter);
	    if (checkStringLeftToRight(t->data.NghiaGoc, Filter)){
	    	FilterMatch = true;
   	    	if (i_ListFilter >= iMaxFilter)
   	    		return;
   			if (i_CheckStartWordUpDown >= iStartWordUpDown){
	    		WordUpDown[i_ListFilter] = t->data; // cap nhat list filter vao trong mang de duyet arrow
	   	    	i_ListFilter++;		
			   }
			i_CheckStartWordUpDown ++;		   
			
    	}else if (stricmp(Filter, "..FULL") == 0){
	    	FilterMatch = true;
   	    	if (i_ListFilter >= iMaxFilter)
   	    		return;
   			if (i_CheckStartWordUpDown >= iStartWordUpDown){
	    		WordUpDown[i_ListFilter] = t->data; // cap nhat list filter vao trong mang de duyet arrow
	   	    	i_ListFilter++;		
			   }
			i_CheckStartWordUpDown ++;			    	
	    }
	    nlrForBox_Generate(t->pright, Filter);
	}
}

void _Gen_At_FirstWord(tree t, char *FirstWord){
	 i_CheckStartWordUpDown = 0;
	 iStartWordUpDown = 0;
	 FilterMatch = false;

	nlrForBox_Generate(t, FirstWord); //cap nhat WordUpDown
	n_WordUpDown = i_ListFilter;
	Xuat_WordUpDown(WordUpDown, i_ListFilter, pos_list_filter);
	GoToXY(13,8);
	printf("\u2192");
	XuatDanhSachWord (WordUpDown[0], 38, 8,91); //xuat tu dau tien				
}

void _Update_Box_Gen(tree t, char* str){
	FilterMatch = false;
	nlrForBox_Generate(t, str);
	n_WordUpDown = i_ListFilter;
	Xuat_WordUpDown(WordUpDown, i_ListFilter, pos_list_filter);
}
void Box_Generate(COORD posNhapTu, COORD pos_list_filter, int nTimKiem, tree t){
	node *p;
	char c;
	char strDefault[]="..FULL"; 
	unsigned int countNhapTu = 0, MaxNhapTu = 18; 
	char str[30]; strcpy(str, ""); bool flagFilter = false;
	COORD posHienTai;	
	i_ListFilter = 0;
	
	_Gen_At_FirstWord(t, strDefault);
	
	GoToXY(posNhapTu.X, posNhapTu.Y);//Ve vi tri Tim kiem

	do{
		c = getch();
		switch(c) {
			case 27:
				setcolor(15 + 0 * 16);
				GoToXY(40,29);
				printf("Dang cap nhat lai danh sach tu dien....\n");
				_File_WriteFromTree(FileName, countChar, array, countline, NghiaGocExcept, maxEx);
				exit(0);
				break;
			case '1':
				p = TimTu(t, WordUpDown[0].NghiaGoc);
				_Text_To_Speech(p->data.NghiaGoc);
				break;
			case '2':{
				setcolor(15 + 0 * 16);
				if (Confirm("Sua tu")==true){
					p = TimTu(t, WordUpDown[0].NghiaGoc);
					SuaTu(p->data);
					return;
				}
				else{
				//	system("cls");
				//	setcolor(15 + 0 * 16);					
					return;
				}
			}
			case '3': {
				setcolor(15 + 0 * 16);
				if (Confirm("Them tu")==true){
					Menu3_add(t);
					//system("cls");
					//UI_main();
					return;
				}
				else{
					//system("cls");
					//setcolor(15 + 0 * 16);
					//UI_main();	
					return;
				}
			}
		
			case '4':{
				setcolor(15 + 0 * 16);
				if (Confirm("Xoa tu")==true){
					p = TimTu(t, WordUpDown[0].NghiaGoc);
					strcpy(NghiaGocExcept[maxEx], WordUpDown[0].NghiaGoc);
					maxEx++;
					t=deleteNode(t, p->data);
					
					
					
					MenuFChoice(t,c);
					
					//system("cls");
					//UI_main();	
					return;
				}
				else{	
				//	system("cls");
				//	setcolor(15 + 0 * 16);
				//	UI_main();	
					return;
				}
			}
			case VK_RETURN://enter
				break;
			case 8: //backspace
				if (str[0] == '\0') continue;// ko co filter
				GoToXY(posNhapTu.X, posNhapTu.Y);//doi con tro ve vi tri ban dau
	
				_StringDeleteAt(str, strlen(str)-1);//xoa ki tu cuoi cung cua str
				printf("%s ", str);
				
				posHienTai = GetXY();//lay con tro hien tai
				
				GoToXY(posHienTai.X - 1, posHienTai.Y);//doi con tro ve vi tri truoc do', de che lap' khoang trang
				
				if (countNhapTu >0 ) countNhapTu --;
				goto eraserFiler;
			case 80: //down
					
					if(stricmp(WordUpDown[0].NghiaGoc, WordUpDown[n_WordUpDown - 1].NghiaGoc )== 0 ||  FilterMatch==false) continue;
					
					EraserCharRange(pos_list_filter.X, pos_list_filter.Y, iMaxLenAline, iMaxFilter);
					EraserCharRange(38, 8, 70, 13);
					
				 	i_CheckStartWordUpDown = 0;
				 	iStartWordUpDown++;
					i_ListFilter = 0;		
					if (str[0] == '\0') 				
						_Update_Box_Gen(t, strDefault);
					else
						_Update_Box_Gen(t, str);

					XuatDanhSachWord (WordUpDown[0], 38, 8,91);	
					
					if (flagFilter)							
						GoToXY(posHienTai.X, posHienTai.Y);
					else
						GoToXY(posNhapTu.X, posNhapTu.Y);						
				
					continue;			
	
			case 72: //up
					if (iStartWordUpDown >0 && FilterMatch==true){
						EraserCharRange(pos_list_filter.X, pos_list_filter.Y, iMaxLenAline, iMaxFilter);
						EraserCharRange(38, 8, 70, 13);
						
						i_CheckStartWordUpDown = 0;
						--iStartWordUpDown;
						i_ListFilter = 0;
						if (str[0] == '\0') 				
							_Update_Box_Gen(t, strDefault);
						else
							_Update_Box_Gen(t, str);
						XuatDanhSachWord (WordUpDown[0], 38, 8,91);
						
						if (flagFilter)							
							GoToXY(posHienTai.X, posHienTai.Y);
						else
							GoToXY(posNhapTu.X, posNhapTu.Y);											
					}

					continue;				
		}
		if ((c >=65 && c <=122) || c==32 || c==45){ // phim a-z, va spacebar hooc '-' dc thuc hien
			if (countNhapTu >= MaxNhapTu) continue;
			countNhapTu++;
						
			flagFilter = true;
			strcat(str, Convert_Char_To_String(c));
			printf("%c", c);
			
			eraserFiler:
			i_ListFilter = 0;
			
			posHienTai = GetXY();//lay con tro hien tai
			EraserCharRange(pos_list_filter.X, pos_list_filter.Y, iMaxLenAline, iMaxFilter);
			GoToXY(posHienTai.X, posHienTai.Y);
			
			_Update_Box_Gen(t, str);

			if (WordUpDown[0].NghiaGoc[0] != '\0' && FilterMatch==true){ //Co filter xuat hien dau tien trong Box list filter				
				EraserCharRange(38, 8, 70, 13);//remove detail word
				XuatDanhSachWord (WordUpDown[0], 38, 8,91);
			}else{
				EraserCharRange(38, 8, 70, 13);			
			}
			if (str[0] == '\0')
				_Gen_At_FirstWord(t, strDefault);
	
			GoToXY(posHienTai.X, posHienTai.Y);
		}

	}while(true);
	
	//return str;
}
//===================================================End_Generate_Box=======================

void MAINmenu(tree t){
	char choice;
	system("cls");
	setcolor(15 + 0 * 16);
	UI_main();

	Box_Generate(posNhapTu, pos_list_filter, iMaxFilter, t);
}
