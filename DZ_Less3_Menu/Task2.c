#include "Task2.h"
//Задание 2
//	Реализовать шейкерную сортировку
//Выполнил Виль В. В.

int ShekerSort(int* Arrays[], int N) //O((n^2)/2)
{
	int count = 0;
	int flag = 1;
	int r = N;
	int l = 0;

	while (flag && r > l)
	{
		flag = 0;
		for (int j = l; j < r - 1;j++)
		{
			if (Arrays[j] > Arrays[j + 1])
			{
				flag = 1;
				swap(Arrays, j, j + 1);
			}
			count++;
		}
		r--;
		for (int j = r; j > l;j--)
		{
			if (Arrays[j] < Arrays[j - 1])
			{
				flag = 1;
				swap(Arrays, j, j - 1);
			}
			count++;
		}
		l++;
	}

	return count;
}

void task2()
{
	int* arr1;

	int arrsize = 20;
	arr1 = (int*)calloc(arrsize, sizeof(int));
	srand(time(0));
	for (int i = 0; i < arrsize; i++)
	{
		int t = rand() % 100;
		arr1[i] = t;
	}

	printf("Несортированный массив:\n");
	printArr(arr1, arrsize);
	printf("Cортированный массив шейкерной сортировкой:\n");
	printf("Количество операций сравнения: %d\n", ShekerSort(arr1, arrsize));
	printf("Асимптотическая сложность: %d\n", (arrsize * arrsize)/ 2);
	printArr(arr1, arrsize);
}