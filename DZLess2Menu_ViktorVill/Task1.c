#include "Task1.h"
#pragma warning(disable : 4996)
// Задание №1
//	Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
// Выполнил Виль В.В.

int DecToBin(int num);

int task1()
{
	int num;
	printf("Введите число: \n");
	while ((scanf("%d", &num) != 1))
	{
		printf("Неверный ввод");
		while (getchar() != '\n');
	}

	printf("%d %s %d", num, "в двоичной системе", DecToBin(num));
}

int DecToBin(int num)
{
	if (num == 1)
		return 1;
	if (num % 2 == 0)
	{
		return DecToBin(num / 2) * 10;
	}
	else return DecToBin((num - 1) / 2) * 10 + 1;
}
