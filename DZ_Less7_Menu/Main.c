#include <stdio.h>
#include <locale.h>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


#pragma warning(disable : 4996)

int main()
{
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	int num;
	printf("Выберите задачу для решения: \n");
	printf("\t1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран. \n");
	printf("\t2. Написать рекурсивную функцию обхода графа в глубину. \n");
	printf("\t3. Написать функцию обхода графа в ширину. \n");
	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num == 3))
	{
		printf("Неверный ввод");
		while (getchar() != '\n');
	}

	switch (num)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		break;
	}

	getch();
	return 0;
}