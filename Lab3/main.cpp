#include <stdio.h>
#include "functions.h"
#include <locale.h>
#include <windows.h>
void multiplicity_four(int number);

int main() {     
	setlocale(LC_ALL, "ru");
	int number;
	int n=0;
	Student* unique = (Student*)malloc(n * sizeof(Student));
	while (true)
	{
		int task = inputIntInRange("Введите номер задания: ", 1, 2);

		switch (task)
		{
		case 1:
			number = inputInt("Введите целое число: ");
			multiplicity_four(number);
			break;
		case 2:
			system("cls");
			task2(unique);
			break;
		}
		int a = inputIntInRange("\nЖелаете продолжить(1-да, 2 - нет): ", 1, 2);

		if (continue_prog(a)) break;
		else system("cls");
	}
	
	return 0;
}
