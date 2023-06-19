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

#include "IArray.h"
#include "Lab11.h"
#include "BigIndicator.h"


namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
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

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	protected:
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"« Индикаторы на два положения »";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(137, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(65, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Размер массива:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(217, 44);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(436, 160);
			this->listBox1->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(382, 210);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(271, 270);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Задать параметры";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Тип индикатора*:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"A", L"B", L"C", L"D" });
			this->comboBox1->Location = System::Drawing::Point(121, 163);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(65, 21);
			this->comboBox1->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 15);
			this->label4->TabIndex = 9;
			this->label4->Text = L"ID индикатора*:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(121, 126);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(65, 20);
			this->textBox2->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 193);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 15);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Размер:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 287);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 15);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Координаты:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(13, 371);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 15);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Состояние:";
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(6, 458);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 23);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Задать параметры";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(29, 216);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(54, 15);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Высота:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(29, 253);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 15);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Ширина:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(89, 216);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(65, 20);
			this->textBox3->TabIndex = 17;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(89, 253);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(65, 20);
			this->textBox4->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(48, 311);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 15);
			this->label10->TabIndex = 19;
			this->label10->Text = L"X:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(48, 336);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(17, 15);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Y:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(89, 311);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(65, 20);
			this->textBox5->TabIndex = 21;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(89, 335);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(65, 20);
			this->textBox6->TabIndex = 22;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(51, 398);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(68, 17);
			this->radioButton1->TabIndex = 23;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"включён";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(51, 421);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(76, 17);
			this->radioButton2->TabIndex = 24;
			this->radioButton2->Text = L"выключен";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 458);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 23);
			this->button3->TabIndex = 25;
			this->button3->Text = L"По умолчанию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(271, 248);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(65, 20);
			this->textBox7->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(256, 216);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(94, 15);
			this->label12->TabIndex = 26;
			this->label12->Text = L"ID индикатора:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(241, 274);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 23);
			this->button4->TabIndex = 28;
			this->button4->Text = L"Нарисовать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(297, 311);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(65, 40);
			this->button5->TabIndex = 29;
			this->button5->Text = L"Очистить\r\n    экран";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(665, 493);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void UpdateListBox()
	{
		listBox1->Items->Clear();

		char* type;
		for (int i = 0; i < bigIndicator.GetSize(); i++)
		{
			switch (bigIndicator.GetType(i))
			{
			case 0:
				type = "A";
				break;
			case 1:
				type = "B";
				break;
			case 2:
				type = "C";
				break;
			case 3:
				type = "D";
				break;
			}
			listBox1->Items->Add(
				String::Format(
					"Индикатор[{0}]: Тип: {1}; Ширина: {2}; Высота: {3}; X: {4};  Y: {5};  Состояние: {6}",
					i, gcnew String(type), 
					gcnew String(bigIndicator[i]->GetW().ToString()),
					gcnew String(bigIndicator[i]->GetH().ToString()),
					gcnew String(bigIndicator[i]->GetX().ToString()),
					gcnew String(bigIndicator[i]->GetY().ToString()), 
					gcnew String(bigIndicator[i]->GetCon().ToString())
				)
			);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Length == 0)
			return;
		int size = Convert::ToInt32(textBox1->Text);
		bigIndicator.SetSize(size);
		UpdateListBox();
		button2->Enabled = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try 
		{
			// Изменение типа
			if (textBox2->Text->Length == 0) throw 9;
			UINT i = Convert::ToInt32(textBox2->Text);
			UINT type = Convert::ToInt32(comboBox1->SelectedIndex);
			bigIndicator.SetType(i, type);
			// Изменение размера
			if (textBox3->Text->Length != 0)
				bigIndicator[i]->SetH(Convert::ToInt32(textBox3->Text));
			if (textBox4->Text->Length != 0)
				bigIndicator[i]->SetW(Convert::ToInt32(textBox4->Text));
			// Изменение координат
			if (textBox5->Text->Length != 0)
				bigIndicator[i]->SetX(Convert::ToInt32(textBox5->Text));
			if (textBox6->Text->Length != 0)
				bigIndicator[i]->SetY(Convert::ToInt32(textBox6->Text));
			// Изменение состояния
			if (radioButton1->Checked)
				bigIndicator[i]->SetCon(1);
			else if (radioButton2->Checked)
				bigIndicator[i]->SetCon(0);
			UpdateListBox();
			listBox1->SelectedIndex = i;
		}
		catch (...) 
		{
			MessageBox::Show("Неправильно заданы данные !",
				"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (bigIndicator.GetSize() == 0) throw 10;
			textBox2->Text = (bigIndicator.GetSize() - 1).ToString();
			textBox3->Text = "20";
			textBox4->Text = "20";
			textBox5->Text = "0";
			textBox6->Text = "0";
			textBox7->Text = (bigIndicator.GetSize() - 1).ToString();
			radioButton1->Checked = true;
		}
		catch(...) {
			MessageBox::Show("Размер массива равен нулю !",
				"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void DrawB(UINT i)
	{
		try
		{
			Color^ col = gcnew Color;
			Pen^ pen = gcnew Pen(col->DarkBlue);
			pen->Width = 2;
			SolidBrush^ brWhite = gcnew SolidBrush(col->White);
			SolidBrush^ brRed = gcnew SolidBrush(col->Red);
			Graphics^ gr = pictureBox1->CreateGraphics();
			//if (bigIndicator[i]->GetCon() == 1)
			bigIndicator[i]->Draw(gr, pen, brRed, brWhite);
			//else if (bigIndicator[i]->GetCon() == 0)
			//	bigIndicator[i]->Draw(gr, pen, brWhite, brWhite);
			//else throw 25;
		}
		catch (...)
		{
			MessageBox::Show("Неправильное значение состояния!",
				"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox7->Text->Length != 0)
		{
			try
			{
				int bigID = Convert::ToInt16(textBox7->Text);
				if (bigID < 0 || bigID >= bigIndicator.GetSize()) throw 10;

				DrawB(bigID);
			}
			catch (...)
			{
				MessageBox::Show("Неправильно заданы данные !",
					"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Color^ col = gcnew Color;
		Graphics^ gr = pictureBox1->CreateGraphics();
		gr->Clear(col->White);
	}
};
}