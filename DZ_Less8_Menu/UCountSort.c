#include "UCountSort.h"
#include "UArrays.h"



int CountSort(int* arrays, int len)
{
	int max = MaxElement(arrays, len)+1;
	int* countarray = CreatArray(max);
	for (int i = 0; i <= max;i++)
		countarray[i] = 0;
	InitArray(countarray, max);

	for (int i = 0;i < len;i++)
	{
		countarray[arrays[i]]++;
	}
	int c = 0;
	for (int i = 0; i <= max;i++)
		for (int j = 0; j < countarray[i];j++)
		{
			arrays[c] = i;
			c++;
		}
	return c;
}