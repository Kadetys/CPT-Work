#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
char bot(char mas[3][4], int vybor) {
    while (1) {
        int vibor = rand() % 8;
        if (mas[vibor / 3][vibor % 3] == '-') {
            if (vybor == 1) {
                mas[vibor / 3][vibor % 3] = 'O';
            }
            else {
                mas[vibor / 3][vibor % 3] = 'X';
            }
            break;
        }

    }
    return mas;
}

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

int check(char mas[3][4], int none) {
    int count = 0;
    for (int i = 0; i != 3; i++) {
        if (mas[i][0] == mas[i][1] == mas[i][2] == 'X') {
            printf("Победил крестик!\n");
            return 0;
        }
        if (mas[i][0] == mas[i][1] == mas[i][2] == 'O') {
            printf("Победил нолик!\n");
            return 0;
        }
    }
        for (int i = 0; i != 3; i++) {
            if (mas[0][i] == mas[1][i] == mas[2][i] == 'X') {
                printf("Победил крестик!\n");
                return 0;
            }
            if (mas[0][i] == mas[1][i] == mas[2][i] == 'O') {
                printf("Победил нолик!\n");
                return 0;
            }
    }
        if (mas[0][0] == mas[1][1] == mas[2][2] == 'X') {
            printf("Победил крестик!\n");
            return 0;
        }
        if (mas[0][2] == mas[1][1] == mas[2][0] == 'X') {
            printf("Победил крестик!\n");
            return 0;
        }
        if (mas[0][0] == mas[1][1] == mas[2][2] == 'O') {
            printf("Победил нолик!\n");
            return 0;
        }
        if (mas[0][2] == mas[1][1] == mas[2][0] == 'O') {
            printf("Победил нолик!\n");
            return 0;
        }
        for (int i = 0; i != 3; i++) {
            for (int j = 0; j != 4; j++) {
                if (mas[i][j] != '-') {
                    none += 1;
                }
            }
        }
            if (none == 9) {
                printf("Ничья!\n");
                return 0;
            }
        return 1;
}

void pole(char mas[3][4]) {
    printf("\n|-%c-|-%c-|-%c-| \n|-%c-|-%c-|-%c-| \n|-%c-|-%c-|-%c-| \n", mas[0][0], mas[0][1], mas[0][2], mas[1][0], mas[1][1], mas[1][2], mas[2][0], mas[2][1], mas[2][2]);
}

void main()
{
    while (1) {
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
        while (1) {
            int game = 1;
            while (game) {
                if (Choise == 1) {
                    mas[3][4] = igrok(mas, Choise);
                    game = check(mas, 0);
                    pole(mas);
                    mas[3][4] = bot(mas, Choise);
                    game = check(mas, 0);
                    pole(mas);
                }
                else {
                    mas[3][4] = bot(mas, Choise);
                    game = check(mas, 0);
                    pole(mas);
                    mas[3][4] = igrok(mas, Choise);
                    game = check(mas, 0);
                    pole(mas);
                }
            }
            int again = 0;
            printf("Сыграть ещё раз?\n 1. Да\n 2. Нет\n");
            scanf("%d", again);
            while (1) {
                if (again > 2 || again < 1) {
                    printf("Выберите один из предложенных пунктов!\n");
                }
                else {
                    break;
                }
            }
            if (again == 2) {
                break;
            }
        }
    }
}