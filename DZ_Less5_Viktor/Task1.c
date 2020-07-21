#include "Task1.h"
#pragma warning(disable : 4996)

//Задание №1
//	Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//Выполнил Виль В.В.

struct TNode
{
	int value;
	struct Node* next;
};

Node Head;

void push(Node *Stack, int value)
{
	if (Stack->next == NULL && Stack->value == -1)
	{
		Stack->value = value;
		Stack->next = NULL;
		return;
	}
	Node* node;
	node = (Node*)calloc(1, sizeof(Node));
	node->value = Stack->value;
	node->next = Stack->next;
	Stack->value = value;
	Stack->next = node;
}
int pop(Node* Stack)
{
	int result;
	if (Stack->next != NULL)
	{
		result = Stack->value;
		Node* tmp = Stack->next;
		Stack->value = tmp->value;
		Stack->next = tmp->next;
		free(tmp);
	}
	else
	{
		result = Stack->value;
		Stack->value = -1;
	}
	return result;
}


void DecToBin(int num)
{
	while(num > 1)
	{
		if (num % 2 == 0)
		{
			push(&Head, 0);
			num /= 2;
		}
		else
		{
			push(&Head, 1);
			num = (num - 1) / 2;
		}
	}
	if (num ==0)
		push(&Head, 0);
	if (num == 1)
		push(&Head, 1);
}

void WriteStack(Node *Stack)
{
	int tmp = 0;

	while (tmp != -1)
	{
		tmp = pop(Stack);
		if (tmp != -1)
			printf("%d", tmp);
	}
	printf("\n");
}

void FreeStack(Node* Stack)
{
	while (Stack->next != NULL)
	{
		Node* tmp = Stack->next;
		Stack->next = tmp->next;
		free(tmp);
	}
	Stack->value = -1;
}

void task1()
{
	Head.next = NULL;
	Head.value = -1;
	int num = 0;
	printf("Введите положительное число: ");
	while ((scanf("%d", &num) != 1) || !(num >= 0))
	{
		printf("Неверный ввод");
		while (getchar() != '\n');
	}

	DecToBin(num);
	WriteStack(&Head);
	FreeStack(&Head);
}