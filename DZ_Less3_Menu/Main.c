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
	printf("�������� ������ ��� �������: \n");
	printf("\t1. ����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.: \n");
	printf("\t2. ����������� ������� ���������� ����� a � ������� b: \n");
	printf("\t3. ������ � ������������� \n");
	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num == 3))
	{
		printf("�������� ����");
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
		break;

	default:
		break;
	}

	getch();
	return 0;
}