#include <cmath>
using namespace System::Drawing;
// Класс Конус
class Cone {
private:
	int R; // Радиус
	int H; // Высота

	int X; // Координаты центра окружности конуса
	int Y;
	int Z;
public:
	// Конструкторы
	Cone();
	Cone(int r, int h, int x, int y, int z);
	// Достать значение параметра класса
	int ConeGetR();
	int ConeGetH();
	int ConeGetX();
	int ConeGetY();
	int ConeGetZ();
	// Изменить значение параметра класса
	void ConeSetR(int r);
	void ConeSetH(int h);
	void ConeSetX(int x);
	void ConeSetY(int y);
	void ConeSetZ(int z);
	// Методы для работы с данными класса
	double CalcL();// Образующая(+ доп класс для работы)
	double CalcSO(); // Площади основания
	double CalcSB(); // площадь боковой стороны
	double CalcS(); // Общая площадь
	double CalcV(); // Вычисление объёма конуса

	void MultN(int N); // Умножение параметров конуса на некоторое число
	void DelN(int N); // Деление параметров конуса на некоторое число
	// Операторы:
	friend void operator*=(Cone cone, int k);	//a* = k умножение параметров конуса на некоторое число
	friend void operator/=(Cone cone, int k);	//a / = k деление параметров конуса на некоторое число
	friend double operator/(Cone cone1, Cone cone2);	//k = a / b вычисление отношения объемов двух конусов
	friend int operator-(Cone cone1, Cone cone2);	//k = a – b вычисление разности объемов двух конусов
	friend int operator+(Cone cone1, Cone cone2);	//k = a + b вычисление суммы объемов двух конусов
	friend bool operator<(Cone cone1, Cone cone2);	//a < b(a > b) сравнение двух конусов на(по объему) < (> )
	friend bool operator>(Cone cone1, Cone cone2);
	friend bool operator==(Cone cone1, Cone cone2);	//a == b сравнение двух конусов на(по объему) ==

	// Метод для рисования конусов, БОЛЬШЕ КОНУСОВ !!!
	void Draw(Graphics^ gr, Pen^ pen);
};
