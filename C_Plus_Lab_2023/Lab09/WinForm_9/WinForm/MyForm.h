#pragma once
#include "Lab9.h"

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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button2;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Конус";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(273, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Задайте значение для массива конусов";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Размер массива:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(135, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(42, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(11, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 15);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Радиус основания:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(11, 171);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 15);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Высота:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(132, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(56, 20);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(132, 169);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(56, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(10, 198);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Координаты";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(83, 222);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 15);
			this->label7->TabIndex = 9;
			this->label7->Text = L"X:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(83, 248);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 15);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Y:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(84, 274);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 15);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Z:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(132, 217);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(56, 20);
			this->textBox4->TabIndex = 12;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(132, 243);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(56, 20);
			this->textBox5->TabIndex = 13;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(132, 269);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(56, 20);
			this->textBox6->TabIndex = 14;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(7, 356);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(278, 121);
			this->listBox1->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(151, 303);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Задать параметры";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(129, 99);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(74, 30);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Начальное \r\n  значение:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(209, 142);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(56, 20);
			this->textBox7->TabIndex = 18;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(209, 169);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(56, 20);
			this->textBox8->TabIndex = 19;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(209, 217);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(56, 20);
			this->textBox9->TabIndex = 20;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(209, 243);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(56, 20);
			this->textBox10->TabIndex = 21;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(209, 269);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(56, 20);
			this->textBox11->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(220, 114);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(33, 15);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Шаг:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(338, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(76, 17);
			this->label12->TabIndex = 24;
			this->label12->Text = L"ID Конуса:";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(439, 35);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(56, 20);
			this->textBox12->TabIndex = 25;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(338, 58);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(345, 30);
			this->label13->TabIndex = 26;
			this->label13->Text = L"Вычислить так же площадь основания, боковой стороны, \r\nобщую площадь и объем кону"
				L"са.";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(338, 114);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(300, 15);
			this->label14->TabIndex = 27;
			this->label14->Text = L"Умножить параметры конуса на некоторое число:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(644, 113);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(56, 20);
			this->textBox13->TabIndex = 28;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(338, 169);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(255, 15);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Сравнить два конуса(введите ID каждого):";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(599, 168);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(56, 20);
			this->textBox14->TabIndex = 30;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(661, 168);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(56, 20);
			this->textBox15->TabIndex = 31;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(341, 252);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(376, 225);
			this->listBox2->TabIndex = 32;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(341, 214);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 23);
			this->button2->TabIndex = 33;
			this->button2->Text = L"Задать параметры";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(736, 489);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdateData(){
		listBox1->Items->Clear();
		listBox2->Items->Clear();
		for (int i = 0; i < size; i++)
		{
			listBox1->Items->Add(String::Format("Конус[{0}]: радиус = {1:F2}; высота = {2:F2}",
				i, coneArr[i].ConeGetR(), coneArr[i].ConeGetH()));
			listBox1->Items->Add(String::Format("координаты: X = {0:F2}, Y = {1:F2}, Z = {2:F2}",
				coneArr[i].ConeGetX(), coneArr[i].ConeGetY(), coneArr[i].ConeGetZ()));
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			size = Convert::ToInt32(textBox1->Text);
			if (textBox2->Text->Length == 0 && textBox7->Text->Length == 0)
				fill_base();
			else
			{
				Cone start_cone = Cone(
					Convert::ToDouble(textBox2->Text),
					Convert::ToDouble(textBox3->Text),
					Convert::ToDouble(textBox4->Text),
					Convert::ToDouble(textBox5->Text),
					Convert::ToDouble(textBox6->Text)
				);
				double steps[5] = {
					Convert::ToDouble(textBox7->Text),
					Convert::ToDouble(textBox8->Text),
					Convert::ToDouble(textBox9->Text),
					Convert::ToDouble(textBox10->Text),
					Convert::ToDouble(textBox11->Text)
				};
				fill_start_step(
					start_cone,
					steps
				);
			}
			UpdateData();
			button2->Enabled = true;
		}
		catch (...)
		{
			MessageBox::Show("Проверьте правильность введённых значений.",
				"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		listBox2->Items->Clear();
		if (textBox12->Text->Length != 0)
		{
			try
			{
				int n = Convert::ToInt32(textBox12->Text);
				if (n < 0 || n >= size) throw 10;

				listBox2->Items->Add(String::Format("Площадь основания = {0:F2}, боковой стороны = {1:F2},",
					coneArr[n].CalcSO(), coneArr[n].CalcSB()));
				listBox2->Items->Add(String::Format("общая площадь = {0:F2}, объём конуса = {1:F2},",
					coneArr[n].CalcS(), coneArr[n].CalcV()));
				listBox2->Items->Add("");

				if (textBox13->Text->Length != 0)
				{
					double N = Convert::ToDouble(textBox13->Text);
					coneArr[n].MultN(N);
					listBox2->Items->Add(String::Format("Новые параметры: радиус = {0:F2}; высота = {1:F2}",
						coneArr[n].ConeGetR(), coneArr[n].ConeGetH()));

					listBox2->Items->Add("");
				}
			}
			catch (...)
			{
				MessageBox::Show("Проверьте правильность введённых значений.",
					"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
		if (textBox14->Text->Length != 0 && textBox15->Text->Length != 0)
		{
			try
			{
				int d1 = Convert::ToInt32(textBox14->Text);
				int d2 = Convert::ToInt32(textBox15->Text);
				if ((d1 != d2)&&(d1 < 0 || d2 < 0)) throw 10;
				listBox2->Items->Add(String::Format("Один конус больше другого на = {0:F2}:", CravConeBol(coneArr[d1], coneArr[d2])));
				listBox2->Items->Add("");
			}
			catch (...)
			{
				MessageBox::Show("Проверьте правильность введённых значений.",
					"Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}