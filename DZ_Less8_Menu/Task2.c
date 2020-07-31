#include "Task2.h"
#include "UMargeSort.h"
#include "UArrays.h"

//Задание №3
//	 *Реализовать сортировку слиянием.
//Выполнил Виль В.В.

void task2()
{
	int size = 100;
	int* a = CreatArray(size);
	RandomizeArray(a, size, 100);
	PrintArray(a, size);
	printf("\n");
	int c = MargeSort(a, 0, size-1);

	PrintArray(a, size);

	printf("%d", c);
	free(a);
}