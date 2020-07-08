#include "Task2.h"
#pragma warning(disable : 4996)
// ������� �2
//	����������� ������� ���������� ����� a � ������� b:
//		a. ��� ��������.
//		b. ����������.
//		c. *����������, ��������� �������� �������� �������.
// �������� ���� �.�.

int task2()
{
	int a, b;
	int num = 0;
	printf("������ ���������� ����� A � ������� B: \n");
	printf("������� ����� A � B ����� ������: \n");

	while ((scanf("%d %d", &a,&b) != 2))
	{
		printf("�������� ����");
		while (getchar() != '\n');
	}

	printf("�������� ����� �������: \n");
	printf("\t1. ��� ��������: \n");
	printf("\t2. ����������: \n");
	printf("\t3. *����������, ��������� �������� �������� �������: \n");

	while ((scanf("%d", &num) != 1) || !(num == 1 || num == 2 || num ==3))
	{
		printf("�������� ����");
		while (getchar() != '\n');
	}

	switch (num)
	{
	case 1:
		printf("%d",Pow1(a,b));
		break;
	case 2:
		printf("%d", Pow2(a, b));
		break;
	case 3:
		printf("%d", Pow3(a, b));
		break;
	default:
		break;
	}

	return 0;
}

long Pow1(int a, int b)
{
	if (b == 0)
		return 1;

	int tmp=b;
	long result=1;
	while (tmp)
	{
		result = result * a;
		tmp--;
	}
	return result;
}

long Pow2(int a, int b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	else return a * Pow2(a, b - 1);
}

long Pow3(int a, int b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a;
	else if (b % 2 == 0)
	{
		int tmp = Pow3(a, b / 2);
		return tmp * tmp;
	}
	else return Pow3(a, b - 1) * a;
}
