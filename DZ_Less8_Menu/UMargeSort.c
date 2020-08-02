#include "UMargeSort.h"
#include "UArrays.h"


int MargeSort(int* arrays, int l, int r)
{
	int result = 0;
	if (l == r)
		return 0;

	//Делим текущий массив попалам
	int mid = (l + r) / 2;
	result += MargeSort(arrays, l, mid);
	result += MargeSort(arrays, mid + 1, r);

	int i = l;
	int j = mid + 1;

	int* tmp = CreatArray(r-l+1);
	for (int k = 0; k < r - l + 1; k++)
	{
		if ((j > r) || ((i <= mid) && (arrays[i] < arrays[j])))
		{
			tmp[k] = arrays[i];
			i++;
		}
		else
		{
			tmp[k] = arrays[j];
			j++;
		}
		result++;
	}

	for (int k = 0; k < r - l + 1; k++)
	{
		arrays[l + k] = tmp[k];
	}
	free(tmp);
	return result;
}