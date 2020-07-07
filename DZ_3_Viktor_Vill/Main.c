#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

// Задание №3
//	Написать программу обмена значениями двух целочисленных переменных:
//		a. с использованием третьей переменной;
//		b.* без использования третьей переменной.
// Выполнил Виль В. В.

int menu()
{
	int answ;

	while (1)
	{
		printf("Выберите алгоритм действия:\n");
		printf("\t 1: Поменять числа местами с помощью третьей переменной\n");
		printf("\t 2: Поменять числа местами математическим способом\n");
		printf("\t 3: Поменять числа местами используя XOR\n");
		if (scanf("%d", &answ) != 1 || !(answ == 1 || answ == 2 || answ == 3))
		{
			system("cls");
			printf("Неверный ввод!!! Попробуйте еще раз...\n");
			while (getchar() != '\n');
			continue;
		}
		return answ;
	}
}

int main()
{
	int a, b;
	int tmp;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("Введите 2 целых числа:\n");
	printf("Число A: ");
	scanf("%d", &a);
	printf("Число B: ");
	scanf("%d", &b);

	switch (menu())
	{
		case 1:
			tmp = a;
			a = b;
			b = tmp;
			break;
		case 2:
			a = a + b;
			b = a - b;
			a = a - b;
			break;
		case 3:
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			break;
		default:
			break;
	}
	printf("%s %d\n%s %d\n", "Число А:", a, "Число B:", b);

	getch();
	return 0;
}