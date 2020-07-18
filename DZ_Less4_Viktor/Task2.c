#include "Task2.h"
#pragma warning(disable : 4996)


//Задание №2
//	Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//Выполнил Виль В.В.

char **d = NULL;
int **c = NULL;
char *a;
char *b;
int m = 20;
int n = 20;

void freeMem(int m)
{
	for (int i = 0; i < m; i++)
	{
		free(c[i]);
		free(d[i]);
	}
	free(c);
}
void printArr(int m, int n)
{
	if (m == 0 || n == 0)
		return;
	if (d[m][n] == 'c')
	{
		printArr(m - 1, n - 1);
		printf("%c", a[m - 1]);
	}
	else if (d[m][n] == 'u')
		printArr(m - 1, n);
	else
		printArr(m, n-1);
}

int lcs_serch(char * a, char * b)
{
	m = strlen(a);
	n = strlen(b);
	c = (int**)calloc(m+1, sizeof(int*));
	d = (char**)calloc(m+1, sizeof(char*));
	
	for (int i = 0; i <= m; i++)
	{
		d[i] = (char*)calloc(n+1, sizeof(char));
	}

	for (int i = 0; i <= m; i++)
	{
		c[i] = (int*)calloc(n+1, sizeof(int));
	}

	for (int i = 0; i <= m;i++)
		c[i][0] = 0;
	for (int j = 0; j <= n;j++)
		c[0][j] = 0;
	for (int i = 1; i<=m;i++)
		for (int j = 1; j <= n;j++) 
		{
			if (a[i - 1] == b[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				d[i][j] = 'c';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				d[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				d[i][j] = 'l';
			}
		}
	int result = c[m][n];

	return result;
}

void task2()
{
	
	a = (char*)calloc(m, sizeof(char));
	b = (char*)calloc(n, sizeof(char));
	printf("Введите первую строку:\n",m);
	scanf("%s", a);
	printf("Введите вторую строку:\n",n);
	scanf("%s", b);

	int count = lcs_serch(a, b);
	printf("Количество совпадающих символов: %d\n", count);
	printArr(m, n);

	
	freeMem(m);
}