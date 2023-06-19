#include <iostream>
#include <iomanip>
#include "Cone.h"
#include "Queue.h"
#include "QueueException.h"

void select_option(char& key)
{
	cout << "Выберите действие, которые хотите сделать " << endl;
	cout << "1) Задать размер очереди" << endl; //
	cout << "2) Добавить элемент в очередь" << endl;
	cout << "3) Извлечь первый элемент из очереди" << endl; // первый
	cout << "4) Обратиться к первому элементу очереди" << endl; // первый
	cout << "5) Проверить очередь на пустоту" << endl;
	cout << "6) Проверить очередь на переполнение" << endl; //
	cout << "7) Прочесть количество элементов в очереди" << endl;
	cout << "8) Прочесть размер очереди" << endl;
	cout << "9) Скопировать одну очередь в другую" << endl;
	cout << "0) Выход" << endl;
	cin >> key;
}

void select_queue(char& key)
{
	cout << "Выберите очередь (1 или 2): ";
	cin >> key;
}

template <typename T>
void test_queue(Queue<T> stack1, Queue<T> stack2)
{
	T value;
	int Len;
	char key = '1';
	while (key != '0')
	{
		select_option(key);

		switch (key)
		{
		case '0': // Выход
			return;
		case '1': // Задать размер очереди
			select_queue(key);
			cout << "Введите размер " << endl;
			cin >> Len;
			if (key == '1')
				stack1.SetSize(Len);
			else
				stack2.SetSize(Len);
			break;
		case '2': // Добавить элемент в очередь
			select_queue(key);
			cout << "Введите данные " << endl;
			cout << "Для short: число" << endl;
			cout << "Для cone: радиус<Enter> высота<Enter> X<Enter> Y<Enter> Z<Enter>" << endl;
			cin >> value;

			if (key == '1')
				stack1.Push(value);
			else
				stack2.Push(value);
			break;
		case '3': // Извлечь первый элемент из очереди
			select_queue(key);
			try
			{
				if (key == '1')
					cout << stack1.Pop();
				else
					cout << stack2.Pop();
			}
			catch (StackEmptyException& e)
			{
				cout << e.what();
			}
			cout << endl;
			break;
		case '4': // Обратиться к первому элементу очереди
			select_queue(key);
			cout << "Первый элемент в очереди: ";
			try
			{
				if (key == '1')
					cout << stack1.Check();
				else
					cout << stack2.Check();
			}
			catch (StackEmptyException& e)
			{
				cout << e.what();
			}
			cout << endl;
			break;
		case '5': // Проверить очередь на пустоту
			select_queue(key);
			cout << "Очередь пуста: ";
			cout << boolalpha;
			if (key == '1')
				cout << stack1.IsEmpty();
			else
				cout << stack2.IsEmpty();
			cout << noboolalpha;
			cout << endl;
			break;
		case '6': // Проверить очередь на переполнение
			select_queue(key);
			cout << "Очередь переполнена: ";
			cout << boolalpha;
			if (key == '1')
				cout << stack1.FullQueue();
			else
				cout << stack2.FullQueue();
			cout << noboolalpha;
			cout << endl;
			break;
		case '7': // Прочесть количество элементов в очереди
			select_queue(key);
			cout << "Количество элементов в очереди: ";
			if (key == '1')
				cout << stack1.GetLen();
			else
				cout << stack2.GetLen();
			cout << endl;
			break;
		case '8': // Прочесть размер очереди
			select_queue(key);
			cout << "Размер очереди: ";
			if (key == '1')
				cout << stack1.GetSize();
			else
				cout << stack2.GetSize();
			cout << endl;
			break;
		case '9': // Скопировать одну очередь в другую
			cout << "Скопировать очередь" << endl;
			cout << "1) Скопировать 2 в 1 (s1 = s2)" << endl;
			cout << "2) Скопировать 1 в 2 (s2 = s1)" << endl;
			cin >> key;
			if (key == '1')
				stack1 = stack2;
			else
				stack2 = stack1;
			cout << "Очередь скопирована";
			cout << endl;
			break;
		default:
			cout << "Неправильное действие" << endl;
			break;
		}
		cout << endl;
	}
}

void task()
{
	char key = '1';
	Queue<short> shorts1;
	Queue<short> shorts2;
	Queue<Cone> cone1;
	Queue<Cone> cone2;
	while (key != '0')
	{
		cout << "Выберите тип очереди" << endl;
		cout << "1) Short" << endl;
		cout << "2) Cone" << endl;
		cout << "0) Выход" << endl;
		cin >> key;
		cout << endl;
		if (key == '1')
			test_queue(shorts1, shorts2);
		else if (key == '2')
			test_queue(cone1, cone2);
		else
			break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	task();
	return 0;
};