#include "IArray.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"

enum { IA, IB, IC, ID };

IArray::IArray() { Arr = 0; Len = 0; }

IArray::IArray(UINT len)
{
	Arr = 0;   
	Len = 0;
	SetSize(len); // ���������� ����� ������ 
}

IArray::~IArray() { Clear(); }

void IArray::SetSize(UINT l) // ������� ������� ������� 
{
	Clear();        // ������� ������ 
	Len = l;  
	Arr = new BigIndicator*[Len]; // �������� ������ ��� ������                           
	                                // ���������� �� BigIndicator  
	for (UINT i = 0; i < Len; i++)    
		Arr[i] = new A; // ���� ������ �� ������� � �������� ��������� 
	// (��� ����� ������� �� ��������� ������, ����. ��������������) 
}

void IArray::SetType(UINT i, UINT type) // ������� ���� ������ 
{           // i � ������ �������� ������� � ��������� �� BigIndicator   
	if (type >= 4) throw 11;  // �������� ��� 
	if (i < Len) // ���� ������ ������  
	{   
		if (Arr[i])
			delete Arr[i]; // ���� ��� ����������� ������ - �������   
		switch (type) // � ����������� �� ���� ������� ������:   
		{
		case IA:
			Arr[i] = new A; 
			break;
		case IB:
			Arr[i] = new B; 
			break;
		case IC:
			Arr[i] = new C;   
			break;
		case ID:
			Arr[i] = new D;    
			break;
		}
	}  else   
		throw 10;   // ����� �� ������� ������� 
}

UINT IArray::GetSize(){	return Len; }

UINT IArray::GetType(UINT i)
{
	BigIndicator* s;  
	if (s = dynamic_cast<A*>(Arr[i]))  return IA;  
	if (s = dynamic_cast<B*>(Arr[i]))  return IB;  
	if (s = dynamic_cast<C*>(Arr[i]))  return IC;  
	if (s = dynamic_cast<D*>(Arr[i]))  return ID; 
	throw 13;  //  ����������� ��� 
}

BigIndicator* IArray::operator[](UINT i)// ��������� � �������� ������� 
{
	if (i < Len) {
		if (Arr[i])    
			return Arr[i];   
		throw 12;   // i-��� ������ ��� �� ���� �������  
	}  
	throw 10;       // ����� �� ������� ������� 
}

IArray& IArray::operator=(const IArray& G)
{                             // ��������������� ��������� = 
	if (this == &G) 
		return *this;  // �������� �� �����. ������ ���� 
	Clear();                     // ������� ������  
	SetSize(G.Len);              // �������� ������   
	//for(UINT i=0; i<Len; i++)    // ��� ������� ���������  
	//{                            // ������� ������ ���� �� ����, ��� �    
	//	SetType(i, G.GetType(i)); // ��������������� ������ �� ������� A,   
	//	*(Arr[i]) = *(G.Arr[i]);  // � �������� ��� ���������  
	//}  
	Arr = G.Arr;
	return *this;
}

void IArray::Clear()
{
	if (Arr) // ���� ������ ����������  
	{   
		for (UINT i = 0; i < Len; i++) // ������� � �����,     
			if (Arr[i]) delete Arr[i]; // ���� ������ �����������, -                                 
	                                   // ������� ��,   
		delete[] Arr; // ������� ������, ���������� ��� ������ ����������   
		Arr = 0;   
		Len = 0;  
	}
}
