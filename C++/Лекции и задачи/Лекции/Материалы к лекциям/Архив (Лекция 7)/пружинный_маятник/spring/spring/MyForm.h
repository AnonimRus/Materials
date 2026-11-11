#pragma once

//---------------------–еальный мир---------------------
//----------------------------ћасса груза------------
float m ;     // (kg)
				   //------------------∆есткость пружины----------------
float k = 4.0e3;   // (n/m)
				  
				 //---------------текущее отклонение пружины-----------
float x; //(m)
		 //---------------текуща€ скорость---------------------
float v; //(m/sec)
		 //----------------текущее ускорение------------------------
float a; // (m/sec2)
		 //-----------------шаг по времени--------------------------
float dt=0.01;

//-----------------------Ёкранный мир----------------------------------------
//-----------------------начальное отклонение на экране------------------------------
int x0_screen = 200;
//-----------------------масшаб дл€ превращени€ реальных координат в экранные
float scale;
//-----------------------текущие экранные координаты груза------------------
int xpos1, ypos1;  //  предыдущие
int xpos2, ypos2; // новые
				  //-----------------------положение равновеси€------------------------------
int xpos0 = 400, ypos0 = 200;
//---------------ширина груза на экране------------------------------------
int w_screen = 50;


namespace spring {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics^ gr;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			gr = this->CreateGraphics();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  springToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->springToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->springToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(869, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// springToolStripMenuItem
			// 
			this->springToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->startToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->springToolStripMenuItem->Name = L"springToolStripMenuItem";
			this->springToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->springToolStripMenuItem->Text = L"Spring";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::startToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(158, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0,01";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(190, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"x0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(333, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"1,0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(368, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"m";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 372);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	private: System::Void startToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


		x = Convert::ToDouble(textBox1->Text);
		scale = x0_screen / x;
		m = Convert::ToDouble(textBox2->Text);
		v = 0.0;
		xpos1 = xpos0;
		ypos1 = ypos0;
		timer1->Enabled = true;

	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	a = -(k / m)*x;

	v = v + a*dt;

	x = x + v*dt;

	xpos2 = xpos0 + x*scale;
	ypos2 = ypos0;

	gr->FillRectangle(Brushes::WhiteSmoke, xpos1 - w_screen / 2, ypos1 - w_screen/2, w_screen, w_screen);
	gr->FillRectangle(Brushes::Green, xpos2 - w_screen/2, ypos2 - w_screen/2, w_screen, w_screen);

	xpos1 = xpos2;
	ypos1 = ypos2;

}
};
}
