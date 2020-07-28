#include "Graphs.h"
#include "UQueue.h"
#pragma warning(disable : 4996)

//Задача №4
//	*Создать библиотеку функций для работы с графами.
//Выполнил Виль В.В.

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

int** ReadGraphFromFile(char* fileName, int size)
{
	int** result;
	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Ошибка открытия файла %s", fileName);
		return NULL;
	}
	result = GraphMemLoc(size);
	for (int i = 0; i < size;i++)
		for (int j = 0; j < size;j++)
			if (0 == fscanf(file, "%d", &result[i][j]))
			{
				printf("Ошибка чтения данных");
				break;
			}
	fclose(file);
	return result;
}

void RecurciveDepthCrawl(int** graph, int size, int startVertex, int* visited)
{
	visited[startVertex - 1] = 1;
	printf("%c ", 'A' + startVertex - 1);
	for (int i = 0; i < size; i++)
	{
		if (graph[startVertex - 1][i] != 0 && visited[i] == 0)
		{
			RecurciveDepthCrawl(graph, size, i + 1, visited);
		}
	}
}

void DepthCrawl(int** graph, int size, int startVertex)
{
	if (startVertex < 1 || startVertex > size)
	{
		printf("Неверно указанная стартовая вершина. За стартовую вершину возмется первая\n");
		startVertex = 1;
	}
	int* visited = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		visited[i] = 0;
	printf("Обойденные вершины:\n ");
	RecurciveDepthCrawl(graph, size, startVertex, visited);

	free(visited);
}

void BreadthCrawl(int** graph, int size, int startVertex)
{
	int* visited;
	visited = (int*)malloc(size * sizeof(int));
	
	for (int i = 0; i < size;i++)
		visited[i] = 1;
	int flag = 0;

	if (startVertex < 1 || startVertex > size)
	{
		printf("Неверно указанная стартовая вершина. За стартовую вершину возмется первая\n");
		startVertex = 1;
	}

	visited[startVertex - 1] = 2;
	Queue q;
	q.Count = 0;
	AddQueue(&q, startVertex - 1);
	printf("Обойденные вершины:\n ");
	int tmp;
	while (flag == 0)
	{
		flag = 1;
		tmp = GetQueue(&q);
		if (visited[tmp] == 2)
		{
			flag = 0;
			for (int j = 0;j < size; j++)
			{
				if (graph[tmp][j] != 0 && visited[j] == 1)
				{
					visited[j] = 2;
					AddQueue(&q, j);
				}
			}
			printf("%c ", 'A' + tmp);
			visited[tmp] = 3;
		}

	}
	free(visited);
	FreeQueue(&q);
}

void FreeGraph(int** graph, int size)
{
	for (int i = 0; i < size; i++)
		free(graph[i]);
	free(graph);
}