#pragma once
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include <ctype.h>

int inputInt(const char* prompt) 
{
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf_s("%d", &value) == 1) {
            while (getchar() != '\n');
            return value;
        }
        printf("Ошибка. Введены некорректные данные. \n");
        while (getchar() != '\n');
    }
}

double inputDouble(const char* prompt) 
{
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf_s("%lf", &value) == 1) {
            while (getchar() != '\n');
            return value;
        }
        printf("Ошибка. Введите корректные данные: \n");
        while (getchar() != '\n');
    }
}

int inputPositiveInt(const char* prompt) 
{
    int value;
    while (1) {
        value = inputInt(prompt);
        if (value > 0) {
            return value;
        }
        printf("Ошибка. Введите положительное число: ");
    }
}

int inputIntInRange(const char* prompt, int min, int max) 
{
    int value;
    while (1) {
        value = inputInt(prompt);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Ошибка. Ввведено некоректное число. ");
    }
}



int inputDoubleInRange(const char* prompt, double min, double max) 
{
    double value;
    while (1) {
        value = inputDouble(prompt);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Ошибка. Ввведено некоректное число. ");
    }
}




char* read_data() 
{
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);       
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



bool kris_is_digit(char c)
{
    char mass[44] = "0123456789/*-+!@#$%^&*()_+=)(?:%;№.,`~<>|";
    for (int i = 0; i < 11; i++)
    {
        if (c == mass[i]) return false;

    }
    return true;
}

/*
char* read_data_line()
{
    //char mass[12] = "0123456789.";
    char* str = read_data();
    if (str == NULL)
    {
        printf("Cтрока не должна быть пустой");
        str = read_line();

    }
    int len_data = sizeof(str) / sizeof(char);
    if (len_data < 5)
    {
        printf("Слишком мало символов для даты");
        str = read_data_line();
    }
    return str;

}
*/

char* read_line()
{
    SetConsoleOutputCP(866);
    SetConsoleCP(CP_UTF8);       
    setlocale(LC_ALL, "RU");
    char* str = read_data();
    if (str == NULL)
    {
        printf("Cтрока не должна быть пустой");
        str = read_line();
        
    }
    int len_str = sizeof(str) / sizeof(char);

    for (int i = 0; i < len_str; i++)
    {
        if (kris_is_digit(str[i]) == false)
        {
            printf("Ввод не должен содержать цифры\n");
            printf("Повторите ввод: ");
            str = read_line();
            break;
        }
    }
    return str;

}





