
#include "Lib/FileEx.cpp"
#include "Lib/StringEx.cpp"
	
struct _TuLoai{
	char Ten[50];
	char Nghia[50][100];
	int nNghia;
};

typedef struct _Word{
	char NghiaGoc[50];
	char PhienAm[100];
	_TuLoai TuLoai[5];
	int nTuLoai;
}_Word;

_Word EmptyStruct;