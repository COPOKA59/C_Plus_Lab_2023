#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <msclr\marshal_cppstd.h>

// Класс Точки
public struct MyPoint
{
	int x;
	int y;
};

MyPoint SetPoint(int x, int y) {
	MyPoint poi{};
	poi.x = x;
	poi.y = y;
	return poi;
}
int PointGetX(MyPoint a) { return a.x; }
int PointGetY(MyPoint a) { return a.y; }

double Distance(MyPoint a) {
	return sqrt(PointGetX(a) * PointGetX(a) + PointGetY(a) * PointGetY(a));
}

double Distanse_two(MyPoint a, MyPoint b) {
	return sqrt((PointGetX(b) - PointGetX(a)) * (PointGetX(b) - PointGetX(a)) + (PointGetY(b) - PointGetY(a)) * (PointGetY(b) - PointGetY(a)));
}


using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

// Количество структур в файле
int CountStructs(FILE* fp)
{
	int len;
	fseek(fp, 0L, SEEK_END); // Переходим в конец файла
	len = ftell(fp); // Читаем позицию - это и будет длина файла
	fseek(fp, 0L, SEEK_SET); // Переходим снова в начало файла
	return len / sizeof(MyPoint); // Кол-во структур
}

// Чтение файла и занесение данных в структуры
int StructText(MyPoint* Arr, int CountPar, TextBox^ textbox) {
	using namespace std;

	String^ name = Convert::ToString(textbox->Text);
	std::string unmanaged = msclr::interop::marshal_as<std::string>(name);
	ifstream in(unmanaged.c_str());

	//Если открытие файла прошло успешно
	if (in.is_open())
	{
		//Вначале посчитаем сколько чисел в файле
		int count = 0;// число чисел в файле
		int temp;//Временная переменная

		while (!in.eof())// пробегаем пока не встретим конец файла eof
		{
			in >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}

		//Число чисел посчитано, теперь нам нужно понять сколько
		//чисел в одной строке
		//Для этого посчитаем число пробелов до знака перевода на новую строку

		//Вначале переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}
		//cout << count_space << endl;

		//Опять переходим в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
		//Теперь можем считать матрицу.

		int n = count / (count_space + 1);//число строк
		int m = count_space + 1;//число столбцов на единицу больше числа пробелов
		double** x;
		x = new double* [n];
		for (int i = 0; i < n; i++) x[i] = new double[m];

		//Считаем матрицу из файла
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];

		//Заполнение массива
		for (int i = 0; i < n; i++)
		{

			Arr[CountPar] = SetPoint(x[i][0], x[i][1]);
			CountPar++;
		}


		for (int i = 0; i < n; i++) delete[] x[i];
		delete[] x;

		in.close();//под конец закроем файла
	}
	return CountPar;
}