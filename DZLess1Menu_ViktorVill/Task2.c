#include "Task2.h"

// ������� �2
//	����� ������������ �� ������� �����. ������� �� ������������.
// �������� ���� �. �.

int task2()
{
	int a, b, c, d;
	int count;

	setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");
	printf("������� ������ ����� �����:\n");

	count = 1;

	while (count <= 4)
	{
		printf("%d %s: ", count, "�����");
		switch (count)
		{
		case 1:
			scanf("%d", &a);
			break;
		case 2:
			scanf("%d", &b);
			break;
		case 3:
			scanf("%d", &c);
			break;
		case 4:
			scanf("%d", &d);
			break;
		default:
			break;
		}
		count++;
	}

	if (a < b)
		a = b;
	if (c < d)
		c = d;
	if (a < c)
		a = c;

	printf("%s %d", "������������ �����:", a);
	return 0;
}