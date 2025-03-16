#pragma once
#pragma once
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>

int inputInt(const char* prompt) {
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf_s("%d", &value) == 1) {
            // Очищаем буфер ввода
            while (getchar() != '\n');
            return value;
        }
        printf("Ошибка. Введены некорректные данные. \n");
        // Очищаем буфер ввода
        while (getchar() != '\n');
    }
}

double inputDouble(const char* prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf_s("%lf", &value) == 1) {
            // Очищаем буфер ввода
            while (getchar() != '\n');
            return value;
        }
        printf("Ошибка. Введите корректные данные: \n");
        // Очищаем буфер ввода
        while (getchar() != '\n');
    }
}

int inputPositiveInt(const char* prompt) {
    int value;
    while (1) {
        value = inputInt(prompt);
        if (value > 0) {
            return value;
        }
        printf("Ошибка. Введите положительное число: ");
    }
}

int inputIntInRange(const char* prompt, int min, int max) {
    int value;
    while (1) {
        value = inputInt(prompt);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Ошибка. Ввведено некоректное число. ");
    }
}



char* read_data() {
    SetConsoleOutputCP(CP_UTF8);  // Устанавливаем кодировку консоли в UTF-8
    SetConsoleCP(CP_UTF8);        // Устанавливаем кодировку ввода в UTF-8
    setlocale(LC_ALL, "RU");
    int size = 10;
    int len = 0;
    char* str = (char*)malloc(size * sizeof(char));
    char ch;

    while ((ch = getchar()) != '\n')
    {

        if (len == size - 1)
        {
            size += 2;
            str = (char*)realloc(str, size * sizeof(char));
        }
        str[len++] = ch;
    }
    str[len] = '\0';

    return str;

}


char* read_line()
{
    SetConsoleOutputCP(CP_UTF8);  // Устанавливаем кодировку консоли в UTF-8
    SetConsoleCP(CP_UTF8);        // Устанавливаем кодировку ввода в UTF-8
    setlocale(LC_ALL, "RU");
    char* str = read_data();
    if (str == NULL)
    {
        printf("Cтрока не должна быть пустой");
        str = read_line();
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 0 and str[i] <= 9)
        {
            printf("Ввод не должен содержать цифры\n");
            printf("Повторите ввод: ");
            str = read_line();
            break;
        }
    }
    return str;

}





