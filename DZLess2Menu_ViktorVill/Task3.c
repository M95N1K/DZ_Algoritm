#include "Task3.h"
#pragma warning(disable : 4996)

//������� �3
//	����������� ����������� ����������� ����� �����, ���������� �� ������. � ����������� ��� �������, ������ ������� �������� �����:
//		������� 1
//		������ �� 2
//	������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����.
//	������� ���������� ��������, ������� ����� 3 ����������� � ����� 20 ?
// �������� ���� �.�.

int count = 0;
int c2 = 0;
int act[2] = { 0,1 };

void CountDecision(int from, int to)
{
	if (from == to)
	{
		count++;
		return;
	}
	if (from > to)
	{
		return;
	}
	int i;
	for (i = 0; i < 2; i++)
	{
		if (act[i])
			CountDecision(from * 2, to);
		else CountDecision(from + 1, to);
	}
}


int task3()
{
	count = 0;
	CountDecision(3, 20);
	printf("���������� ��������, ������� ����� 3 ����������� � ����� 20, �����: %d\n", count);

}

