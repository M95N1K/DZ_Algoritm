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
		while ((arrays[left] < basis) && (left<= right) ) left++; // ������� ������� � ���� ������� ������ ��� �������
		while ((arrays[right] > basis) && (left <= right)) right--; // ������� ������� � ����� ������� ������ ��� �������
		// ������ �� �������
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
	result += QuickSort(arrays, first, right); //��������� ��������� ��� ����� ��������
	result += QuickSort(arrays, left, last); //��������� ��������� ��� ������ ��������
	return result;
}