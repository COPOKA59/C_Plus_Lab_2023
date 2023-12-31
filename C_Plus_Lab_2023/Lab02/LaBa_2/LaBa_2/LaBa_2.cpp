﻿#define _CRT_SECURE_NO_WARNINGS
#include <conio.h> // Подключаем заголовочный файл с описанием функции getch
#include <stdio.h> // Подключаем заголовочный файл с описанием функции printf
#include <locale.h> // Подключаем заголовочный файл с описанием функции setlocale
#include <iostream>

/* Лабораторная работа № 2, Вариант 13;
   Макарова Полина, 2 курс, гр. ПМИ-2 */

   /* Вариант 13 >
      a(n) = (-1^n)*((n+1)/(5*n+3^(n+1)))
   */

int main()
{
    setlocale(LC_ALL, "Russian"); // Смена кодировки
    // Объявление переменных
      // n - параметр цикла, Count - кол-во членов ряда для суммы, k2 = 3^(n+1)
      // a - значение текущего члена, Eps - точность вычисления членов ряда, Sum - сумма членов ряда, S - сумма первых членов ряда
      // k1 - (-1)^n
    int n, Count;
    double a, k2, Eps, Sum, S = 0;
    short k1;
    char key = '0';

    printf(" 1 Задание");
    do
    {
        // Ввод данных с клавиатуры
        printf("\nВведите точность: \n");
        scanf("%lf", &Eps);
        printf("Введите колличество членов ряда для подсчёта суммы: \n");
        scanf("%d", &Count);

        // Заголовок таблицы
        printf("\n------------------------");
        printf("\n|   n  |      a(n)     |");
        printf("\n------------------------");

        // Цикл подсчёта членов ряда
        for (n = 0, Sum = 0, k1 = 1, k2 = 3; ; n++, k2 *= 3, k1 = -k1)
        {
            a = k1 * ((double)(n + 1) / (5 * n + (double)k2)); // n-й член ряда
            if (fabs(a) < Eps) // Если член ряда меньше указанной точности
                break;         // => выход из цикла

            printf("\n|%5d|%16.10f|", n, a); // Напечатать член ряда

            Sum += a;// Подсчёт всеё суммы
            if (n == Count - 1) // Если номер члена ряда меньше указанного для суммы
            {
                S = Sum;  // => посчёт суммы
                printf("  <="); // В консоли указывается член ряда, что идёт в счёт
            }
        }
        printf("\n------------------------");

        printf("\n Сумма всех членов ряда с заданной точностью : {%10.10f}", Sum);
        printf("\n Сумма первых членов ряда с заданной точностью : {%10.10f}\n", S);

        printf("\n Нажать 0, чтобы повторить > ");
        key = _getch();
    } while (key == '0');

    printf("\n\n 2 Задание\n\n");
    printf("|-------------|-------------|\n");
    printf("|      X      |      Y      |\n");
    printf("|-------------|-------------|\n");

    float x, y, x1;
    short h;

    for (n = 0; n < 5; n++) // внешний цикл для 5 периодов
    {
        for (x = 0; x < 4; x += 0.25) // внутр. цикл для одного периода
        {
            if (x < 2)
                y = sqrt(1 - (x - 1) * (x - 1)); // 1-й отрезок
            else if (x < 3)
                y = sqrt(1 - (x - 3) * (x - 3)); // 2-й отрезок
            else
                y = 4 - x;                           // 3-й отрезок
            x1 = x + n * 4;
            printf("| %11.2f | %11.7f |", x1, y); // вывод строки таблицы
            h = (y + 1) * 8 + 0.5; // определение позиции точки
            for (; h > 0; h--)
                printf(" "); // смещение точки графика
            printf("*\n");  // вывод точки графика
        } // конец внутреннего цикла
    } // конец внешнего цикла

    return 0;
}
