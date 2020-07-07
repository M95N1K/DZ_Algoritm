#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define Point struct Points

// Задание №7
//	С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). 
//	Требуется определить, относятся поля к одному цвету или нет.
// Выполнил Виль В. В.

struct Points
{
	int x, y;
};

Point GetPoint()
{
	Point a;
	while ((scanf("%d %d", &a.x, &a.y) != 2) || !(a.x > 0 && a.x < 9 && a.y > 0 && a.y < 9))
	{
		system("cls");
		printf("Координаты клетки (формат: X Y) (От 1 До 8)\n");
		while (getchar() != '\n');
	}
	return a;
}

int IsWhite(Point a)
{
	if ((a.x + a.y) % 2 == 0)
		return 1;
	return 0;
}

int main()
{
	Point a, b;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("Введите координаты 2-х клеток на шахмотной доске\n");
	printf("Координаты первой клетки (формат: X Y)");
	a = GetPoint();
	printf("Координаты второй клетки (формат: X Y)");
	b = GetPoint();

#pragma region Ход мысли начался с этого
	// Если координаты X и Y четные (или не четные) цвет белый
	// Есди X четная, а Y не четная (или наоборот) цвет черный

	/*if ((a.x % 2 == 0 && a.y % 2 == 0) || (a.x % 2 != 0 && a.y % 2 != 0))
	{
		if ((b.x % 2 == 0 && b.y % 2 == 0) || (b.x % 2 != 0 && b.y % 2 != 0))
			printf("Цвета одинаковые");
		else
			printf("Цвета разные");
	}
	else if ((a.x % 2 == 0 && a.y % 2 != 0) || (a.x % 2 != 0 && a.y % 2 == 0))
	{
		if ((b.x % 2 == 0 && b.y % 2 != 0) || (b.x % 2 != 0 && b.y % 2 == 0))
			printf("Цвета одинаковые");
		else
			printf("Цвета разные");
	}*/
#pragma endregion


	//Если сумма X и Y четная то цвет белый, иначе черный
	if (IsWhite(a) && IsWhite(b))
	{
		printf("Цвета одинаковые");
	}
	else
		printf("Цвета разные");

	getch();
	return 0;
}