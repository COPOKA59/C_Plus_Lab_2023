#pragma once
#include "Queue.h"
#include "QueueException.h"
#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
	size_t Size; // �����
	T* S; // ��������� �� ������� ������ ������
	int Len;
public:
	Queue(); // �����������
	~Queue(); // ����������
	void Push(T elem); // ����� ��������� ++����� ��� ��������
	T Pop(); // ����� --����� ��� ��������
	T Check(); // ������� �������
	bool IsEmpty(); // �������� �� ������ �������
	bool FullQueue(); // �������� �� ������������ �������
	unsigned long GetSize();
	unsigned long GetLen();
	void SetSize(int size); // ������ ������ �������
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
	// �������� �� ����������� �� �������
	if (FullQueue()) {
		// ����������� ������� �� 1
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
		// ��������� ������� � �������
		S[Len] = elem;
	}
	Len += 1;
}

template <class T>
T Queue<T>::Pop()
{
	// ������� ������ ������� �� �������
	if (IsEmpty())
		throw StackEmptyException("������� �����");
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
		throw StackEmptyException("������� �����");
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
	if (S) delete[] S; // ������� ������
	Size = size; // �������� ������ �������
	S = new T[Size]; // ������� ����� ������� � ����� ��������
	Len = 0;
}


template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T>& queue)
{
	if (S) delete[] S; // ������� ������
	Size = queue.Size; // �������� ������ �������
	Len = queue.Len;
	S = new T[queue.Size]; // ������� ����� ������� � ����� ��������
	for (int i = 0; i < queue.Len; ++i)
		S[i] = queue.S[i];

	return *this;
}