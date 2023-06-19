#pragma once
#include "BigIndicator.h"

typedef unsigned int UINT; // объявим новое имя типа 

class IArray // Класс – массив фигур 
{
private:
	BigIndicator** Arr; // Указатель на будущий массив указателей 
	UINT Len;   // Размер массива 
public:
	IArray(); // Конструктор по умолчанию 
	IArray(UINT len); // Конструктор, для массива размера len 
	~IArray(); // Деструктор 

	void SetSize(UINT l); // Задание размера массива и выделение памяти 
	void SetType(UINT i, UINT type); // Задаем тип i-той фигуры 

	UINT GetSize();
	UINT GetType(UINT i);

	BigIndicator* operator[](UINT i); // Обращение к i-тому элементу массива 
	IArray& operator=(const IArray& G);

	void Clear(); // Очистка массива 
};