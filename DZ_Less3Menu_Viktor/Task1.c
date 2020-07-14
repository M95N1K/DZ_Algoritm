#include "Task1.h"
#pragma warning(disable : 4996)
#define ARRSIZE 20

void swap(int* Arrays[], int i, int j)
{
	int tmp = Arrays[i];
	Arrays[i] = Arrays[j];
	Arrays[j] = tmp;
}

void printArr(int Arrays[], int N)
{
	for (int i = 0; i < N;i++)
	{
		printf("%d ", Arrays[i]);
	}
	printf("\n");
}

int BubleSort(int* Arrays[], int N) //O(n^2)
{
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Arrays[j] > Arrays[j+1])
			{
				swap(Arrays, j, j+1);
			}
			count++;
		}
	}
	return count;
}

int OptimizeBubleSort(int* Arrays[], int N) //O(n^2+(2/(1+n%2))n)
{
	int count = 0;
	int flag = 1;

	while (flag)
	{
		flag = 0;
		for (int i = 0; i < N ;i++)
		{
			if (Arrays[i] > Arrays[i+1])
			{
				swap(Arrays, i, i+1);
				flag = 1;
			}
			count++;
		}
		for (int i = N; i > 0; i--)
		{
			if (Arrays[i] < Arrays[i - 1])
			{
				swap(Arrays, i, i - 1);
				flag = 1;
			}
			count++;
		}
	}

	return count;
}

void task1()
{
		//ARRSIZE = 20
	int arr[ARRSIZE] = { 40,33,553,64,554,20,96,84,67,55,32,12,54,57,95,85,51,42,89,56 };
	int arr2[ARRSIZE] = { 40,33,553,64,554,20,96,84,67,55,32,12,54,57,95,85,51,42,89,56 };
	int arr3[ARRSIZE] = { 40,33,553,64,554,20,96,84,67,55,32,12,54,57,95,85,51,42,89,56 };

	/*int arr[ARRSIZE] = { 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2 };
	int arr2[ARRSIZE] = { 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2 };
	int arr3[ARRSIZE] = { 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2 };*/

		//ARRSIZE = 23;
	//int arr[ARRSIZE] = { 22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	//int arr2[ARRSIZE] = {22, 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	//int arr3[ARRSIZE] = {22, 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };



	printArr(arr, ARRSIZE);
	printf("Количество операций сравнения несортированного массива (BubleSort): %d\n", BubleSort(arr2, ARRSIZE));
	printf("Асимптотическая сложность: %d\n", ARRSIZE * ARRSIZE);
	printArr(arr2, ARRSIZE);
	
	printf("Количество операций сравнения несортированного массива (OptimizeBubleSort): %d\n", OptimizeBubleSort(arr3, ARRSIZE));
	printf("Асимптотическая сложность: %d\n", (ARRSIZE * ARRSIZE)+(2/(1+ARRSIZE % 2))*ARRSIZE);
	printArr(arr3, ARRSIZE);

	printf("Количество операций сравнения сортированного массива (BubleSort): %d\n", BubleSort(arr2, ARRSIZE));

	printf("Количество операций сравнения сортированного массива (OptimizeBubleSort): %d\n", OptimizeBubleSort(arr3, ARRSIZE));
	

}
