#include "Graphs.h"
#pragma warning(disable : 4996)

int** ReadGraphFromFile(char* fileName,int size)
{
	int** result;
	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("������ �������� ����� %s",fileName);
		return NULL;
	}
	
}