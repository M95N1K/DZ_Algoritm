#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

// ������� �3
//	�������� ��������� ������ ���������� ���� ������������� ����������:
//		a. � �������������� ������� ����������;
//		b.* ��� ������������� ������� ����������.
// �������� ���� �. �.

int menu()
{
	int answ;

	while (1)
	{
		printf("�������� �������� ��������:\n");
		printf("\t 1: �������� ����� ������� � ������� ������� ����������\n");
		printf("\t 2: �������� ����� ������� �������������� ��������\n");
		printf("\t 3: �������� ����� ������� ��������� XOR\n");
		if (scanf("%d", &answ) != 1 || !(answ == 1 || answ == 2 || answ == 3))
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
	int a, b;
	int tmp;
	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("������� 2 ����� �����:\n");
	printf("����� A: ");
	scanf("%d", &a);
	printf("����� B: ");
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
	printf("%s %d\n%s %d\n", "����� �:", a, "����� B:", b);

	getch();
	return 0;
}