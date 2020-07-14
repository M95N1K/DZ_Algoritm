#include "Task2.h"
#pragma warning(disable : 4996)
#define ARRSIZE 20

int shekerSort(int* Arrays[], int N) //O((n^2+n)/2)
{
	int count = 0;
	int flag = 1;
	int l = 0;
	int r = N;
	while (flag)
	{
		flag = 0;
		for (int i = l; i < r;i++)
		{
			if (Arrays[i] > Arrays[i + 1])
			{
				swap(Arrays, i, i + 1);
				flag = 1;
			}
			count++;
		}
		r--;
		for (int i = r; i > l; i--)
		{
			if (Arrays[i] < Arrays[i - 1])
			{
				swap(Arrays, i, i - 1);
				flag = 1;
			}
			count++;
		}
		l++;
	}

	return count;
}

void task2()
{
	//ARRSIZE = 20
	int arr[ARRSIZE] = { 40,33,553,64,554,20,96,84,67,55,32,12,54,57,95,85,51,42,89,56 };
	int arr3[ARRSIZE] = { 40,33,553,64,554,20,96,84,67,55,32,12,54,57,95,85,51,42,89,56 };

	/*int arr[ARRSIZE] = { 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2 };
	int arr3[ARRSIZE] = { 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2 };*/

	//  //ARRSIZE = 23;
	//int arr[ARRSIZE] = { 22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	//int arr3[ARRSIZE] = {22, 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };



	printArr(arr, ARRSIZE);
	printf("���������� �������� ��������� ���������������� ������� (OptimizeBubleSort): %d\n", shekerSort(arr3, ARRSIZE));
	printf("��������������� ���������: %d\n", ((ARRSIZE * ARRSIZE)+ARRSIZE)/2);
	printArr(arr3, ARRSIZE);

	printf("���������� �������� ��������� �������������� ������� (OptimizeBubleSort): %d\n", shekerSort(arr3, ARRSIZE));
}