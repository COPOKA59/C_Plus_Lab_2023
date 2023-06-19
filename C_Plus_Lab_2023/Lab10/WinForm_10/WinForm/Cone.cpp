#include "Cone.h"
#include <cmath>
using namespace System::Drawing;

const double PI = 3.14;

Cone::Cone()
{
	R = 20; // Радиус от  20 до 200 пикселов
	H = 2; // Высота до 300 см
	X = 0;
	Y = 0;
	Z = 0;
}

Cone::Cone(int r, int h, int x, int y, int z)
{
	R = 20; // Радиус от  20 до 200 пикселов
	H = 2; // Высота до 300 см
	X = 0;
	Y = 0;
	Z = 0;
	// Проверка, что числа не выходят за рамки
	ConeSetR(r);
	ConeSetH(h);
	ConeSetX(x);
	ConeSetY(y);
	ConeSetZ(z);
}

int Cone::ConeGetR() { return R; }
int Cone::ConeGetH() { return H; }
int Cone::ConeGetX() { return X; }
int Cone::ConeGetY() { return Y; }
int Cone::ConeGetZ() { return Z; }

void Cone::ConeSetR(int r){
	if (r > 20 && r < 200) {
		R = r;
	}
}
void Cone::ConeSetH(int h){
	if (h < 300) {
		H = h;
	}
}
void Cone::ConeSetX(int x){X = x;}
void Cone::ConeSetY(int y){Y = y;}
void Cone::ConeSetZ(int z){Z = z;}

double Cone::CalcL(){
	return sqrt(H * H + R * R);
}
double Cone::CalcSO(){
	return PI * R * R;
}
double Cone::CalcSB(){
	return PI * R * CalcL();
}
double Cone::CalcS(){
	return PI * R * ( R + CalcL());
}
double Cone::CalcV(){
	return PI * R * R * H / 3;
}

void Cone::MultN(int N)
{
	int r = R * N;
	int h = H * N;
	// Проверка, что числа не выходят за рамки
	ConeSetR(r);
	ConeSetH(h);
}

void Cone::DelN(int N)
{
	int r = R / N;
	int h = H / N;
	// Проверка, что числа не выходят за рамки
	ConeSetR(r);
	ConeSetH(h);
}

void Cone::Draw(Graphics^ gr, Pen^ pen)
{
	{
		// Координаты точки указывают на центр окружности ->
			// Что бы расположить Конус правильно, надо его переместить в низ на высоту
			// Круг основания
		gr->DrawEllipse(pen, (X + (R / 2)), (Y + H), R, 25);
		// Линии, создающие конус с кругом
		gr->DrawLine(pen, (X + (R / 2)), (Y + H) + 12.5, (X + R), Y);
		gr->DrawLine(pen, (X + R), Y, (X + R), (Y + H) + 12.5);
		gr->DrawLine(pen, (X + R), Y, (X + R + R / 2), (Y + H) + 12.5);
	}
}

void operator*=(Cone cone, int k){ cone.MultN(k); }
void operator/=(Cone cone, int k){ cone.DelN(k); }

double operator/(Cone cone1, Cone cone2){
	return cone1.CalcV() / cone2.CalcV();
}
int operator-(Cone cone1, Cone cone2){
	return cone1.CalcV() - cone2.CalcV();
}
int operator+(Cone cone1, Cone cone2){
	return cone1.CalcV() + cone2.CalcV();
}
bool operator<(Cone cone1, Cone cone2){
	return cone1.CalcV() < cone2.CalcV();
}
bool operator>(Cone cone1, Cone cone2){
	return cone1.CalcV() > cone2.CalcV();
}
bool operator==(Cone cone1, Cone cone2){
	return cone1.CalcV() == cone2.CalcV();
}


