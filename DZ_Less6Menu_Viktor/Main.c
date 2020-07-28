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
	printf("\t1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов. \n");
	printf("%s%s%s","\t2. Переписать программу, реализующую двоичное дерево поиска. \n",
				"\t\tа) Добавить в него обход дерева различными способами;\n",
				"\t\tб) Реализовать поиск в двоичном дереве поиска; \n");
	printf("\t3. Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер». \n");
	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num == 3 ))
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
	case 4:
		//task4();
		break;

	default:
		break;
	}

	getch();
	return 0;
}