#include "Task2.h"
#include "Graphs.h"

//������ �2
//	�������� ����������� ������� ������ ����� � �������.
//�������� ���� �.�.

void task2()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	
	printf("\n");
	DepthCrawl(graph, size, 1);

	FreeGraph(graph, size);
}