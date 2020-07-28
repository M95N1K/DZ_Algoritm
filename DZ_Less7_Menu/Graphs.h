#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** ReadGraphFromFile(char* fileName, int size);
void PrintGraph(int** graph, int size);
void FreeMem(int** graph, int size);
//void BreadthCrawl(int** graph, int size);