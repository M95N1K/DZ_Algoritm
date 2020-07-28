#include "Graphs.h"
#pragma warning(disable : 4996)

void PrintGraph(int** graph, int size)
{
	printf("%5c", ' ');
	for (int i = 0; i < size;i++)
		printf("%5c", 'A' + i);
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%5c", 'A' + i);
		for (int j = 0; j < size; j++)
			printf("%5d", graph[i][j]);
		printf("\n");
	}
}

int** GraphMemLoc(int size)
{
	int** result = NULL;
	result = (int**)calloc(size, sizeof(int*));
	for (int i = 0;i < size;i++)
		result[i] = (int*)calloc(size, sizeof(int));
	return result;
}

int** ReadGraphFromFile(char* fileName,int size)
{
	int** result;
	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Ошибка открытия файла %s",fileName);
		return NULL;
	}
	result = GraphMemLoc(size);
	for (int i = 0; i < size ;i++)
		for(int j = 0; j < size;j++)
			if (0 == fscanf(file, "%d", &result[i][j]))
			{
				printf("Ошибка чтения данных");
				break;
			}
	fclose(file);
	return result;
}

void DepthCrawl(int** graph, int size)
{

}

void BreadthCrawl(int** graph, int size)
{
	
}

void FreeMem(int** graph, int size)
{
	for (int i = 0; i < size; i++)
		free(graph[i]);
	free(graph);
}