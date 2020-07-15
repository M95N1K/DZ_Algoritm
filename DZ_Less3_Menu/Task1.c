#include "Task1.h"

//Задание 1
//	Попробовать оптимизировать пузырьковую сортировку. 
//	Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. 
//	Написать функции сортировки, которые возвращают количество операций.
//Выполнил Виль В. В.

void swap(int* Arrays[], int a, int b)
{
	int tmp = Arrays[a];
	Arrays[a] = Arrays[b];
	Arrays[b] = tmp;
}

void printArr(int Arrays[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", Arrays[i]);
	}
	printf("\n");
}

int BubleSort(int* Arrays[], int N) //O(n^2-n)
{
	int count = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0; j < N - 1;j++)
		{
			if (Arrays[j] > Arrays[j + 1])
				swap(Arrays, j, j + 1);
			count++;
		}
	}
	return count;
}

int OptimizeBuble(int* Arrays[], int N) //O((n^2-n)/2)
{
	int count = 0;
	int flag = 1;
	int r = N;

	while (flag && r > 0)
	{
		flag = 0;
		for (int j = 0; j < r - 1;j++)
		{
			if (Arrays[j] > Arrays[j + 1])
			{
				flag = 1;
				swap(Arrays, j, j + 1);
			}
			count++;
		}
		r--;
	}

	return count;
}

void task1()
{
	int *arr1;
	int *arr2;
	
	int arrsize = 20;

	arr1 = (int*)calloc(arrsize, sizeof(int));
	arr2 = (int*)calloc(arrsize, sizeof(int));
	srand(time(0));
	for (int i = 0; i < arrsize; i++)
	{
		int t = rand()%100;
		arr1[i] = t;
		arr2[i] = t;
	}

	printf("Несортированный массив:\n");
	printArr(arr1, arrsize);

	printf("Cортированный массив методом пузырька:\n");
	printf("Количество операций сравнения: %d\n",BubleSort(arr1,arrsize));
	printf("Асимптотическая сложность: %d\n",(arrsize*arrsize)-arrsize);
	printArr(arr1, arrsize);
	printf("\nCортированный массив методом оптимизированного пузырька:\n");
	printf("Количество операций сравнения: %d\n", OptimizeBuble(arr2, arrsize));
	printf("Асимптотическая сложность: %d\n", ((arrsize * arrsize) - arrsize)/2);
	printArr(arr2, arrsize);
	printf("Количество операций сравнения при сортированном массиве: %d\n", BubleSort(arr1, arrsize));
	printf("Количество операций сравнения при сортированном массиве: %d\n", OptimizeBuble(arr2, arrsize));


	free(arr1);
	free(arr2);
}