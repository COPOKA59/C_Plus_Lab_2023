#pragma once
#include <cmath>
using namespace System::Drawing;

class BigIndicator
{
protected:
	// Размер индикатора
	int W; // Длина(ширина)
	int H; // Высота
	// Координаты левого верхнего угла
	int X;
	int Y;
	// Цвет(для А и Б): 0 - белый, 1 - красный
	int IColor; // Сам цвет будет определяться и рисоваться уже в рисунке
	// Состояние(для В и Г + надписи): 0 - выключен, 1 - включён
	int Condition;
public:
	// Конструкторы
	BigIndicator();
	BigIndicator(int w, int h, int x, int y, int Icol, int con);
	// Достать значение параметра класса
	int GetW();
	int GetH();
	int GetX();
	int GetY();
	int GetCol();
	int GetCon();
	// Изменить значение параметра класса
	void SetW(int w);
	void SetH(int h);
	void SetX(int x);
	void SetY(int y);
	void SetCol(int Icol);
	void SetCon(int con);

	// Методы для работы с данными класса
	// Метод для рисования индикатора
	virtual void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite) = 0;
};