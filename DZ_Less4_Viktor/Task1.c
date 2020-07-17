#include "Task1.h"
#define N 5
#define M 5

//Задача №1
//	Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
//Выполнил Виль В.В.

void print(int n, int m, int a[N][M])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
			printf("%6d", a[i][j]);
		printf("\n");
	}
}

void task1()
{
	int i, j;
	int A[N][M];
	int map[N][M] =
	{
		{1,1,1,1,1},
		{0,1,1,1,1},
		{1,0,1,1,0},
		{1,1,1,1,1},
		{1,1,1,1,1}
	};

	for (j = 0; j < M;j++)
	{
		A[0][j] = 1 * map[0][j];
	}

	for (i = 1; i < N;i++)
	{
		A[i][0] = 1 * map[i][0];
		for (j = 1; j < M; j++)
		{
			A[i][j] = (A[i - 1][j] + A[i][j - 1]) * map[i][j];
		}
	}

	print(N, M, A);
}