#include "Task4.h"
#include "UArrays.h"
#include "UCountSort.h"
#include "UMargeSort.h"
#include "UQuickSort.h"

//Задание №4
//	Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.
//Выполнил Виль В.В.

void works(int size)
{
	int* a = CreatArray(size);
	int* b = CreatArray(size);
	int* d = CreatArray(size);
	RandomizeArray(a, size, 100);
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
		d[i] = a[i];
	}
	PrintArray(a, size);
	printf("\n");

	int c = CountSort(a, size);
	printf("CountSort %d\n", c);
	c = MargeSort(a, 0, size - 1);
	printf("MargeSort %d\n", c);
	c = QuickSort(a, 0, size - 1);
	printf("QuickSort %d\n", c);

	free(a);
	free(b);
	free(d);
}

void task4()
{
	works(100);
	printf("\n");
	getch();
	works(1000);
	printf("\n");
	getch();
	works(1000000);
	printf("\n");
	
}