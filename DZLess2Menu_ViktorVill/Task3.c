#include "Task3.h"
#pragma warning(disable : 4996)

//Задание №3
//	Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
//		Прибавь 1
//		Умножь на 2
//	Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
//	Сколько существует программ, которые число 3 преобразуют в число 20 ?
// Выполнил Виль В.В.

int count = 0;
int c2 = 0;
int act[2] = { 0,1 };

void CountDecision(int from, int to)
{
	if (from == to)
	{
		count++;
		return;
	}
	if (from > to)
	{
		return;
	}
	int i;
	for (i = 0; i < 2; i++)
	{
		if (act[i])
			CountDecision(from * 2, to);
		else CountDecision(from + 1, to);
	}
}


int task3()
{
	count = 0;
	CountDecision(3, 20);
	printf("Количество программ, которые число 3 преобразуют в число 20, равно: %d\n", count);

}

