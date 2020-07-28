#include "Task1.h"
#include "Graphs.h"

void task1()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	PrintGraph(graph, size);

	FreeMem(graph, size);
}