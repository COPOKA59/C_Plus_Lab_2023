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
	SetSize(len); // Используем метод класса 
}

IArray::~IArray() { Clear(); }

void IArray::SetSize(UINT l) // Задание размера массива 
{
	Clear();        // Очищаем память 
	Len = l;  
	Arr = new BigIndicator*[Len]; // Выделяем память под массив                           
	                                // указателей на BigIndicator  
	for (UINT i = 0; i < Len; i++)    
		Arr[i] = new A; // Пока фигуры не созданы – обнуляем указатели 
	// (или можно создать по умолчанию фигуры, напр. прямоугольники) 
}

void IArray::SetType(UINT i, UINT type) // Задание типа фигуры 
{           // i – индекс элемента массива – указателя на BigIndicator   
	if (type >= 4) throw 11;  // неверный тип 
	if (i < Len) // Если индекс верный  
	{   
		if (Arr[i])
			delete Arr[i]; // Если уже создавалась фигура - удаляем   
		switch (type) // В зависимости от типа создаем фигуры:   
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
		throw 10;   // выход за пределы массива 
}

UINT IArray::GetSize(){	return Len; }

UINT IArray::GetType(UINT i)
{
	BigIndicator* s;  
	if (s = dynamic_cast<A*>(Arr[i]))  return IA;  
	if (s = dynamic_cast<B*>(Arr[i]))  return IB;  
	if (s = dynamic_cast<C*>(Arr[i]))  return IC;  
	if (s = dynamic_cast<D*>(Arr[i]))  return ID; 
	throw 13;  //  Неизвестный тип 
}

BigIndicator* IArray::operator[](UINT i)// Обращение к элементу массива 
{
	if (i < Len) {
		if (Arr[i])    
			return Arr[i];   
		throw 12;   // i-тая фигура еще не была создана  
	}  
	throw 10;       // выход за пределы массива 
}

IArray& IArray::operator=(const IArray& G)
{                             // Переопределение оператора = 
	if (this == &G) 
		return *this;  // проверка на присв. самому себе 
	Clear();                     // Очищаем массив  
	SetSize(G.Len);              // Выделяем память   
	//for(UINT i=0; i<Len; i++)    // Для каждого указателя  
	//{                            // создаем объект того же типа, что и    
	//	SetType(i, G.GetType(i)); // соответствующий объект из массива A,   
	//	*(Arr[i]) = *(G.Arr[i]);  // и копируем его параметры  
	//}  
	Arr = G.Arr;
	return *this;
}

void IArray::Clear()
{
	if (Arr) // Если память выделялась  
	{   
		for (UINT i = 0; i < Len; i++) // Сначала в цикле,     
			if (Arr[i]) delete Arr[i]; // если фигура создавалась, -                                 
	                                   // удаляем ее,   
		delete[] Arr; // очищаем память, выделенную под массив указателей   
		Arr = 0;   
		Len = 0;  
	}
}
