#pragma once
#include "Queue.h"
#include "QueueException.h"
#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
	size_t Size; // Длина
	T* S; // Указатель на будущий массив данных
	int Len;
public:
	Queue(); // Конструктор
	~Queue(); // Деструктор
	void Push(T elem); // Сдвиг элементов ++место для элемента
	T Pop(); // Сдвиг --место для элемента
	T Check(); // Достать элемент
	bool IsEmpty(); // Проверка на пустую очередь
	bool FullQueue(); // Проверка на переполненую очередь
	unsigned long GetSize();
	unsigned long GetLen();
	void SetSize(int size); // Задать размер очереди
	Queue& operator = (const Queue<T>&);
	friend ostream& operator<< (ostream& out, Queue<T> stack);
};

template <class T>
Queue<T>::Queue()
{
	S = 0;
	Size = 0;
}

template <class T>
Queue<T>::~Queue()
{
	if (S)
		delete[] S;
}

template <class T>
void Queue<T>::Push(T elem)
{
	// Проверка не переполнена ли очередь
	if (FullQueue()) {
		// Увеличиваем очередь на 1
		T* temp = new T[Size + 1];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = S[i];
		}
		temp[Size] = elem;
		Size++;
		delete[] S;
		S = new T[Size];
		S = temp;
	}
	else 
	{
		// Добавляем элемент в очередь
		S[Len] = elem;
	}
	Len += 1;
}

template <class T>
T Queue<T>::Pop()
{
	// Извлечь первый элемент из очереди
	if (IsEmpty())
		throw StackEmptyException("Очередь пуста");
	T value = S[0];
	Len -= 1;

	T* temp = new T[Size];
	for (int i = 0; i < Len; i++)
	{
		temp[i] = S[i+1];
	}
	delete[] S;
	S = new T[Size];
	S = temp;

	return value;
}

template <class T>
T Queue<T>::Check()
{
	if (IsEmpty())
		throw StackEmptyException("Очередь пуста");
	return S[0];
}

template <class T>
bool Queue<T>::IsEmpty()
{
	return true ? Len == 0 : false;
}

template<class T>
inline bool Queue<T>::FullQueue()
{
	if (Len == Size)
		return true;
	return false;
}

template <class T>
unsigned long Queue<T>::GetSize()
{
	return Size;
}

template<class T>
inline unsigned long Queue<T>::GetLen()
{
	return Len;
}

template<class T>
void Queue<T>::SetSize(int size)
{
	if (S) delete[] S; // Удалили данные
	Size = size; // Изменили размер очереди
	S = new T[Size]; // Создали новую очередь с новым размером
	Len = 0;
}


template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T>& queue)
{
	if (S) delete[] S; // Удалили данные
	Size = queue.Size; // Изменили размер очереди
	Len = queue.Len;
	S = new T[queue.Size]; // Создали новую очередь с новым размером
	for (int i = 0; i < queue.Len; ++i)
		S[i] = queue.S[i];

	return *this;
}