#include "Task3.h"
#include "UQuickSort.h"

//������� �2
//	����������� ������� ����������.
//�������� ���� �.�.

void task3()
{
	int size = 1000;
	int* a = CreatArray(size);
	RandomizeArray(a, size, 100);
	PrintArray(a, size);
	printf("\n");
	int c = QuickSort(a, 0, size - 1);

	PrintArray(a, size);

	printf("%d", c);
	free(a);
}