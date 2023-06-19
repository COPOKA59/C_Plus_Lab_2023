#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <msclr\marshal_cppstd.h>

// ����� �����
public struct MyPoint
{
	int x;
	int y;
};

MyPoint SetPoint(int x, int y) {
	MyPoint poi{};
	poi.x = x;
	poi.y = y;
	return poi;
}
int PointGetX(MyPoint a) { return a.x; }
int PointGetY(MyPoint a) { return a.y; }

double Distance(MyPoint a) {
	return sqrt(PointGetX(a) * PointGetX(a) + PointGetY(a) * PointGetY(a));
}

double Distanse_two(MyPoint a, MyPoint b) {
	return sqrt((PointGetX(b) - PointGetX(a)) * (PointGetX(b) - PointGetX(a)) + (PointGetY(b) - PointGetY(a)) * (PointGetY(b) - PointGetY(a)));
}


using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

// ���������� �������� � �����
int CountStructs(FILE* fp)
{
	int len;
	fseek(fp, 0L, SEEK_END); // ��������� � ����� �����
	len = ftell(fp); // ������ ������� - ��� � ����� ����� �����
	fseek(fp, 0L, SEEK_SET); // ��������� ����� � ������ �����
	return len / sizeof(MyPoint); // ���-�� ��������
}

// ������ ����� � ��������� ������ � ���������
int StructText(MyPoint* Arr, int CountPar, TextBox^ textbox) {
	using namespace std;

	String^ name = Convert::ToString(textbox->Text);
	std::string unmanaged = msclr::interop::marshal_as<std::string>(name);
	ifstream in(unmanaged.c_str());

	//���� �������� ����� ������ �������
	if (in.is_open())
	{
		//������� ��������� ������� ����� � �����
		int count = 0;// ����� ����� � �����
		int temp;//��������� ����������

		while (!in.eof())// ��������� ���� �� �������� ����� ����� eof
		{
			in >> temp;//� ������� ��������� �� ����� �����
			count++;// ����������� ������� ����� �����
		}

		//����� ����� ���������, ������ ��� ����� ������ �������
		//����� � ����� ������
		//��� ����� ��������� ����� �������� �� ����� �������� �� ����� ������

		//������� ��������� ������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//����� �������� � ������ ������� ������� ����� 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//�� ������ ������ ���� ������������ ������ �����
		{
			//������ ��� ����� ��������� �� �����, � ����������� ��������� ������
			in.get(symbol);//������� ������� ������
			if (symbol == ' ') count_space++;//���� ��� ������, �� ����� �������� �����������
			if (symbol == '\n') break;//���� ����� �� ����� ������, �� ������� �� �����
		}
		//cout << count_space << endl;

		//����� ��������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//������ �� ����� ������� ����� � ����� � ������� �������� � ������ ������.
		//������ ����� ������� �������.

		int n = count / (count_space + 1);//����� �����
		int m = count_space + 1;//����� �������� �� ������� ������ ����� ��������
		double** x;
		x = new double* [n];
		for (int i = 0; i < n; i++) x[i] = new double[m];

		//������� ������� �� �����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];

		//���������� �������
		for (int i = 0; i < n; i++)
		{

			Arr[CountPar] = SetPoint(x[i][0], x[i][1]);
			CountPar++;
		}


		for (int i = 0; i < n; i++) delete[] x[i];
		delete[] x;

		in.close();//��� ����� ������� �����
	}
	return CountPar;
}