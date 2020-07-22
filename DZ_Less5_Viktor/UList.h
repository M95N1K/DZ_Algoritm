#pragma once
#include <stdio.h>
#include <stdlib.h>
#define T int

typedef struct TNodeL NodeL;
typedef struct TList List;

struct TNodeL
{
	T value;
	NodeL* next;
};

struct TList
{
	NodeL* tail;
	int Count;
};

void pushL(List* list, T value);
T popL(List* list);
void FreeList(List* list);
List CopyList(List from);

