#define _CRT_SECURE_NO_WARNINGS
#include <conio.h> // Подключаем заголовочный файл с описанием функции getch
#include <stdio.h> // Подключаем заголовочный файл с описанием функции printf
#include <locale.h> // Подключаем заголовочный файл с описанием функции setlocale
#include <iostream>

/* Лабораторная работа № 3, Вариант 13;
   Макарова Полина, 2 курс, гр. ПМИ-2 */

   /* Вариант 13 >
      Разработать функцию, которая циклически сдвигает целое число x влево на
      n разрядов (например, 123456 сдвинуть на 2 разряда = 345612).
   */


   // Функция подсчёта колличества цифр в числе
int number_of_digits(int Value)
{
    int i;
    for (i = 0; Value != 0; i++) {
        Value /= 10;
    }
    return i;
}
// Функция для вычисления степени 10
int degree_of_ten(int Value)
{
    int a = 10;
    for (int i = 1; i != (Value - 1); i++)
    {
        a *= 10;
    }
    return a;
}
// Функция сдвига числа влево
int left_shift(int x, int n)
{
    // count - переменная для подсчёта цифр в числе x
    int count;
    count = number_of_digits(x);
    // degree - переменная 10^count
    int degree;
    degree = degree_of_ten(count);

    int one;
    // Циклический сдвиг по цифре влево
    for (int i = 0; i != n; i++)
    {
        one = x / degree;
        x = (x % degree) * 10 + one;
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Смена кодировки
    printf(" |   Макарова Полина, 2 курс, гр. ПМИ-2   |\n");
    printf(" |   Лабораторная работа № 3, Вариант 13  |\n");
    // Объявление переменных
    // x - целое число
    int x, n;
    // Ввод данных с клавиатуры
    printf("\nВведите целое число: ");
    scanf("%d", &x);
    printf("\nВведите ко-во разрядов, на которое надо сдвинуть число влево: ");
    scanf("%d", &n);

    printf("\n\n Введённое число: %10d\n Введённый сдвиг: %10d\n\n", x, n);

    // Вызов функции
    x = left_shift(x, n);

    // Вывод результата
    printf("   Результат: %10d\n", x);
}