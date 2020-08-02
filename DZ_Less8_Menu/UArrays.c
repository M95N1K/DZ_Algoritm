#include "UArrays.h"


int* CreatArray(int len)
{
	return (int*)calloc(len, sizeof(int));
}

void PrintArray(int* arrays, int size)
{
	for (int i = 0; i < size;i++)
		printf("%d ", arrays[i]);
	printf("\n");
}

int MaxElement(int* arrays, int len)
{
	int result = arrays[0];
	for (int i = 0; i < len;i++)
		if (arrays[i] > result)
			result = arrays[i];
	return result;
}

void InitArray(int* arrays, int size)
{
	for (int i = 0; i < size;i++)
		arrays[i] = 0;
}

void RandomizeArray(int* arrays, int size, int max)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		arrays[i] = rand() % max;
}