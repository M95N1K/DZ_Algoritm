#include "Task1.h"
#include "Graphs.h"

//������ �1
//	�������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����.
//�������� ���� �.�.

void task1()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	PrintGraph(graph, size);

	FreeGraph(graph, size);
}