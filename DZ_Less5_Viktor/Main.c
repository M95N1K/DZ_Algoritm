#include <stdio.h>
#include <locale.h>
#include "Task1.h"

#pragma warning(disable : 4996)

int main()
{
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	int num;
	printf("�������� ������ ��� �������: \n");
	printf("\t1. O������������� ����������� ����������. \n");
	printf("\t2. ����������� ��������� ����������. \n");
	printf("\t3. ����������� �������� �������� ������. \n");
	printf("\t4. ���������� ���������� �������� ��� ������ �� ���������� \n\t\t� �������� ��� � ��������������� ���������� ���������. \n");
	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num == 3 || num == 4))
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
		//task2();
		break;
	case 3:
		//task3();
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