#pragma once

#include <math.h>

namespace collision {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		Graphics^ holst; 

		float x1,y1,vx1,vy1;
		float x2,y2,vx2,vy2;

		int xp1,yp1,xp10,yp10;
		int xp2,yp2,xp20,yp20;
		int xp0,yp0;


		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			holst=this->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(316, 349);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(23, 14);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"-0,2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(158, 14);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"0,01";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(23, 55);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"3,0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(161, 55);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(97, 20);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"0";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(358, 17);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 5;
			this->textBox5->Text = L"0,2";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(514, 14);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 6;
			this->textBox6->Text = L"-0,01";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(358, 55);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 7;
			this->textBox7->Text = L"-3,0";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(514, 55);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 8;
			this->textBox8->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, -2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"X1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(185, -2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Y1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(57, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"VX1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(184, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"VY1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(371, 1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"X2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(551, 1);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Y2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(382, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"VX2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(536, 37);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"VY2";
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 424);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
               
		timer1->Enabled=true;
        x1 = Convert::ToDouble(textBox1->Text);
		y1 = Convert::ToDouble(textBox2->Text);

		vx1 = Convert::ToDouble(textBox3->Text);
		vy1 = Convert::ToDouble(textBox4->Text);

		x2 = Convert::ToDouble(textBox5->Text);
		y2 = Convert::ToDouble(textBox6->Text);

		vx2 = Convert::ToDouble(textBox7->Text);
		vy2 = Convert::ToDouble(textBox8->Text);

        xp0=400;
		yp0=200;
		
		xp1 = xp0;
		yp1 = yp0;

		xp2 = xp0;
		yp2 = yp0;

			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	float pi = 3.1415;
	float e0=8.85e-11;
	float c = 1.0 / (4.0 * pi*e0);
	float m1=0.001;
	float m2=0.001;
	float q1=1e-6;
	float q2=1e-6;
	float dt=1e-4;

	float xx = x1 - x2;
	float yy = y1 - y2;

	float r2 = xx*xx + yy*yy;
	float r = sqrt(r2);

	float f = c*(q1*q2) / r2;

	float fx1 = f*xx / r;
	float fy1 = f*yy / r;

	float fx2 = -fx1;
	float fy2 = -fy1;

	vx1 = vx1 + (fx1 / m1)*dt;
	vy1 = vy1 + (fy1 / m1)*dt;

	vx2 = vx2 + (fx2 / m2)*dt;
	vy2 = vy2 + (fy2 / m2)*dt;

	x1 = x1 + vx1*dt;
	y1 = y1 + vy1*dt;

	x2 = x2 + vx2*dt;
	y2 = y2 + vy2*dt;

	float scale = 100 / 0.2;

	xp1 = xp0 + scale*x1;
	yp1 = yp0 - scale*y1;

//	holst->FillEllipse(Brushes::Blue, xp10 - 5, yp10 - 5, 10, 10);
	holst->FillEllipse(Brushes::Red, xp1 - 5, yp1 - 5, 10, 10);

	xp10 = xp1;
	yp10 = yp1;

	xp2 = xp0 + scale*x2;
	yp2 = yp0 - scale*y2;

//	holst->FillEllipse(Brushes::Blue, xp20 - 5, yp20 - 5, 10, 10);
	holst->FillEllipse(Brushes::Red, xp2 - 5, yp2 - 5, 10, 10);

	xp20 = xp2;
	yp20 = yp2;

		 }
};
}

