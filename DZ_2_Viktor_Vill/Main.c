#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)

// Задание №2
//	Найти максимальное из четырех чисел. Массивы не использовать.
// Выполнил Виль В. В.

int main()
{
	int a, b, c, d;
	int count;

	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("Введите четрые целых числа:\n");

	count = 1;

	while (count <= 4)
	{
		printf("%d %s: ", count, "число");
		switch (count)
		{
		case 1:
			scanf("%d", &a);
			break;
		case 2:
			scanf("%d", &b);
			break;
		case 3:
			scanf("%d", &c);
			break;
		case 4:
			scanf("%d", &d);
			break;
		default:
			break;
		}
		count++;
	}

	if (a < b)
		a = b;
	if (c < d)
		c = d;
	if (a < c)
		a = c;

	printf("%s %d", "Максимальное число:", a);
	getch();
	return 0;
}