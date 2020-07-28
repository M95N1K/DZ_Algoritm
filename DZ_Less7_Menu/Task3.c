#include "Task3.h"
#include "Graphs.h"

//Задача №3
//	Написать функцию обхода графа в ширину.
//Выполнил Виль В.В.

void task3()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	
	printf("\n");
	BreadthCrawl(graph, size, 1);
	FreeGraph(graph, size);
}