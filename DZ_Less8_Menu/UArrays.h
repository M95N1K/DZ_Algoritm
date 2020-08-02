#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* CreatArray(int len);
void PrintArray(int* arrays, int size);
int MaxElement(int* arrays, int len);
void InitArray(int* arrays, int size);
void RandomizeArray(int* arrays, int size, int max);
