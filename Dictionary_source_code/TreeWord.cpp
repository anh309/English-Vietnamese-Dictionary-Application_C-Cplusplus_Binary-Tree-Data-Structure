
#include "StructWord.cpp"
struct node
{
    _Word data;
    node *pleft;
    node *pright;
    int height;
};

typedef node* tree;

void init (tree &t){
	t = NULL;
}
int Max(int a, int b);
 
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int Max(int a, int b)
{
    return (a > b)? a : b;
}
 
node* newNode(_Word word)
{
    node* p = new node;
    p->data   = word;
    p->pleft   = NULL;
    p->pright  = NULL;
    p->height = 1; 
    return(p);
}

node *rightRotate(node *y)
{
    node *x = y->pleft;
    node *T2 = x->pright;

    x->pright = y;
    y->pleft = T2;

    y->height = Max(height(y->pleft), height(y->pright))+1;
    x->height = Max(height(x->pleft), height(x->pright))+1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->pright;
    node *T2 = y->pleft;

    y->pleft = x;
    x->pright = T2;

    x->height = Max(height(x->pleft), height(x->pright))+1;
    y->height = Max(height(y->pleft), height(y->pright))+1;

    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->pleft) - height(N->pright);
}

node* insert(tree t, _Word data)
{

    if (t == NULL)
        return(newNode(data));
 
    if (stricmp(t->data.NghiaGoc, data.NghiaGoc) > 0)
        t->pleft  = insert(t->pleft, data);
    else if (stricmp(t->data.NghiaGoc,  data.NghiaGoc) < 0)
        t->pright = insert(t->pright, data);
    else 
        return t;

    t->height = 1 + Max(height(t->pleft),
                           height(t->pright));

    int balance = getBalance(t);

    if (balance > 1 && stricmp(data.NghiaGoc, t->pleft->data.NghiaGoc) < 0)
        return rightRotate(t);

    if (balance < -1 && stricmp(data.NghiaGoc, t->pright->data.NghiaGoc) > 0)
        return leftRotate(t);

    if (balance > 1 && stricmp(data.NghiaGoc, t->pleft->data.NghiaGoc) > 0)
    {
        t->pleft =  leftRotate(t->pleft);
        return rightRotate(t);
    }

    if (balance < -1 && stricmp(data.NghiaGoc, t->pright->data.NghiaGoc) < 0)
    {
        t->pright = rightRotate(t->pright);
        return leftRotate(t);
    }

    return t;
}
int PrintAuto_nextLine(char *s,int &ln,int x,int y,int MaxSpace){
	GoToXY(x,y+ln);
	for (int i =0; i<strlen(s);i++){
		printf("%c",s[i]);
		if(i%MaxSpace==0&&i>=MaxSpace){
			ln++;
			GoToXY(x,y+ln);
		}
	}
}
void XuatDanhSachWord (_Word word,int x,int y,int Space){ //73 mainmenu
	int k=0,m=0,ln=0;
	GoToXY(x,y);
	printf("Nghia Goc: %s",word.NghiaGoc);
	ln++;
	GoToXY(x,y+ln);
	printf("Phien Am: %s",word.PhienAm);
	ln++;
		
		for (k=0; k < word.nTuLoai; k++){

			PrintAuto_nextLine(word.TuLoai[k].Ten,ln,x,y,Space);
			ln++;
			for (m=0; m<word.TuLoai[k].nNghia; m++){
				
				PrintAuto_nextLine(word.TuLoai[k].Nghia[m],ln,x,y,Space);
				ln++;
			}			
		}
}


_Word _ArrayToOneWord (char **array, int fromWord, int EndWord){//update
	int iTuLoai = 0, iNghia = 0;
	char** tokens;
	char tempNghiaGocAndPhienAm[255];
	_Word TempWord = EmptyStruct;
	
	//InitWord (TempWord);

	for (int i=fromWord; i<=EndWord; i++){
		if (array[i][0] == '@'){//Nghia + Phien Am
	
				strcpy(tempNghiaGocAndPhienAm, array[i]); //update

				tokens = _StringSplit (tempNghiaGocAndPhienAm, '/');
				if (tokens){
					for (int j=0; tokens[j]; j++)
						if (j == 0){
							tokens[0] = _StringDeleteAt(tokens[0], 0);// xoa ki tu '@' truoc nghia goc. vd: @hello
							tokens[0] = _StringDeleteAt(tokens[0], strlen(tokens[0]) - 1);// xoa ki tu khoang trang cuoi cung`
							strcpy(TempWord.NghiaGoc, tokens[0]); 
						}
					
						else{							
							strcat(TempWord.PhienAm, tokens[j]);
						}		
				}else{
					array[i] = _StringDeleteAt(array[i], 0); // xoa ki tu '@' truoc nghia goc. vd: @hello
					tokens[0] = _StringDeleteAt(tokens[0], strlen(tokens[0]) - 1);// xoa ki tu khoang trang cuoi cung`
					strcpy(TempWord.NghiaGoc, array[i]); 
				}
		}
		else if (array[i][0] == '*'){
			if (iTuLoai > 0){
				TempWord.TuLoai[iTuLoai - 1].nNghia = iNghia;
				iNghia=0;
			}
			if (iTuLoai == 5){
				TempWord.nTuLoai = iTuLoai - 1;
				break;	
			}
			
			strcpy(TempWord.TuLoai[iTuLoai].Ten, array[i]);
			iTuLoai++;
		}
		else if (array[i][0] == '-'){
			if (iNghia == 2){
				TempWord.TuLoai[iTuLoai - 1].nNghia = iNghia;
			}
			else{
				strcpy(TempWord.TuLoai[iTuLoai - 1].Nghia[iNghia], array[i]);
				iNghia++;
			}			
				
			
		}	
		if (i==EndWord){
			TempWord.nTuLoai = iTuLoai;
			TempWord.TuLoai[iTuLoai - 1].nNghia = iNghia;
		}
	}
	
	return TempWord;
}

void _ArrayToTreeWord (char **array, int nArray, tree &t){

	bool checkEnd = false;
	int from, to;
	_Word tempWord;
	for (int i=0; i<nArray; i++){

		if (checkEnd == false && array[i][0] == '@'){

			checkEnd=true;
			from = i;
			continue;
		}
			
		if (checkEnd == true && (i == nArray-1 || array[i + 1][0] == NULL || array[i + 1][0] == '@')){	
				checkEnd = false;	
				to = i;
				tempWord = _ArrayToOneWord (array, from, to);
			 	t = insert(t, tempWord);
			}
	}
}

void nlr(tree t)
{
    if(t != NULL)
    {  
        nlr(t->pleft);
        XuatDanhSachWord (t->data,1,1,90);
        nlr(t->pright);
    }
}

void nlrXuatNghiaGoc(tree t){
	if(t != NULL)
    {
        
        nlrXuatNghiaGoc(t->pleft);
        printf ("\t%s\n",t->data.NghiaGoc);
        nlrXuatNghiaGoc(t->pright);
    }
/*		node *current,*pre;
	
	if(root == NULL)
	 return; 
	
	current = root;
	while(current != NULL)
	{                 
		if(current->pleft == NULL)
		{
		  printf ("\t%s\n",current->data.NghiaGoc);	
		  current = current->pright;      
		}    
		else
		{
		  pre = current->pleft;
		  while(pre->pleft != NULL && pre->pright != current)
		    pre = pre->pright;
		
		if(pre->pright == NULL)
		  {
		    pre->pright = current;
		    current = current->pleft;
		  }
		  else 
		  {
		    pre->pright = NULL;
		    printf ("\t%s\n",current->data.NghiaGoc);	
		    current = current->pright;      
		  }
		} 
	} 
	}*/
	
}

bool _Have_Exception (char *Word, char **NghiaGocExcept, int maxEx){
		for (int i=0; i<maxEx; i++){
			if (stricmp(Word, NghiaGocExcept[i]) == 0)
				return true;
		}	
		return false;
}
void _File_WriteFromTree(char *FileName, long countChar, char **arrayWord, int nArray, char **NghiaGocExcept, int maxEx){

	bool checkEnd = false;
	int from, to;
	char **tokens;
	
	char *text = new char[countChar];
	strcpy(text, "\n");
	char tempText[255];
	char tempToken[255];
	
	for (int i=0; i<nArray; i++){

		if (checkEnd == false && arrayWord[i][0] == '@'){

			checkEnd=true;
			from = i;
			continue;
		}
			
		if (checkEnd == true && (i == nArray-1 || arrayWord[i + 1][0] == NULL || arrayWord[i + 1][0] == '@')){	
				checkEnd = false;	
				to = i;
				strcpy(tempToken, arrayWord[from]);
				tokens = _StringSplit (tempToken, '/');//	@a /../ 
				tokens[0] = _StringDeleteAt(tokens[0], strlen(tokens[0]) - 1); //-> get "@a"
				tokens[0] = _StringDeleteAt(tokens[0], 0); //-> get "a"
				
				if (!_Have_Exception(tokens[0], NghiaGocExcept, maxEx)){
					
					for (int j=from; j<=to; j++){
						
						strcpy(tempText, arrayWord[j]);
						strcat(tempText, "\n");
						strcat(text, tempText);
					}		
				}
			}
	}
	text[strlen(text) - 1] ='\0'; //xoa ki tu \n o cuoi dong
	_FileOverWrite (FileName, text);
}
