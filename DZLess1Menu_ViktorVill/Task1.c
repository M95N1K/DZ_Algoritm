#include "Task1.h"
#pragma warning(disable : 4996)
// ������� �1
//	������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h); 
//	��� m-����� ���� � �����������, h - ���� � ������.
// �������� ���� �. �.
int task1()
{
	double height;
	double weight;

	printf("Enter the height in meters: ");
	scanf("%lf", &height);

	printf("Enter the weight in kilograms: ");
	scanf("%lf", &weight);


	printf("Mass index is %lf\n", weight / (height * height));

	return 0;
}
