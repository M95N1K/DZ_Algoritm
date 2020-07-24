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

Node* SearchRecurcive(int value, Node * root)
{
	if (root == NULL)
		return NULL;
	Node* result;
	if (value == root->value)
		result = root;
	else if (value > root->value)
		result = SearchRecurcive(value, root->right);
	else
		result = SearchRecurcive(value, root->left);
	return result;
}

Node* SearchCicle(int value, Node * tree)
{
	Node* root = tree;
	if (root == NULL)
		return NULL;

	while (root)
	{
		if (root->value == value)
			return root;
		else if (value > root->value)
			root = root->right;
		else root = root->left;
	}
}

void task2()
{
	srand(1);
	Node* tree = NULL;
	printTree(tree);
	int tmp = 0;
	int count = 20;
	for (int i = 0; i < count; i++)
	{
		int c = rand() % 100;
		insert(&tree, c);
		if (i == count / 2)
			tmp = c;
	}
	printf("Вывод дерева\n");
	printTree(tree);
	printf("\nОбход preOrderTravers\n");
	preOrderTravers(tree);
	printf("\n\nОбход inOrderTravers\n");
	inOrderTravers(tree);
	printf("\n\nОбход postOrderTravers\n");
	postOrderTravers(tree);
	printf("Поиск элемента %d рекурсией\n", tmp);
	Node* search = SearchRecurcive(tmp, tree);
	printf("Элемент %d находится по адрессу %x\n\n", tmp, search);
	printf("Поиск элемента %d циклом\n", tmp);
	search = SearchCicle(tmp, tree);
	printf("Элемент %d находится по адрессу %x", tmp, search);
}