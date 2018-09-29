#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** _StringSplit(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char**) malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

char * _StringDeleteAt (char *str, int pos){
	for (int i=pos; i<strlen(str); i++)
		str[i] = str[i+1];
	return str;
}

char * _StringAddAt (char* str, int pos, char charAdd){ // update

	char *str2 = new char[strlen(str) + 1];

	strcpy(str2,"");
	strcat(str2, str);	
	
	int length2= strlen(str2);
	for (int i=length2; i>pos; i--)
		str2[i] = str2[i-1];
	str2[pos] = charAdd;
	return str2;
}

char* Convert_Char_To_String (char word){
	char *chuoi= (char*) malloc(sizeof(char));;
	chuoi[0] = word;
	chuoi[1] = '\0';
	return chuoi;
}