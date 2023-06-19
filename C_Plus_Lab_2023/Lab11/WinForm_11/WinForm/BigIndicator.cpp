#include "BigIndicator.h"
#include <cmath>
using namespace System::Drawing;

BigIndicator::BigIndicator()
{
	W = 20;
	H = 20;
	X = 0;
	Y = 0;
	IColor = 0;
	Condition = 0;
}

BigIndicator::BigIndicator(int w, int h, int x, int y, int Icol, int con)
{
	W = 20;
	H = 20;
	X = x;
	Y = y;
	IColor = 0;
	Condition = 0;

	SetW(w);
	SetH(h);
	SetCol(Icol);
	SetCon(con);
}

int BigIndicator::GetW(){ return W; }
int BigIndicator::GetH() { return H; }
int BigIndicator::GetX() { return X; }
int BigIndicator::GetY() { return Y; }
int BigIndicator::GetCol() { return IColor; }
int BigIndicator::GetCon() { return Condition; }

void BigIndicator::SetW(int w)
{
	if (w > 10)	W = w;
}
void BigIndicator::SetH(int h)
{
	if (h > 10)	H = h;
}
void BigIndicator::SetX(int x)
{
	X = x;
}
void BigIndicator::SetY(int y)
{
	Y = y;
}
void BigIndicator::SetCol(int Icol)
{
	if (Icol == 0 || Icol == 1) IColor = Icol;
}
void BigIndicator::SetCon(int con)
{
	if (con == 0 || con == 1) Condition = con;
}
