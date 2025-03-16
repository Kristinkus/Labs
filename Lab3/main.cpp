#include <stdio.h>
#include "functions.h"
#include <locale.h>
#include <windows.h>
void multiplicity_four(int number);

int main() {
	SetConsoleOutputCP(CP_UTF8);   кодировка консоли в UTF-8
	SetConsoleCP(CP_UTF8);         кодировка ввода в UTF-8
	setlocale(LC_ALL, "ru");
	int number;
	int n;

	int task = inputIntInRange("Введите номер задания: ", 1, 2);

	switch(task)
	{
	case 1:
		number = inputInt("Введите целое число: ");
		multiplicity_four(number);
		break;
	case 2:
		system("cls");
		task2();
		break;
	}

	return 0;
}
