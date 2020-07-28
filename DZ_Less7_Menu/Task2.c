#include "Task2.h"
#include "Graphs.h"

//Задача №2
//	Написать рекурсивную функцию обхода графа в глубину.
//Выполнил Виль В.В.

void task2()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	
	printf("\n");
	DepthCrawl(graph, size, 1);

	FreeGraph(graph, size);
}