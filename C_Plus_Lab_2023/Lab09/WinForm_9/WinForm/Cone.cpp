#include "Cone.h"
#include <cmath>
const double PI = 3.14;

Cone::Cone()
{
	R = 20; // Радиус от  20 до 200 пикселов
	H = 2; // Высота до 300 см
	X = 0;
	Y = 0;
	Z = 0;
}

Cone::Cone(double r, double h, double x, double y, double z)
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

double Cone::ConeGetR() { return R; }
double Cone::ConeGetH() { return H; }
double Cone::ConeGetX() { return X; }
double Cone::ConeGetY() { return Y; }
double Cone::ConeGetZ() { return Z; }

void Cone::ConeSetR(double r)
{
	if (r > 20 && r < 200) {
		R = r;
	}
}
void Cone::ConeSetH(double h)
{
	if (h < 300) {
		H = h;
	}
}
void Cone::ConeSetX(double x){X = x;}
void Cone::ConeSetY(double y){Y = y;}
void Cone::ConeSetZ(double z){Z = z;}

double Cone::CalcL()
{
	return sqrt(H * H + R * R);
}
double Cone::CalcSO()
{
	return PI * R * R;
}
double Cone::CalcSB()
{
	return PI * R * CalcL();
}
double Cone::CalcS()
{
	return PI * R * ( R + CalcL());
}
double Cone::CalcV()
{
	return PI * R * R * H / 3;
}

void Cone::MultN(double N)
{
	double r = R * N;
	double h = H * N;
	// Проверка, что числа не выходят за рамки
	ConeSetR(r);
	ConeSetH(h);
}

