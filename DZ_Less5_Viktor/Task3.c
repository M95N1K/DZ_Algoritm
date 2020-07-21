#include "Task3.h"
#pragma warning(disable : 4996)
#define C char

//Задание №3
//	Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Выполнил Виль В.В.

struct TNode
{
	C value;
	Node* next;
};

void pushC(Node* Stack, C value)
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
C popC(Node* Stack)
{
	C result;
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

void WriteStackC(Node* Stack)
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

void FreeStackC(Node* Stack)
{
	while (Stack->next != NULL)
	{
		Node* tmp = Stack->next;
		Stack->next = tmp->next;
		free(tmp);
	}
	Stack->value = -1;
}

int IsCorrect(char* str, Node *Stack)
{
	int result = 1;
	int c = strlen(str);
	for (int i = 0; i < c; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			pushC(Stack, str[i]);
		}
		
		switch (str[i])
		{
		case 125:
			if (Stack->value == '{')
				popC(Stack);
			else return 0;
			break;
		case 93:
			if (Stack->value == '[')
				popC(Stack);
			else return 0;
			break;
		case 41:
			if (Stack->value == '(')
				popC(Stack);
			else return 0;
			break;
		}
	}
	if (Stack->value > -1)
		return 0;
	return result;
}

void task3()
{
	Node Head;
	Head.next = NULL;
	Head.value = -1;
	char *num[10];
	printf("Введите положительное строку: ");
	scanf("%s", num);
	printf("%d", IsCorrect(num, &Head));

}