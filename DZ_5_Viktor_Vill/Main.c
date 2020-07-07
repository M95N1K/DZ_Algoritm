#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

// Задание №5
//	С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
// Выполнил Виль В. В.

int main()
{
	int answ = 0;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("Введите номер месяца\n");

	while ((scanf("%d",&answ) != 1) || !(0 < answ && answ < 13))
	{
		system("cls");
		printf("Введите номер месяца (От 1 До 12)\n");
		while (getchar() != '\n');
	}

	switch (answ)
	{
	case 1:
	case 2:
	case 12:
		printf("Холодная Зима");
		break;
	case 3:
	case 4:
	case 5:
		printf("Зеленая Весна");
		break;
	case 6:
	case 7:
	case 8:
		printf("Жаркое Лето");
		break;
	case 9:
	case 10:
	case 11:
		printf("Желтая Осень");
		break;
	default:
		break;
	}

	getch();
	return 0;
}