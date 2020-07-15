#include "Task3.h"
#pragma warning(disable : 4996)

//Задание 3
//	Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
//	Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//Выполнил Виль В.В.

int BinSearch(int* Arrays[], int N, int findNum)
{
	int result = -1;
	int l = 0;
	int r = N;
	int flag = 1;
	while (flag && r > l)
	{
		int m = ((r - l) / 2)+l;
		if (findNum > Arrays[m])
			l = m + 1;
		else if (findNum < Arrays[m])
			r = m - 1;
		else
		{
			result = m;
			flag = 0;
		}
	}
	return result;
}

void task3()
{
	int* arr1;

	int arrsize = 20;
	arr1 = (int*)calloc(arrsize, sizeof(int));
	for (int i = 0; i < arrsize; i++)
	{
		arr1[i] = i+13;
	}
	printf("Массив:\n");
	printArr(arr1, arrsize);

	int ans;
	printf("Введите искомое число: ");
	scanf("%d", &ans);

	int r = BinSearch(arr1, arrsize, ans);
	if (r != -1)
	{
		printf("Элемент %d находится в ячейке %d",arr1[r],r);
	}
}