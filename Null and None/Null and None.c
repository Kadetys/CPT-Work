#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
char igrok(char mas[3][4], int vybor) {
    while (1) {
        int vibor;
        printf("Выберите ячейку для установки:\n");
        scanf("%d", &vibor);
        if (vibor > 9 || vibor < 1) {
            printf("Некорректный номер ячейки, повторите попытку!\n");
        }
        vibor -= 1;
        if (mas[vibor / 3][vibor % 3] != '-') {
            printf("Ячейка занята, выберите другую!\n");
        }
        if (vybor == 1) {
            mas[vibor / 3][vibor % 3] = 'X';
        }
        else {
            mas[vibor / 3][vibor % 3] = 'O';
        }
        break;
        return mas;
    }
}

    void main()
    {
        int Choise = 0;
        setlocale(LC_ALL, "");
        printf("Нумерация клеток на поле: \n|-1-|-2-|-3-| \n|-4-|-5-|-6-| \n|-7-|-8-|-9-| \n");
        while (1) {
            printf("Совершите выбор: \n1: Крестик\n2: Нолик\n");
            scanf("%d", &Choise);
            if (Choise > 2 || Choise < 1) {
                printf("Ошибка, выберите один из предложенных пунктов\n");
            }
            else {
                break;
            }
        }
        char mas[3][4];
        for (int i = 0; i != 3; i++) {
            ;
            for (int j = 0; j != 3; j++) {
                mas[i][j] = '-';
            }
        }
        mas[3][4] = bot(mas, Choise);
        for (int i = 0; i != 3; i++) {
            printf("\n");
            for (int j = 0; j != 3; j++) {
                printf("%c ", mas[i][j]);
            }
        }
    }