#include "Task1.h"
#include "Graphs.h"

//Задача №1
//	Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
//Выполнил Виль В.В.

void task1()
{
	int** graph;
	int size = 4;
	graph = ReadGraphFromFile("D:\\graph.txt", size);
	PrintGraph(graph, size);

	FreeGraph(graph, size);
}