#include <stdio.h>
#include <locale.h>
#include "Task1.h"
#include "Task2.h"

#pragma warning(disable : 4996)

int main()
{
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	int num;
	printf("Выберите задачу для решения: \n");
	printf("\t1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека. \n");
	printf("\t2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. \n");
	printf("\t3. Реализовать очередь. \n");
	printf("\t4. Создать функцию, копирующую односвязный список. \n");
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
		task2();
		break;
	case 3:
		//task6();
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