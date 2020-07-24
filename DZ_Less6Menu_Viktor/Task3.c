#include "Task3.h"
#pragma warning(disable : 4996)

//Задание №3 (я не разобрался как работать с массивами char)
//	*Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер»
//		Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных
//Выполнил Виль В.В.

typedef struct TStudent
{
	int age;
	int tNum;
	char name[1];
}Student;

typedef struct TNode
{
	Student value;
	struct TNode* left;
	struct TNode* right;
	struct TNode* parent;
}Node;

Node* CreateNodes(Student value, Node* parent)
{
	Node* result = (Node*)malloc(sizeof(Node));
	result->value.name[0] = *value.name;
	result->value.age = value.age;
	result->value.tNum = value.tNum;
	result->left = NULL;
	result->right = NULL;
	result->parent = parent;
	return result;
}


void SearchTreeByAge(Node** head, Student value)
{
	if (*head == NULL)
	{
		*head = CreateNodes(value, NULL);
		return;
	}
	Node* tmp = *head;
	while (tmp)
	{
		if (value.age > tmp->value.age)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = CreateNodes(value, tmp);
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
				tmp->left = CreateNodes(value, tmp);
				return;
			}
		}
	}
}

void SearchTreeByNumber(Node** head, Student value)
{
	if (*head == NULL)
	{
		*head = CreateNodes(value, NULL);
		return;
	}
	Node* tmp = *head;
	while (tmp)
	{
		if (value.tNum > tmp->value.tNum)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = CreateNodes(value, tmp);
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
				tmp->left = CreateNodes(value, tmp);
				return;
			}
		}
	}
}

Node* SearchByAge(int age, Student *Date, int len)
{
	Node* root = NULL;
	for (int i = 0; i < len;i++)
	{
		SearchTreeByAge(&root, Date[i]);
	}
	
	if (root == NULL)
		return NULL;

	while (root)
	{
		if (root->value.age == age)
			return root;
		else if (age > root->value.age)
			root = root->right;
		else root = root->left;
	}
}

void task3()
{
	srand(1);
	int count = 20;
	int i = 0;
	Student *Date = (Student*)calloc(count, sizeof(Student));
	for (int i = 0; i < count;i++)
	{
		*Date[i].name = 40+rand()%100;
		Date[i].age = 18 + rand()%10;
		Date[i].tNum = (i + 1) * 10000 + rand()%100 * 100 + i * 2;
	}
	printf("Имя - Возраст - Табельный номер\n");
	for (int i = 0; i < count; i++)
	{
		printf("%3s - %3d - %6d\n", Date[i].name, Date[i].age, Date[i].tNum);
	}

	Node* search = SearchByAge(Date[3].age, Date,count);
	if (search)
		printf(" %1c - % 3d - % 6d %x", search->value.name, search->value.age, search->value.tNum, search);
	else printf("Empty");
}