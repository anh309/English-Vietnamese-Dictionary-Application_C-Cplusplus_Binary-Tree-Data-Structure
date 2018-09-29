#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const wchar_t *GetWC(const char *c)
{
    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);

    return wc;
}

void _FileOverWrite (char *FileName, char *text){ //update
	FILE *f;
	f = _wfopen(GetWC(FileName), L"w+, ccs=UTF-8"); //create UTF-8 file
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	fclose(f);
	
	f= fopen(FileName, "a");	//append text to file
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	fprintf(f, text);
	fclose(f);
}

int _FileCountLines (char* FileName){
    FILE *fp;
    int count = 0;
    char c; 
    
    fp = fopen(FileName, "r");
 
    if (fp == NULL)
    {
        printf("Could not open file %s", FileName);
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') 
            count = count + 1;
 	count++;

    fclose(fp);
    return count;
}

int _FileCountChar (char* FileName){
	int count = 0;
	FILE *file = fopen(FileName, "r");
	if (file) {	
	    while ((getc(file)) != EOF)
	       count++;
	    fclose(file);
	}
	return count;
}

char* _FileRead (char* FileName){
    char _char;
	char *text = (char *)malloc(sizeof(char) * _FileCountChar (FileName));
	
	int count = 0;
    FILE* file = fopen(FileName, "r");

   	if (file) {	
	    while ((_char = getc(file)) != EOF){ //getline
	    	if (_char == '\n')
	    		text[count] = '\n';
    		else
    			text[count] = _char;
   			count++;
    	}
	    fclose(file);
	}
    return text;	
}

char** _FileListToArray (char* FileName){

	FILE* fp;
	int CountLine = _FileCountLines(FileName);
	char buffer[1024];
	
	char ** text = new char*[CountLine];
	
	for (int i=0; i<CountLine; i++){
		text[i] = new char[1024];
	}
	
    FILE* file = fopen(FileName, "r");
	int count = 0, i = 0;
 	char _char;
   	if (file) {	
	    while ((_char = getc(file)) != EOF){ //getline
	    	if (_char == '\n'){
	    		text[count][i] = '\0';
	    		count++; i=0;
	    	}
	    		
    		else
    			text[count][i++] = _char;
    	}
	    fclose(file);
	    return text;
	}
	
}