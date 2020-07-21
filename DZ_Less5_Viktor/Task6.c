#include "Task6.h"

#pragma warning(disable : 4996)

//Задача №6 (реализованно в файлах UQueue.x)
//	Реализовать очередь 
//Выполнил Виль В.В.

void task6()
{
	Queue MyQueue;
	MyQueue.Count = 0;
	AddQueue(&MyQueue, 'a');
	AddQueue(&MyQueue, 'b');
	AddQueue(&MyQueue, 'c');

	while (MyQueue.Count > 0)
	{
		printf("%c", GetQueue(&MyQueue));
	}

	FreeQueue(&MyQueue);
}