#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "checks.h"
#include <string.h>
#include<locale.h>
#include <windows.h>


char* read_line();

void multiplicity_four(int number)
{
	int number_div_four = number >> 2;
	printf("Число(целое) в 4 раза меньшее: %d", number_div_four);

}


typedef struct 
{
	char data[100];
}Enrollment_date;

typedef struct{
	int passbook_number;
	char* last_name;
	Enrollment_date data;
	double avarage_grade;
} Student;



char* perform_data(char* data)
{
    int len = sizeof(data) / sizeof(char);
    for (int i = 0; i < len; i++)
    {
        if (data[i] == '\n')
        {
            data[i] = '\0';
        }

    }

    return data;
}

void enter_information(Student *unique) 
{
    SetConsoleOutputCP(CP_UTF8);  
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "RU");

    unique->passbook_number = inputPositiveInt("Введите номер зачётной книжки: ");
	printf("Введите фамилию: ");
    unique->last_name = read_line();
	printf("Введите дату зачисления: ");
    fgets(unique->data.data, sizeof(unique->data.data), stdin);
    perform_data(unique->data.data);
    unique->avarage_grade = inputDoubleInRange("Введите средний балл : ", 0, 10);
	
}

bool continue_prog(int a) 
{
    if (a == 1) return false;
    else if (a == 2) return true;

}



void print_student(const Student* unique) {
    printf("Номер зачётной книжки: %d\n", unique->passbook_number);
    printf("Фамилия: %s\n", unique->last_name);
    printf("Дата зачисления: %s\n", unique->data.data);
    printf("Средний балл: %.2lf\n", unique->avarage_grade);
}



bool compare_resp_and_name(char* name_in_struckt,const char* last_name) {
    int len_word1 = sizeof(name_in_struckt)/ sizeof(char);
    int len_word2 = sizeof(last_name) / sizeof(char);
    if (len_word1 != len_word2) 
    {
        return false;

    }
    for (int i = 0; i < len_word1; i++)
    {
        if (name_in_struckt[i] != last_name[i])
        {
            return false;
        }
    }
    return true;


}

void find_student_by_last_name(Student* unique, int n, const char* last_name)
{
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (compare_resp_and_name(unique[i].last_name, last_name))
        {
            printf("Найден студент:\n");
            print_student(&unique[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Cтуденты с фамилией '%s' не найдены.\n", last_name);
    }
}

/*
void find_student_by_last_name1(Student* unique, int n, const char* last_name)
{
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(unique[i].last_name, last_name) == 0)
        {
            printf("Найден студент:\n");
            print_student(&unique[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Cтуденты с фамилией '%s' не найдены.\n", last_name);
    }
}
*/



void delete_student_by_passbook(Student* unique, int* n, int max_value) {
    int deleted = 0;
    for (int i = 0; i < *n; i++) {
        if (unique[i].passbook_number < max_value) {
            free(unique[i].last_name);
            for (int j = i; j < *n - 1; j++) {
                unique[j] = unique[j + 1];
            }
            (*n)--;
            i--;
            deleted++;
        }
    }

    printf("Удалено %d студентов.\n", deleted);
}


void menu() 
{
    printf("\nМеню:\n");
    printf("1. Вывести всех студентов\n");
    printf("2. Удалить студента по номеру зачётки\n");
    printf("3. Найти студента по фамилии\n");
    printf("4. Добавить студента\n");
    printf("5. Выйти\n");

}


void task2(Student*unique)
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    int action;
    int n = 0;
    char* last_name;
    int number_bookpass_max;

    
    do {
        
        menu();
        if (n == 0)
        {
            printf("Недостаточно студентов для действий 1-3");
            action = inputIntInRange("\nВыберите действие: ", 4, 5);
        }
        else action = inputIntInRange("Выберите действие:", 1, 5);
        switch (action)
        {
        case 1:

            for (int i = 0; i < n; i++)
            {
                printf("\nДанные о студенте %d:\n", i + 1);
                print_student(&unique[i]);
            }
            
            break;

        case 2:
            number_bookpass_max = inputPositiveInt("Введите максимальный номер зачётки: ");
            delete_student_by_passbook(unique, &n, number_bookpass_max);
            break;

        case 3:
            printf("Введите фамилию: ");
            last_name = read_line();
            printf("Введите фамилию: ");

            find_student_by_last_name(unique, n, last_name);
            free(last_name);
            break;
        
        case 4:

            n += 1;
            unique = (Student*)realloc(unique, n*sizeof(Student));
            enter_information(&unique[n - 1]);
            system("cls");
            break;
           
        }


    } while (action != 5);


    for (int i = 0; i < n; i++)
    {
        free(unique[i].last_name);
    }
    free(unique);

}

