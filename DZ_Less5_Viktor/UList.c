#include "UList.h"

void pushL(List* list, T value)
{
	if (list->Count <= 0)
	{
		NodeL* tmp = (NodeL*)calloc(1, sizeof(NodeL));
		tmp->value = value;
		tmp->next = tmp;
		list->tail = tmp;
		list->Count++;
		return;
	}
	NodeL* head = list->tail->next;
	NodeL* tmp = (NodeL*)calloc(1, sizeof(NodeL));
	tmp->value = value;
	tmp->next = list->tail->next;
	list->tail->next = tmp;
	list->tail = tmp;
	list->Count++;
}

T popL(List* list)
{
	if (list->Count <= 0)
		return 0;
	NodeL* tmp = list->tail->next;
	T result = tmp->value;
	list->tail->next = tmp->next;
	list->Count--;
	free(tmp);
	return result;
}

void FreeList(List* list)
{
	if (list->Count <= 0)
		return;
	while (list->Count > 0)
	{
		NodeL* tmp = list->tail;
		list->tail = tmp->next;
		list->Count--;
		free(tmp);
	}
}

List CopyList(List from)
{
	List to;
	to.Count = 0;
	NodeL* fList = from.tail;
	do
	{
		fList = fList->next;
		pushL(&to, fList->value);
	} while (fList != from.tail);
	return to;
}