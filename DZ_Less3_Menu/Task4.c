#include "Task4.h"

//Задача 4
//	Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
//Выполнид Виль В. В.

void task4()
{
	int* arr1;
	int* arr2;
	int* arr3;

	int arrsize = 251;

	arr1 = (int*)calloc(arrsize, sizeof(int));
	arr2 = (int*)calloc(arrsize, sizeof(int));
	arr3 = (int*)calloc(arrsize, sizeof(int));
	srand(time(0));
	for (int i = 0; i < arrsize; i++)
	{
		int t = rand() % 100;
		arr1[i] = t;
		arr2[i] = t;
		arr3[i] = t;
	}

	printf("Несортированный массив:\n");
	printArr(arr1, arrsize);

	printf("1) Метод пузырька:\n");
	printf("2) Метод оптимизированного пузырька:\n");
	printf("3) Шейкерная сортировка:\n");

	printf("\n1) Количество операций сравнения - aсимптотическая сложность : %d - %d\n", 
				BubleSort(arr1, arrsize), (arrsize * arrsize) - arrsize);
	printf("2) Количество операций сравнения - aсимптотическая сложность : %d - %d\n", 
				OptimizeBuble(arr2, arrsize), ((arrsize * arrsize) - arrsize) / 2);
	printf("3) Количество операций сравнения - aсимптотическая сложность : %d - %d\n",
		ShekerSort(arr3, arrsize), (arrsize * arrsize) / 2);
	printf("\nСортирванные массивы\n");
	printf("1) ");
	printArr(arr1, arrsize);
	printf("2) ");
	printArr(arr2, arrsize);
	printf("3) ");
	printArr(arr3, arrsize);
}