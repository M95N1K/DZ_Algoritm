#include <stdio.h>
#include <locale.h>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task5.h"
#include "Task7.h"
#pragma warning(disable : 4996)

int menus()
{
	int answ;

	while (1)
	{
		printf("�������� ����� ������ ������:\n");
		printf("%s \n%s", "\t 1: ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);",
			"\t\t��� m-����� ���� � �����������, h - ���� � ������.\n");
		printf("\t 2: ����� ������������ �� ������� �����. ������� �� ������������.\n");
		printf("\t 3: �������� ��������� ������ ���������� ���� ������������� ����������\n");
		printf("\t 4: � ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������.\n");
		printf("%s \n%s", "\t 5: � ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2).",
			"\t\t��������� ����������, ��������� ���� � ������ ����� ��� ���.\n");
		if (scanf("%d", &answ) != 1 || !(answ == 1 || answ == 2 || answ == 3 || answ == 4 || answ == 5))
		{
			system("cls");
			printf("�������� ����!!! ���������� ��� ���...\n");
			while (getchar() != '\n');
			continue;
		}
		return answ;
	}
}

int main()
{
	int ans;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	ans = menus();

	switch (ans)
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
		task5();
		break;
	case 5:
		task7();
		break;

	default:
		break;
	}


	getch();
	return 0;
}