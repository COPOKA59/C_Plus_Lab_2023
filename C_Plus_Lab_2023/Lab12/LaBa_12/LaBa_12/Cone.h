#pragma once
#include <iostream>
#include <cmath>
using namespace std;

// ����� �����
class Cone {
private:
	double R; // ������
	double H; // ������

	double X; // ���������� ������ ���������� ��������
	double Y;
	double Z;
public:
	// ������������
	Cone();
	Cone(double r, double h, double x, double y, double z);
	// ������� �������� ��������� ������
	double ConeGetR();
	double ConeGetH();
	double ConeGetX();
	double ConeGetY();
	double ConeGetZ();
	// �������� �������� ��������� ������
	void ConeSetR(double r);
	void ConeSetH(double h);
	void ConeSetX(double x);
	void ConeSetY(double y);
	void ConeSetZ(double z);
	// ������ ��� ������ � ������� ������
	double CalcL();// ����������(+ ��� ����� ��� ������)
	double CalcSO(); // ������� ���������
	double CalcSB(); // ������� ������� �������
	double CalcS(); // ����� �������
	double CalcV(); // ���������� ������ ������

	void MultN(double N);// ��������� ���������� ������ �� ��������� �����

	friend ostream& operator<< (ostream& out, Cone Cone);
	friend istream& operator>> (istream& in, Cone& Cone);
};
