#pragma once
#include <iostream>
#include <cmath>
using namespace std;

// Класс Конус
class Cone {
private:
	double R; // Радиус
	double H; // Высота

	double X; // Координаты центра окружности косинуса
	double Y;
	double Z;
public:
	// Конструкторы
	Cone();
	Cone(double r, double h, double x, double y, double z);
	// Достать значение параметра класса
	double ConeGetR();
	double ConeGetH();
	double ConeGetX();
	double ConeGetY();
	double ConeGetZ();
	// Изменить значение параметра класса
	void ConeSetR(double r);
	void ConeSetH(double h);
	void ConeSetX(double x);
	void ConeSetY(double y);
	void ConeSetZ(double z);
	// Методы для работы с данными класса
	double CalcL();// Образующая(+ доп класс для работы)
	double CalcSO(); // Площади основания
	double CalcSB(); // площадь боковой стороны
	double CalcS(); // Общая площадь
	double CalcV(); // Вычисление объёма конуса

	void MultN(double N);// Умножение параметров конуса на некоторое число

	friend ostream& operator<< (ostream& out, Cone Cone);
	friend istream& operator>> (istream& in, Cone& Cone);
};
