#include "Task1.h"

//������� 1
//	����������� �������������� ����������� ����������. 
//	�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������. 
//	�������� ������� ����������, ������� ���������� ���������� ��������.
//�������� ���� �. �.

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

	printf("��������������� ������:\n");
	printArr(arr1, arrsize);

	printf("C������������ ������ ������� ��������:\n");
	printf("���������� �������� ���������: %d\n",BubleSort(arr1,arrsize));
	printf("��������������� ���������: %d\n",(arrsize*arrsize)-arrsize);
	printArr(arr1, arrsize);
	printf("\nC������������ ������ ������� ����������������� ��������:\n");
	printf("���������� �������� ���������: %d\n", OptimizeBuble(arr2, arrsize));
	printf("��������������� ���������: %d\n", ((arrsize * arrsize) - arrsize)/2);
	printArr(arr2, arrsize);
	printf("���������� �������� ��������� ��� ������������� �������: %d\n", BubleSort(arr1, arrsize));
	printf("���������� �������� ��������� ��� ������������� �������: %d\n", OptimizeBuble(arr2, arrsize));


	free(arr1);
	free(arr2);
}