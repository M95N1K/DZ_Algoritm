#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define Point struct Points

// ������� �7
//	� ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2). 
//	��������� ����������, ��������� ���� � ������ ����� ��� ���.
// �������� ���� �. �.

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
		printf("���������� ������ (������: X Y) (�� 1 �� 8)\n");
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
	printf("������� ���������� 2-� ������ �� ��������� �����\n");
	printf("���������� ������ ������ (������: X Y)");
	a = GetPoint();
	printf("���������� ������ ������ (������: X Y)");
	b = GetPoint();

#pragma region ��� ����� ������� � �����
	// ���� ���������� X � Y ������ (��� �� ������) ���� �����
	// ���� X ������, � Y �� ������ (��� ��������) ���� ������

	/*if ((a.x % 2 == 0 && a.y % 2 == 0) || (a.x % 2 != 0 && a.y % 2 != 0))
	{
		if ((b.x % 2 == 0 && b.y % 2 == 0) || (b.x % 2 != 0 && b.y % 2 != 0))
			printf("����� ����������");
		else
			printf("����� ������");
	}
	else if ((a.x % 2 == 0 && a.y % 2 != 0) || (a.x % 2 != 0 && a.y % 2 == 0))
	{
		if ((b.x % 2 == 0 && b.y % 2 != 0) || (b.x % 2 != 0 && b.y % 2 == 0))
			printf("����� ����������");
		else
			printf("����� ������");
	}*/
#pragma endregion


	//���� ����� X � Y ������ �� ���� �����, ����� ������
	if (IsWhite(a) && IsWhite(b))
	{
		printf("����� ����������");
	}
	else
		printf("����� ������");

	getch();
	return 0;
}