#pragma once
#include <cmath>
using namespace System::Drawing;

class BigIndicator
{
protected:
	// ������ ����������
	int W; // �����(������)
	int H; // ������
	// ���������� ������ �������� ����
	int X;
	int Y;
	// ����(��� � � �): 0 - �����, 1 - �������
	int IColor; // ��� ���� ����� ������������ � ���������� ��� � �������
	// ���������(��� � � � + �������): 0 - ��������, 1 - �������
	int Condition;
public:
	// ������������
	BigIndicator();
	BigIndicator(int w, int h, int x, int y, int Icol, int con);
	// ������� �������� ��������� ������
	int GetW();
	int GetH();
	int GetX();
	int GetY();
	int GetCol();
	int GetCon();
	// �������� �������� ��������� ������
	void SetW(int w);
	void SetH(int h);
	void SetX(int x);
	void SetY(int y);
	void SetCol(int Icol);
	void SetCon(int con);

	// ������ ��� ������ � ������� ������
	// ����� ��� ��������� ����������
	virtual void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite) = 0;
};