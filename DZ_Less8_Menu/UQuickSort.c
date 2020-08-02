#include "UQuickSort.h"

int QuickSort(int* arrays, int first, int last)
{
	if (first >= last) return 0;
	int basis;
	int left = first;
	int right = last;
	basis = arrays[(left+right)/2];
	int result = 0;

	do
	{
		while ((arrays[left] < basis) && (left<= right) ) left++; // Ноходим элемент с лева который больше чем опорный
		while ((arrays[right] > basis) && (left <= right)) right--; // Ноходим элемент с права который меньше чем опорный
		// меняем их местами
		if (left <= right)
		{
			int tmp = arrays[left];
			arrays[left] = arrays[right];
			arrays[right] = tmp;
			left++;
			right--;
		}
		result++;
	} while (left <= right);
	result += QuickSort(arrays, first, right); //запускаем сортирвку для левой половины
	result += QuickSort(arrays, left, last); //запускаем сортирвку для правой половины
	return result;
}