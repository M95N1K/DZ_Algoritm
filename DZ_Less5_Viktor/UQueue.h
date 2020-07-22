#pragma once
#include <stdio.h>
#include <stdlib.h>
#define T char

typedef struct TNode Node;
typedef struct TQueue Queue;

struct TNode
{
	T value;
	Node* next;
};
struct TQueue
{
	Node* head;
	Node* tail;
	int Count;
};

void AddQueue(Queue* queue, T value);
T GetQueue(Queue* queue);
void FreeQueue(Queue* queue);