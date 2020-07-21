#include <stdio.h>
#include <locale.h>
#include "Task1.h"

#pragma warning(disable : 4996)

int main()
{
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	int num;
	printf("Выберите задачу для решения: \n");
	printf("\t1. Oптимизировать пузырьковую сортировку. \n");
	printf("\t2. Реализовать шейкерную сортировку. \n");
	printf("\t3. Реализовать бинарный алгоритм поиска. \n");
	printf("\t4. Подсчитать количество операций для каждой из сортировок \n\t\tи сравнить его с асимптотической сложностью алгоритма. \n");
	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num == 3 || num == 4))
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
		//task2();
		break;
	case 3:
		//task3();
		break;
	case 4:
		//task4();
		break;

	default:
		break;
	}

	getch();
	return 0;
}