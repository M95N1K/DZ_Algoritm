#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

// ������� �5
//	� ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������.
// �������� ���� �. �.

int main()
{
	int answ = 0;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("������� ����� ������\n");

	while ((scanf("%d",&answ) != 1) || !(0 < answ && answ < 13))
	{
		system("cls");
		printf("������� ����� ������ (�� 1 �� 12)\n");
		while (getchar() != '\n');
	}

	switch (answ)
	{
	case 1:
	case 2:
	case 12:
		printf("�������� ����");
		break;
	case 3:
	case 4:
	case 5:
		printf("������� �����");
		break;
	case 6:
	case 7:
	case 8:
		printf("������ ����");
		break;
	case 9:
	case 10:
	case 11:
		printf("������ �����");
		break;
	default:
		break;
	}

	getch();
	return 0;
}