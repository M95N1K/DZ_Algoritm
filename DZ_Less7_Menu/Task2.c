#include "Task2.h"
#include "Graphs.h"

void task2()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	int mass = BreadthCrawl(graph, size, 0);
	printf("��� �����: %d", mass);
	FreeMem(graph, size);
}