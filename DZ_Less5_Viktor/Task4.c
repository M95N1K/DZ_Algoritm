#include "Task4.h"

//������ �4 (������� CopyList(List from))
//	������� �������, ���������� ����������� ������
//�������� �����.�.

void printL(List* list)
{
	if (list->Count == 0)
		return;
	while (list->Count > 0)
	{
		printf("[%d]", popL(list));
	}
}

void task4()
{
	List a;
	a.Count = 0;

	pushL(&a, 1);
	pushL(&a, 2);
	pushL(&a, 3);
	pushL(&a, 4);

	List b;
	b = CopyList(a);
	printL(&b);
	printf("\n");
	printL(&a);
	FreeList(&a);
}