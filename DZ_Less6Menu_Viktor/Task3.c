#include "Task3.h"
#pragma warning(disable : 4996)

typedef struct TStudent
{
	int age;
	int tNum;
	char name[10];
}Student;

typedef struct TNode
{
	Student value;
	struct TNode* left;
	struct TNode* right;
	struct TNode* parent;
}Node;

void task3()
{
	int count = 20;
	int i = 0;
	Student *Date = (Student*)calloc(count, sizeof(Student));
	for (int i = 0; i < count;i++)
	{
		char tmp[10] = "Name";
		*Date[i].name = tmp[0];
		Date[i].age = 18 + i / 2;
		Date[i].tNum = (i + 1) * 10000 + i * 100 + i * 2;
	}
	printf("Имя - Возраст - Табельный номер\n");
	for (int i = 0; i < count; i++)
	{
		printf("%10s - %3d - %6d\n", Date[i].name, Date[i].age, Date[i].tNum);
	}
}