#include <cmath>
using namespace System::Drawing;
// ����� �����
class Cone {
private:
	int R; // ������
	int H; // ������

	int X; // ���������� ������ ���������� ������
	int Y;
	int Z;
public:
	// ������������
	Cone();
	Cone(int r, int h, int x, int y, int z);
	// ������� �������� ��������� ������
	int ConeGetR();
	int ConeGetH();
	int ConeGetX();
	int ConeGetY();
	int ConeGetZ();
	// �������� �������� ��������� ������
	void ConeSetR(int r);
	void ConeSetH(int h);
	void ConeSetX(int x);
	void ConeSetY(int y);
	void ConeSetZ(int z);
	// ������ ��� ������ � ������� ������
	double CalcL();// ����������(+ ��� ����� ��� ������)
	double CalcSO(); // ������� ���������
	double CalcSB(); // ������� ������� �������
	double CalcS(); // ����� �������
	double CalcV(); // ���������� ������ ������

	void MultN(int N); // ��������� ���������� ������ �� ��������� �����
	void DelN(int N); // ������� ���������� ������ �� ��������� �����
	// ���������:
	friend void operator*=(Cone cone, int k);	//a* = k ��������� ���������� ������ �� ��������� �����
	friend void operator/=(Cone cone, int k);	//a / = k ������� ���������� ������ �� ��������� �����
	friend double operator/(Cone cone1, Cone cone2);	//k = a / b ���������� ��������� ������� ���� �������
	friend int operator-(Cone cone1, Cone cone2);	//k = a � b ���������� �������� ������� ���� �������
	friend int operator+(Cone cone1, Cone cone2);	//k = a + b ���������� ����� ������� ���� �������
	friend bool operator<(Cone cone1, Cone cone2);	//a < b(a > b) ��������� ���� ������� ��(�� ������) < (> )
	friend bool operator>(Cone cone1, Cone cone2);
	friend bool operator==(Cone cone1, Cone cone2);	//a == b ��������� ���� ������� ��(�� ������) ==

	// ����� ��� ��������� �������, ������ ������� !!!
	void Draw(Graphics^ gr, Pen^ pen);
};
