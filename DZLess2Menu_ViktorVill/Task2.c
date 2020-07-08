#include "Task2.h"
#pragma warning(disable : 4996)
// Задание №2
//	Реализовать функцию возведения числа a в степень b:
//		a. Без рекурсии.
//		b. Рекурсивно.
//		c. *Рекурсивно, используя свойство четности степени.
// Выполнил Виль В.В.

int task2()
{
	int a, b;
	int num = 0;
	printf("Задача возведения числа A в степень B: \n");
	printf("Введите числа A и B через пробел: \n");

	while ((scanf("%d %d", &a,&b) != 2))
	{
		printf("Неверный ввод");
		while (getchar() != '\n');
	}

	printf("Выберите метод решения: \n");
	printf("\t1. Без рекурсии: \n");
	printf("\t2. Рекурсивно: \n");
	printf("\t3. *Рекурсивно, используя свойство четности степени: \n");

	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num ==3))
	{
		printf("Неверный ввод");
		while (getchar() != '\n');
	}

	switch (num)
	{
	case 1:
		printf("%d",Pow1(a,b));
		break;
	case 2:
		printf("%d", Pow2(a, b));
		break;
	case 3:
		printf("%d", Pow3(a, b));
		break;
	default:
		break;
	}

	return 0;
}

long Pow1(int a, int b)
{
	if (b == 0)
		return 1;

	int tmp=b;
	long result=1;
	while (tmp)
	{
		result = result * a;
		tmp--;
	}
	return result;
}

long Pow2(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	else return a * Pow2(a, b - 1);
}

long Pow3(int a, int b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a;
	else if (b % 2 == 0)
	{
		int tmp = Pow3(a, b / 2);
		return tmp * tmp;
	}
	else return Pow3(a, b - 1) * a;
}
