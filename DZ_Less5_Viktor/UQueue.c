#include "UQueue.h"
#pragma warning(disable : 4996)

//Задача №6
//	Реализовать очередь
//Выполнил Виль В.В.

void AddQueue(Queue *queue, T value)
{
	if (queue->Count == 0)
	{
		Node* tmp = (Node*)calloc(1, sizeof(Node));
		tmp->value = value;
		tmp->next = NULL;
		queue->head = tmp;
		queue->tail = tmp;
		queue->Count++;
		return;
	}
	Node* tmp = (Node*)calloc(1, sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	queue->tail->next = tmp;
	queue->tail = tmp;
	queue->Count++;
}

T GetQueue(Queue* queue)
{
	if (queue->Count == 0)
		return 0;
	int result = queue->head->value;
	Node* tmp = queue->head;
	queue->head = tmp->next;
	if (queue->tail == tmp)
		queue->tail = NULL;
	queue->Count--;
	free(tmp);
	return result;
}

void FreeQueue(Queue* queue)
{
	while (queue->Count > 0)
	{
		Node* tmp = queue->head;
		queue->head = tmp->next;
		if (queue->tail == tmp)
			queue->tail = NULL;
		queue->Count--;
		free(tmp);
	}
}