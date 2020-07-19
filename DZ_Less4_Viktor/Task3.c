#include "Task3.h"
#pragma warning(disable : 4996)
#define M 3
#define N 4
#define POINT struct Point

//Задание 3
//	Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу.
//Выполнил Виль В.В.

struct Point
{
	int x;
	int y;
};

int board[M][N];
POINT NextStep(int x, int y, int verStep)
{
	POINT result;
	if (verStep == 1)
	{
		result.x = x - 1;
		result.y = y + 2;
	}
	else if (verStep == 2)
	{
		result.x = x + 1;
		result.y = y + 2;
	}
	else if (verStep == 3)
	{
		result.x = x + 2;
		result.y = y + 1;
	}
	else if (verStep == 4)
	{
		result.x = x + 2;
		result.y = y - 1;
	}
	else if (verStep == 5)
	{
		result.x = x + 1;
		result.y = y - 2;
	}
	else if (verStep == 6)
	{
		result.x = x - 1;
		result.y = y - 2;
	}
	else if (verStep == 7)
	{
		result.x = x - 2;
		result.y = y - 1;
	}
	else if (verStep == 8)
	{
		result.x = x - 2;
		result.y = y + 1;
	}
	else if (verStep == 0)
	{
		result.x = x;
		result.y = y;
	}
	else 
	{
		result.x = -1;
		result.y = -1;
	}

	return result;
}

int StepHorse(POINT xy,int countStep)
{
	if (countStep <= 0)
		return 1;
	if (xy.x < 0 || xy.y < 0)
		return 0;
	if (xy.x >= M || xy.y >= N)
		return 0;
	if (board[xy.x][xy.y] == 1)
	{
		board[xy.x][xy.y] = 0;
		for (int v = 1; v <= 8;v++)
			if (StepHorse(NextStep(xy.x, xy.y, v), countStep - 1) == 1)
			{
				printf("%4d, %4d \n", xy.x, xy.y);
				return 1;
			}
		board[xy.x][xy.y] = 1;
	}
	return 0;
}

void task3()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 1;
		}

	if (StepHorse(NextStep(0, 0, 0), (M * N)) == 0)
		printf("Нет решения!!!");
}
