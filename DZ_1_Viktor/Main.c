#include <stdio.h>
#pragma warning(disable : 4996)

// Задание №1
//	Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
// Выполнил Виль В. В.
int main()
{
	double height;
	double weight;

	printf("Enter the height in meters: ");
	scanf("%lf", &height);

	printf("Enter the weight in kilograms: ");
	scanf("%lf", &weight);
	

	printf("Mass index is %lf\n", weight / (height * height));
	
	getch();
	return 0;
}