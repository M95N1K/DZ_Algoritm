#include "Task2.h"
#pragma warning(disable : 4996)

//Задание №2
//	Переписать программу, реализующую двоичное дерево поиска.
//		а) Добавить в него обход дерева различными способами;
//		б) Реализовать поиск в двоичном дереве поиска;
//Выполнил Виль В.В.

typedef struct TNode
{
	int value;
	struct TNode* left;
	struct TNode* right;
	struct TNode* parent;
} Node;

Node* CreateNode(int value, Node* parent)
{
	Node* result = (Node*)malloc(sizeof(Node));
	result->value = value;
	result->left = NULL;
	result->right = NULL;
	result->parent = parent;
	return result;
}

void insert(Node** head, int value)
{
	if (*head == NULL)
	{
		*head = CreateNode(value, NULL);
		return;
	}
	Node* tmp = *head;
	while (tmp)
	{
		if (value > tmp->value)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = CreateNode(value, tmp);
				return;
			}
		}
		else
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = CreateNode(value, tmp);
				return;
			}
		}
	}
}

void printTree(Node *root)
{
	if (root)
	{
		printf("%d ", root->value);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else printf("NULL ");
			if (root->right)
				printTree(root->right);
			else printf(" NULL");
			printf(")");
		}
	}
}

void preOrderTravers(Node* root)
{
	if (root)
	{
		printf("%d ", root->value);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(Node* root)
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->value);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(Node* root)
{
	if (root)
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->value);
	}
}

void task2()
{
	srand(1);
	Node* tree = NULL;
	printTree(tree);

	int count = 20;
	for (int i = 0; i < count; i++)
		insert(&tree, rand() % 100);
	printf("Вывод дерева\n");
	printTree(tree);
	printf("\nОбход preOrderTravers\n");
	preOrderTravers(tree);
	printf("\n\nОбход inOrderTravers\n");
	inOrderTravers(tree);
	printf("\n\nОбход postOrderTravers\n");
	postOrderTravers(tree);

}