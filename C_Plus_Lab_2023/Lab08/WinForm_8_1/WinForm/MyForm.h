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

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Text;

	// Класс Точки
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
		return sqrt((PointGetX(b) - PointGetX(a))*(PointGetX(b) - PointGetX(a)) + (PointGetY(b) - PointGetY(a))* (PointGetY(b) - PointGetY(a)));
	}

	// Количество структур в файле
	int CountStructs(FILE* fp)
	{
		int len;
		fseek(fp, 0L, SEEK_END); // Переходим в конец файла
		len = ftell(fp); // Читаем позицию - это и будет длина файла
		fseek(fp, 0L, SEEK_SET); // Переходим снова в начало файла
		return len / sizeof(MyPoint); // Кол-во структур
	}

	// Чтение файла и занесение данных в структуры
	int StructText(MyPoint* Arr, int CountPar, TextBox^ textbox) {
		using namespace std;

		String^ name = Convert::ToString(textbox->Text);
		std::string unmanaged = msclr::interop::marshal_as<std::string>(name);
		ifstream in(unmanaged.c_str());

		//Если открытие файла прошло успешно
		if (in.is_open())
		{
			//Вначале посчитаем сколько чисел в файле
			int count = 0;// число чисел в файле
			int temp;//Временная переменная

			while (!in.eof())// пробегаем пока не встретим конец файла eof
			{
				in >> temp;//в пустоту считываем из файла числа
				count++;// увеличиваем счетчик числа чисел
			}

			//Число чисел посчитано, теперь нам нужно понять сколько
			//чисел в одной строке
			//Для этого посчитаем число пробелов до знака перевода на новую строку

			//Вначале переведем каретку в потоке в начало файла
			in.seekg(0, ios::beg);
			in.clear();

			//Число пробелов в первой строчке вначале равно 0
			int count_space = 0;
			char symbol;
			while (!in.eof())//на всякий случай цикл ограничиваем концом файла
			{
				//теперь нам нужно считывать не числа, а посимвольно считывать данные
				in.get(symbol);//считали текущий символ
				if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
				if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
			}
			//cout << count_space << endl;

			//Опять переходим в потоке в начало файла
			in.seekg(0, ios::beg);
			in.clear();

			//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
			//Теперь можем считать матрицу.

			int n = count / (count_space + 1);//число строк
			int m = count_space + 1;//число столбцов на единицу больше числа пробелов
			double** x;
			x = new double* [n];
			for (int i = 0; i < n; i++) x[i] = new double[m];

			//Считаем матрицу из файла
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					in >> x[i][j];

			//Заполнение массива
			for (int i = 0; i < n; i++)
			{

				Arr[CountPar] = SetPoint(x[i][0], x[i][1]);
				CountPar++;
			}


			for (int i = 0; i < n; i++) delete[] x[i];
			delete[] x;

			in.close();//под конец закроем файла
		}
		return CountPar;
	}

	void operator<<(ListBox^ listBox, MyPoint p)
	{
		String^ str =
			L"|   " + Convert::ToString(PointGetX(p)) + "   |" +
			L"   " + Convert::ToString(PointGetY(p)) + "    |    " +
			Convert::ToString(Distance(p).ToString("0.###")) + "      |"
			/*L" (" + Convert::ToString(p.rt.x) + "," + Convert::ToString(p.rt.y) + ") |" +
			L" (" + Convert::ToString(p.lb.x) + "," + Convert::ToString(p.lb.y) + ") |" +
			L" (" + Convert::ToString(p.rb.x) + "," + Convert::ToString(p.rb.y) + ") " +
			L" | " + Convert::ToString(S(p)) + "   " +
			L"| " + Convert::ToString(Per(p)) + "  |"*/;
		listBox->Items->Add(str);

	}
	void vievArr(MyPoint* Arr, int CountPar, ListBox^ listBox) {

		listBox->Items->Clear();

		String^ str = L"|   X   |   Y   |   Distance  |";
		listBox->Items->Add(str);

		for (int i = 0; i < CountPar; i++)
		{
			listBox << Arr[i];
		}
	}

	int delete_i(MyPoint* Arr, int CountPar, int pos) {
		for (int i = pos; i < CountPar - 1; ++i) {
			Arr[i] = Arr[i + 1];
		}
		return CountPar - 1;
	}




	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			Arr = new MyPoint[100];
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		MyPoint* Arr;
		int CountPar = 0;

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button7;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button11;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"«Точка на плоскости»";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 22);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Файл (по умолчанию)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(265, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(117, 22);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Загрузить из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(363, 80);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(222, 303);
			this->listBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"X = ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Y = ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(44, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(44, 128);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(68, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(203, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Создать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(152, 172);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(245, 172);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Изменить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(190, 125);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(106, 23);
			this->button6->TabIndex = 12;
			this->button6->Text = L"По умолчанию";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(76, 174);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(62, 20);
			this->textBox4->TabIndex = 13;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 26);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Элемент\r\nмассива =";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(152, 223);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(187, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"Растояние между двумя точками";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Элементы массива:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(6, 226);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(63, 20);
			this->textBox5->TabIndex = 18;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(75, 226);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(63, 20);
			this->textBox6->TabIndex = 19;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(6, 264);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(333, 39);
			this->button8->TabIndex = 20;
			this->button8->Text = L"Самую ближнюю и дальнюю от начала координат \r\nточки поменять местами";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(6, 309);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(333, 23);
			this->button9->TabIndex = 21;
			this->button9->Text = L"Две точки, между которыми наибольшее растояние";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(104, 351);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(235, 36);
			this->button10->TabIndex = 22;
			this->button10->Text = L"Переместить в начало массива точки,\r\nлежащие в указанном радиусе";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(34, 357);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(64, 20);
			this->textBox7->TabIndex = 23;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 360);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"R =";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(510, 36);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 25;
			this->button11->Text = L"Сохранить";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(613, 402);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "input.txt";
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		CountPar = StructText(Arr, CountPar, textBox1);
		vievArr(Arr, CountPar, listBox1);
	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MyPoint P = SetPoint(Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox3->Text));
		Arr[CountPar] = P;

		CountPar++;
		vievArr(Arr, CountPar, listBox1);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = Convert::ToInt32(textBox4->Text);
		CountPar = delete_i(Arr, CountPar, i - 1);
		vievArr(Arr, CountPar, listBox1);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = Convert::ToInt32(textBox4->Text);
		MyPoint P = SetPoint(Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox3->Text));
		Arr[i - 1] = P;
		vievArr(Arr, CountPar, listBox1);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = "1";
		textBox3->Text = "3";
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		int a = Convert::ToInt32(textBox5->Text) - 1;
		int b = Convert::ToInt32(textBox6->Text) - 1;
		double D = Distanse_two(Arr[a], Arr[b]);
		String^ str = L"(" + Convert::ToString(PointGetX(Arr[b])) + "," + Convert::ToString(PointGetY(Arr[b])) + ") ->"
			+ L"(" + Convert::ToString(PointGetX(Arr[a])) + "," + Convert::ToString(PointGetY(Arr[a])) + ")  =  "
			+ Convert::ToString(D.ToString("0.###"));
		listBox1->Items->Add(str);
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		double max = Distance(Arr[0]), min = Distance(Arr[0]);
		int maxi = 0, mini = 0;
		int n = CountPar - 1;
		for (int i = 0; i <= n; ++i) {
			if (Distance(Arr[i]) > max) {
				max = Distance(Arr[i]);
				maxi = i;
			}
			if (Distance(Arr[i]) < min) {
				min = Distance(Arr[i]);
				mini = i;
			}
		}
		MyPoint P = Arr[mini];
		Arr[mini] = Arr[maxi];
		Arr[maxi] = P;

		vievArr(Arr, CountPar, listBox1);
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		double max = Distanse_two(Arr[0], Arr[1]);
		int m1 = 0, m2 = 1;

		for (int i = 0; i <= CountPar-1; ++i) {
			for (int j = 0; j <= CountPar-1; ++j) {
				if (Distanse_two(Arr[i], Arr[j]) > max) {
					max = Distanse_two(Arr[i], Arr[j]);
					m1 = i; m2 = j;
				}
			}
		}
		String^ str = L"(" + Convert::ToString(PointGetX(Arr[m1])) + "," + Convert::ToString(PointGetY(Arr[m1])) + ") ->"
			+ L"(" + Convert::ToString(PointGetX(Arr[m2])) + "," + Convert::ToString(PointGetY(Arr[m2])) + ")  =  "
			+ Convert::ToString(max.ToString("0.###"));
		listBox1->Items->Add(str);
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		int r = Convert::ToInt32(textBox7->Text);
		MyPoint P;
		int n = 0;
		for (int i = 0; i <= CountPar - 1; ++i) {
			if (Distance(Arr[i]) < r) {
				P = Arr[n];
				Arr[n] = Arr[i];
				Arr[i] = P;
				if (n < i) {
					n++;
					i--;
				}
			}
		}

		vievArr(Arr, CountPar, listBox1);
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		FILE* fout;

		String^ name = Convert::ToString(textBox1->Text);

		std::string unmanaged = msclr::interop::marshal_as<std::string>(name);

		fout = fopen(unmanaged.c_str(), "w");
		String^ str;

		for (int i = 0; i < CountPar -1; i++)
		{
			str =
				L"" + Convert::ToString(PointGetX(Arr[i])) + " " + Convert::ToString(PointGetY(Arr[i])) + "\n";

			unmanaged = msclr::interop::marshal_as<std::string>(str);
			fputs(unmanaged.c_str(), fout);
		}
		str =
			L"" + Convert::ToString(PointGetX(Arr[CountPar - 1])) + " " + Convert::ToString(PointGetY(Arr[CountPar - 1]));

		unmanaged = msclr::interop::marshal_as<std::string>(str);
		fputs(unmanaged.c_str(), fout);



		fclose(fout);
	}
};
}