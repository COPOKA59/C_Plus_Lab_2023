#pragma once
#include "BigIndicator.h"

typedef unsigned int UINT; // ������� ����� ��� ���� 

class IArray // ����� � ������ ����� 
{
private:
	BigIndicator** Arr; // ��������� �� ������� ������ ���������� 
	UINT Len;   // ������ ������� 
public:
	IArray(); // ����������� �� ��������� 
	IArray(UINT len); // �����������, ��� ������� ������� len 
	~IArray(); // ���������� 

	void SetSize(UINT l); // ������� ������� ������� � ��������� ������ 
	void SetType(UINT i, UINT type); // ������ ��� i-��� ������ 

	UINT GetSize();
	UINT GetType(UINT i);

	BigIndicator* operator[](UINT i); // ��������� � i-���� �������� ������� 
	IArray& operator=(const IArray& G);

	void Clear(); // ������� ������� 
};