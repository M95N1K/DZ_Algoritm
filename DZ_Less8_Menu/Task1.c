#include "Task1.h"
#include "UCountSort.h"
#include "UArrays.h"

//Задание №1
//	Реализовать сортировку подсчетом.
//Выполнил Виль В.В.

void task1()
{
	srand(2);
	int size = 100;
	int* arr = CreatArray(size);
	RandomizeArray(arr, size, 100);
	PrintArray(arr, size);

	printf("\n");

	int c = CountSort(arr, size);

	PrintArray(arr, size);
	printf("\n");

	printf("%d",c);
	free(arr);
}