#include "Task1.h"
#pragma warning(disable : 4996)
// ������� �1
//	����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.
// �������� ���� �.�.

int DecToBin(int num);

int task1()
{
	int num;
	printf("������� �����: \n");
	while ((scanf("%d", &num) != 1))
	{
		printf("�������� ����");
		while (getchar() != '\n');
	}

	printf("%d %s %d", num, "� �������� �������", DecToBin(num));
}

int DecToBin(int num)
{
	if (num == 1)
		return 1;
	if (num % 2 == 0)
	{
		return DecToBin(num / 2) * 10;
	}
	else return DecToBin((num - 1) / 2) * 10 + 1;
}
