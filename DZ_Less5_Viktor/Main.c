#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main(void)
{
	setlocale(LC_ALL, "RU");
	printf("Hallo World!!!\n Base C Project\n");

	getch();
	return 0;
}