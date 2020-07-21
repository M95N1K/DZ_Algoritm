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

struct TStack
{
	Node* head;
};

TStack Head;

void push(TStack *St, int value)
{
	Node* Stack = St->head;
	if (Stack == NULL)
	{
		Stack = (Node*)calloc(1, sizeof(Node));
		Stack->value = value;
		Stack->next = NULL;
		St->head = Stack;
		return;
	}
	Node* node;
	node = (Node*)calloc(1, sizeof(Node));
	node->value = value;
	node->next = Stack;
	Stack = node;
	St->head = Stack;
}
int pop(TStack* St)
{
	Node* Stack = St->head;
	if (Stack == NULL)
		return -1;
	int result = Stack->value;
	Node* tmp = Stack;
	Stack = Stack->next;
	St->head = Stack;
	free(tmp);
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

void FreeStack(TStack* St)
{
	Node* Stack = St->head;
	while (Stack != NULL)
	{
		Node* tmp = Stack;
		Stack = Stack->next;
		free(tmp);
	}
}

void task1()
{
	Head.head = NULL;
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