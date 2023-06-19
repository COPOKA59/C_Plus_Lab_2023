#include "Cone.h"

int size;
Cone* coneArr;

void updateArr(int i, double r, double h, double x, double y, double z)
{
	coneArr[i].ConeSetR(r);
	coneArr[i].ConeSetH(h);
	coneArr[i].ConeSetX(x);
	coneArr[i].ConeSetY(y);
	coneArr[i].ConeSetZ(z);
}
void CalcL(int i) { coneArr[i].CalcL(); }
void CalcSO(int i) { coneArr[i].CalcSO(); }
void CalcSB(int i) { coneArr[i].CalcSB(); }
void CalcS(int i) { coneArr[i].CalcS(); }
void CalcV(int i) { coneArr[i].CalcV(); }
void MultN(int i, double N) { coneArr[i].MultN(N); }

// Заполнение с шагом
void fill_start_step(Cone start_cone, double* steps)
{
	coneArr = new Cone[size];
	for (int i = 0; i < size; i++)
	{
		coneArr[i] = start_cone;
		start_cone.ConeSetR(start_cone.ConeGetR() + steps[0]);
		start_cone.ConeSetH(start_cone.ConeGetH() + steps[1]);
		start_cone.ConeSetX(start_cone.ConeGetX() + steps[2]);
		start_cone.ConeSetY(start_cone.ConeGetY() + steps[3]);
		start_cone.ConeSetZ(start_cone.ConeGetZ() + steps[4]);
	}
}
void fill_base()
{
	coneArr = new Cone[size];
	for (int i = 0; i < size; i++)
	{
		coneArr[i] = Cone();
	}
}

// Функция для сравнения двух конусов на большее по объёму
bool CravCone(double v1, double v2) 
{
	if (v1 < v2)
		return true;
	else false;
}
double CravConeBol(Cone one, Cone two)
{
	if (CravCone(one.CalcV(), two.CalcV()))
		return one.CalcV() / two.CalcV();
	else
		return two.CalcV() / one.CalcV();
}