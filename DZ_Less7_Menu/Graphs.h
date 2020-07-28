#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int** ReadGraphFromFile(char* fileName, int size);
void PrintGraph(int** graph, int size);
void FreeGraph(int** graph, int size);
void BreadthCrawl(int** graph, int size, int startVertex);
void DepthCrawl(int** graph, int size, int startVertex);