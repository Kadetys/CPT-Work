#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
int hod(char mas[3][3], int vibor) {
    while (1) {
        printf("Выберите ячейку для установки:\n");
        scanf("%d", &vibor);
        vibor -= 1;
        if (vibor > 9 || vibor < 1) {
            printf("Некорректный номер ячейки, повторите попытку!\n");
        }
        if (mas[vibor / 3][vibor % 3] != NULL) {
            printf("Ячейка занята, выберите другую!\n");
            }
        mas[vibor / 3][vibor % 3] = 'x';
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    printf("Нумерация клеток на поле: \n|-1-|-2-|-3-| \n|-4-|-5-|-6-| \n|-7-|-8-|-9-| \n");
    while (1) {
        printf("Совершите выбор: \n1: Крестик\n2: Нолик\n");
        int Choise = 0;
        scanf("%d", &Choise);
        if (Choise >2 || Choise < 1) {
            printf("Ошибка, выберите один из предложенных пунктов\n");
        }
        else {
            break;
        }
    }
    
    return 0;
}