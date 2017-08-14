#pragma once

#include < stdio.h >  
#include < stdlib.h >  
#include"vcclr.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	//using namespace cv;
	
	enum BitmapImageProcessing
	{
		RGB2Gray,

		ToRed,
		ToGreen,
		ToBlue,
		horizontal, 
		vertical,
		diagonal,
		THRESH_BINARY,
		THRESH_BINARY_Inv,
		Duplication,
		other
	};

	
	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  openFileToolStripMenuItem;

	private:Bitmap^ Img_Source;





	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;


	private: System::Windows::Forms::ToolStripButton^  toolStripBtn_Gray;
	private: System::Windows::Forms::ToolStrip^  toolStrip2;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToRed;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToGreen;
	private: System::Windows::Forms::ToolStripButton^  Btn_ToBlue;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ToolStrip^  toolStrip3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton_horizontalFilp;
	private: System::Windows::Forms::ToolStripButton^  Btn_verticalFlip;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton_diagonal;
	private: System::Windows::Forms::ToolStrip^  toolStrip4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton_Threshold;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton_Threshold_Inv;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ToolStrip^  toolStrip5;
	private: System::Windows::Forms::ToolStripButton^  Btn_Zoom;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripTextBox^  TextBox_ZoomRate;
	private: System::Windows::Forms::ToolStripButton^  tBtn_otherZoom;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::ToolStrip^  toolStrip6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  Pos_X;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  Pos_Y;
	private: System::Windows::Forms::Label^  Pos_RGBvalue;














		
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	   ref struct PCXData//http://www.fysnet.net/pcxfile.htm  PCX解封包資料
		{
		String ^filePath;//檔案路徑
		String ^fileName;//檔案名稱
		String^ Manufacturer;//Zsoft ID
		int version;//版本
		int Encoding;//PCX run-length encoding
		int Hdpi;//
		int Vdpi;//
		int reserved;//
		String^ NPlanes;//
		String^ color;//灰階 彩色
		int HscreenSize;//Video screen size (Horizontal)
		int VscreenSize;// Video screen size (Vertical)
		Bitmap^ Image;//
		int BytePerLine;//
		int BitsPerPixel;//
		Bitmap^ ColorMap;//
		}; 
	   
	   
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip4 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_Threshold = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_Threshold_Inv = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->Btn_ToRed = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_ToGreen = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_ToBlue = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripBtn_Gray = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip3 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton_horizontalFilp = (gcnew System::Windows::Forms::ToolStripButton());
			this->Btn_verticalFlip = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton_diagonal = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip5 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->TextBox_ZoomRate = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->Btn_Zoom = (gcnew System::Windows::Forms::ToolStripButton());
			this->tBtn_otherZoom = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip6 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Pos_X = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Pos_Y = (gcnew System::Windows::Forms::Label());
			this->Pos_RGBvalue = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->toolStrip4->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->toolStrip3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->toolStrip5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->toolStrip6->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1561, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openFileToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(45, 23);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFileToolStripMenuItem.Image")));
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(146, 26);
			this->openFileToolStripMenuItem->Text = L"OpenFile";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(48, 261);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 274);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(493, 261);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(323, 274);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->toolStrip4);
			this->groupBox1->Controls->Add(this->toolStrip2);
			this->groupBox1->Controls->Add(this->toolStrip1);
			this->groupBox1->Location = System::Drawing::Point(12, 39);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(127, 178);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"色彩轉換";
			// 
			// toolStrip4
			// 
			this->toolStrip4->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip4->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton_Threshold,
					this->toolStripButton_Threshold_Inv
			});
			this->toolStrip4->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip4->Location = System::Drawing::Point(3, 73);
			this->toolStrip4->Name = L"toolStrip4";
			this->toolStrip4->Size = System::Drawing::Size(121, 65);
			this->toolStrip4->TabIndex = 2;
			this->toolStrip4->Text = L"toolStrip4";
			// 
			// toolStripButton_Threshold
			// 
			this->toolStripButton_Threshold->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Threshold.Image")));
			this->toolStripButton_Threshold->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Threshold->Name = L"toolStripButton_Threshold";
			this->toolStripButton_Threshold->Size = System::Drawing::Size(119, 24);
			this->toolStripButton_Threshold->Text = L"二值化";
			this->toolStripButton_Threshold->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_Threshold_Click);
			// 
			// toolStripButton_Threshold_Inv
			// 
			this->toolStripButton_Threshold_Inv->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_Threshold_Inv.Image")));
			this->toolStripButton_Threshold_Inv->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_Threshold_Inv->Name = L"toolStripButton_Threshold_Inv";
			this->toolStripButton_Threshold_Inv->Size = System::Drawing::Size(119, 24);
			this->toolStripButton_Threshold_Inv->Text = L"二值化負片";
			this->toolStripButton_Threshold_Inv->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_Threshold_Inv_Click);
			// 
			// toolStrip2
			// 
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->Btn_ToRed, this->Btn_ToGreen,
					this->Btn_ToBlue
			});
			this->toolStrip2->Location = System::Drawing::Point(3, 47);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(121, 26);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// Btn_ToRed
			// 
			this->Btn_ToRed->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToRed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToRed.Image")));
			this->Btn_ToRed->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToRed->Name = L"Btn_ToRed";
			this->Btn_ToRed->Size = System::Drawing::Size(23, 23);
			this->Btn_ToRed->Text = L"R";
			this->Btn_ToRed->Click += gcnew System::EventHandler(this, &MyForm::Btn_ToRed_Click);
			// 
			// Btn_ToGreen
			// 
			this->Btn_ToGreen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToGreen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToGreen.Image")));
			this->Btn_ToGreen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToGreen->Name = L"Btn_ToGreen";
			this->Btn_ToGreen->Size = System::Drawing::Size(24, 23);
			this->Btn_ToGreen->Text = L"G";
			this->Btn_ToGreen->Click += gcnew System::EventHandler(this, &MyForm::Btn_ToGreen_Click);
			// 
			// Btn_ToBlue
			// 
			this->Btn_ToBlue->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Btn_ToBlue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_ToBlue.Image")));
			this->Btn_ToBlue->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_ToBlue->Name = L"Btn_ToBlue";
			this->Btn_ToBlue->Size = System::Drawing::Size(23, 23);
			this->Btn_ToBlue->Text = L"B";
			this->Btn_ToBlue->Click += gcnew System::EventHandler(this, &MyForm::Btn_ToBlue_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripBtn_Gray });
			this->toolStrip1->Location = System::Drawing::Point(3, 20);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(121, 27);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripBtn_Gray
			// 
			this->toolStripBtn_Gray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripBtn_Gray.Image")));
			this->toolStripBtn_Gray->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripBtn_Gray->Name = L"toolStripBtn_Gray";
			this->toolStripBtn_Gray->Size = System::Drawing::Size(63, 24);
			this->toolStripBtn_Gray->Text = L"灰階";
			this->toolStripBtn_Gray->Click += gcnew System::EventHandler(this, &MyForm::toolStripBtn_Gray_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->toolStrip3);
			this->groupBox2->Location = System::Drawing::Point(145, 39);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(125, 145);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"鏡射";
			// 
			// toolStrip3
			// 
			this->toolStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripButton_horizontalFilp,
					this->Btn_verticalFlip, this->toolStripButton_diagonal
			});
			this->toolStrip3->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip3->Location = System::Drawing::Point(3, 20);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->Size = System::Drawing::Size(119, 92);
			this->toolStrip3->TabIndex = 0;
			this->toolStrip3->Text = L"toolStrip3";
			// 
			// toolStripButton_horizontalFilp
			// 
			this->toolStripButton_horizontalFilp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_horizontalFilp.Image")));
			this->toolStripButton_horizontalFilp->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_horizontalFilp->Name = L"toolStripButton_horizontalFilp";
			this->toolStripButton_horizontalFilp->Size = System::Drawing::Size(117, 24);
			this->toolStripButton_horizontalFilp->Text = L"水平鏡射";
			this->toolStripButton_horizontalFilp->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_horizontalFilp_Click);
			// 
			// Btn_verticalFlip
			// 
			this->Btn_verticalFlip->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_verticalFlip.Image")));
			this->Btn_verticalFlip->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_verticalFlip->Name = L"Btn_verticalFlip";
			this->Btn_verticalFlip->Size = System::Drawing::Size(117, 24);
			this->Btn_verticalFlip->Text = L"垂直鏡射";
			this->Btn_verticalFlip->Click += gcnew System::EventHandler(this, &MyForm::Btn_verticalFlip_Click);
			// 
			// toolStripButton_diagonal
			// 
			this->toolStripButton_diagonal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton_diagonal.Image")));
			this->toolStripButton_diagonal->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton_diagonal->Name = L"toolStripButton_diagonal";
			this->toolStripButton_diagonal->Size = System::Drawing::Size(117, 24);
			this->toolStripButton_diagonal->Text = L"對角線鏡射";
			this->toolStripButton_diagonal->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton_diagonal_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->toolStrip5);
			this->groupBox3->Location = System::Drawing::Point(277, 39);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(137, 178);
			this->groupBox3->TabIndex = 9;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"縮放";
			// 
			// toolStrip5
			// 
			this->toolStrip5->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip5->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripLabel1,
					this->TextBox_ZoomRate, this->Btn_Zoom, this->tBtn_otherZoom
			});
			this->toolStrip5->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip5->Location = System::Drawing::Point(4, 22);
			this->toolStrip5->Name = L"toolStrip5";
			this->toolStrip5->Size = System::Drawing::Size(129, 95);
			this->toolStrip5->TabIndex = 0;
			this->toolStrip5->Text = L"toolStrip5";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(127, 0);
			// 
			// TextBox_ZoomRate
			// 
			this->TextBox_ZoomRate->AutoSize = false;
			this->TextBox_ZoomRate->BackColor = System::Drawing::SystemColors::Window;
			this->TextBox_ZoomRate->Name = L"TextBox_ZoomRate";
			this->TextBox_ZoomRate->Size = System::Drawing::Size(123, 27);
			this->TextBox_ZoomRate->Text = L"1";
			this->TextBox_ZoomRate->TextBoxTextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->TextBox_ZoomRate->ToolTipText = L"縮放倍率";
			// 
			// Btn_Zoom
			// 
			this->Btn_Zoom->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Btn_Zoom.Image")));
			this->Btn_Zoom->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Btn_Zoom->Name = L"Btn_Zoom";
			this->Btn_Zoom->Size = System::Drawing::Size(127, 24);
			this->Btn_Zoom->Text = L"複製縮放";
			this->Btn_Zoom->ToolTipText = L"縮放";
			this->Btn_Zoom->Click += gcnew System::EventHandler(this, &MyForm::Btn_ZoomIn_Click);
			// 
			// tBtn_otherZoom
			// 
			this->tBtn_otherZoom->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tBtn_otherZoom.Image")));
			this->tBtn_otherZoom->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tBtn_otherZoom->Name = L"tBtn_otherZoom";
			this->tBtn_otherZoom->Size = System::Drawing::Size(127, 24);
			this->tBtn_otherZoom->Text = L"其他縮放";
			this->tBtn_otherZoom->Click += gcnew System::EventHandler(this, &MyForm::tBtn_otherZoom_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->toolStrip6);
			this->groupBox4->Location = System::Drawing::Point(447, 48);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4);
			this->groupBox4->Size = System::Drawing::Size(164, 168);
			this->groupBox4->TabIndex = 10;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"繪圖工具";
			// 
			// toolStrip6
			// 
			this->toolStrip6->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip6->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			this->toolStrip6->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::VerticalStackWithOverflow;
			this->toolStrip6->Location = System::Drawing::Point(4, 22);
			this->toolStrip6->Name = L"toolStrip6";
			this->toolStrip6->Size = System::Drawing::Size(156, 38);
			this->toolStrip6->TabIndex = 0;
			this->toolStrip6->Text = L"toolStrip6";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(154, 24);
			this->toolStripButton1->Text = L"矩形";
			this->toolStripButton1->ToolTipText = L"矩形";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(96, 595);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 15);
			this->label1->TabIndex = 11;
			this->label1->Text = L"X:";
			// 
			// Pos_X
			// 
			this->Pos_X->AutoSize = true;
			this->Pos_X->Location = System::Drawing::Point(123, 595);
			this->Pos_X->Name = L"Pos_X";
			this->Pos_X->Size = System::Drawing::Size(41, 15);
			this->Pos_X->TabIndex = 11;
			this->Pos_X->Text = L"label1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(201, 595);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 15);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Y:";
			// 
			// Pos_Y
			// 
			this->Pos_Y->AutoSize = true;
			this->Pos_Y->Location = System::Drawing::Point(259, 595);
			this->Pos_Y->Name = L"Pos_Y";
			this->Pos_Y->Size = System::Drawing::Size(41, 15);
			this->Pos_Y->TabIndex = 11;
			this->Pos_Y->Text = L"label1";
			// 
			// Pos_RGBvalue
			// 
			this->Pos_RGBvalue->AutoSize = true;
			this->Pos_RGBvalue->Location = System::Drawing::Point(387, 595);
			this->Pos_RGBvalue->Name = L"Pos_RGBvalue";
			this->Pos_RGBvalue->Size = System::Drawing::Size(41, 15);
			this->Pos_RGBvalue->TabIndex = 12;
			this->Pos_RGBvalue->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1561, 662);
			this->Controls->Add(this->Pos_RGBvalue);
			this->Controls->Add(this->Pos_Y);
			this->Controls->Add(this->Pos_X);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip4->ResumeLayout(false);
			this->toolStrip4->PerformLayout();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->toolStrip3->ResumeLayout(false);
			this->toolStrip3->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->toolStrip5->ResumeLayout(false);
			this->toolStrip5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->toolStrip6->ResumeLayout(false);
			this->toolStrip6->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public:void LoadPCXFile(String^ filename,PCXData % PCXdata)
{
	PCXdata.filePath = filename;
	String^name = System::IO::Path::GetFileName(filename);//得到檔案名稱
	PCXdata.fileName = name;
	FileStream^ fs = gcnew FileStream(filename, FileMode::Open);//資料流
	BinaryReader^ br = gcnew BinaryReader(fs);//二進位編碼
	while (br->BaseStream->Position < 128)
	{
		switch (br->BaseStream->Position)
		{
		case 0:
			PCXdata.Manufacturer= br->ReadByte().ToString();
			break;
		case 1:
			PCXdata.version= br->ReadByte();
			break;
		case 2:
			PCXdata.Encoding = br->ReadByte();
			break;
		case 3:
			PCXdata.BitsPerPixel = br->ReadByte();
			break;
		case 4:{
			int Xmin = br->ReadByte();
			Xmin = Xmin + 256 * br->ReadByte();
			int Ymin = br->ReadByte();
			Ymin = Ymin + 256 * br->ReadByte();
			int Xmax = br->ReadByte();
			Xmax = Xmax + 256 * br->ReadByte();
			int Ymax = br->ReadByte();
			Ymax = Ymax + 256 * br->ReadByte();
			PCXdata.Image = gcnew Bitmap(Xmax-Xmin+1, Ymax - Ymin + 1);
			break;
		}
		case 12:
			PCXdata.Hdpi = br->ReadByte();
			break;
		case 14:
			PCXdata.Vdpi = br->ReadByte();
			break;
		case 64:
			PCXdata.reserved = br->ReadByte();
				break;
		case 65:
			PCXdata.NPlanes = br->ReadByte().ToString();
			break;
		case 66:
			PCXdata.BytePerLine = br->ReadByte();
			PCXdata.BytePerLine = 256 * (br->ReadByte()) + PCXdata.BytePerLine;
			break;
		case 68:
		{	
			if (br->ReadByte() ==1)
			{
				PCXdata.color = "Color or BW";
			}
			else
			{
					PCXdata.color = "Grayscale";
			}
			break;
		}
		case 70:
			PCXdata.HscreenSize = br->ReadByte();
			break;
		case 72:
			PCXdata.VscreenSize = br->ReadByte();
			break;
		default:
			br->ReadByte();
			break;
		}
	}
	/***********************************/
	PCXdata.ColorMap = gcnew Bitmap(128, 128);
	br->BaseStream->Position = (fs->Length) - 769;//
	
	int check = br->ReadByte();
	Graphics^ graphics = Graphics::FromImage(PCXdata.ColorMap);
	Color palette;
	short color[256][3] = { { 0, 0, 0 } };
	if (check != 12) {
		br->BaseStream->Position = 16;
		int red, green, blue;
		for (int i=0,c = 0; i < 4; i++)
			for (int  j = 0; j < 4;j++,c++) {
				red = br->ReadByte();
				green = br->ReadByte();
				blue = br->ReadByte();
				palette = Color::FromArgb(red, green, blue);
				SolidBrush^ brush = gcnew SolidBrush(palette);
				System::Drawing::Rectangle rect((i * 32), (j * 32), 32, 32);
				graphics->FillRectangle(brush, rect);
				color[c][0] = red;
				color[c][1] = green;
				color[c][2] = blue;
			}
	}
	else if (check == 12)
	{
		int red, green, blue;
		for (int i = 0,c=0; i < 16; i++) 
			for (int j = 0; j < 16; j++, c++) {
				red = br->ReadByte();
				green = br->ReadByte();
				blue = br->ReadByte();
				palette = Color::FromArgb(red, green, blue);
				SolidBrush^ brush = gcnew SolidBrush(palette);
				System::Drawing::Rectangle rect((i * 8), (j * 8), 8, 8);
				graphics->FillRectangle(brush, rect);
				color[c][0] = red;
				color[c][1] = green;
				color[c][2] = blue;
			}
	}
	br->BaseStream->Position = 127;
	int count = br->ReadByte();

	if (PCXdata.Encoding == 0) 
	{
		int y = 0;
		int x = 0;
		while (y < PCXdata.Image->Height)
		{
			int pposition = br->BaseStream->Position;
			int ck_c = br->ReadByte();
			bool over = false;
			Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
			PCXdata.Image->SetPixel(x, y, newColor);
			x++;
			if (x >= PCXdata.Image->Width)
			{
				y++;
				x = 0;
			}
		}
	}
	/********************以下處理彩色**********************/
	else if (count == 0) {
		int y = 0;
		int x = 0;
		while (y < PCXdata.Image->Height)
		{
			int pposition = br->BaseStream->Position;
			int ck_c = br->ReadByte();
			bool over = false;
			if (ck_c >= 192)
			{
				int length = ck_c - 192;
				int colorcode = br->ReadByte();
				Color newColor = Color::FromArgb(color[colorcode][0], color[colorcode][1], color[colorcode][2]);
				for (length; length > 0; length--) {
					PCXdata.Image->SetPixel(x, y, newColor);
					x++;
					if (x >= PCXdata.Image->Width)
					{
						y++;
						x = 0;
					}
					if (y >= PCXdata.Image->Height)
					{
						break;
					}
				}
			}
			else {
				Color newColor = Color::FromArgb(color[ck_c][0], color[ck_c][1], color[ck_c][2]);
				PCXdata.Image->SetPixel(x, y, newColor);
				x++;
				if (x >= PCXdata.Image->Width)
				{
					y++;
					x = 0;
				}
			}
		}
	}
	fs->Close();
}
public: void ConvertColor(Bitmap^ src, Bitmap ^%dst,int code)
	{
		if (src != nullptr)
		{
		dst = gcnew Bitmap(src->Width, src->Height);
				switch (code)
				{
				case RGB2Gray:
					for (int i = 0; i < src->Width; i++)
						for (int j = 0; j < src->Height; j++)
						{					
								int Gray_vaule = src->GetPixel(i, j).R*0.299 + src->GetPixel(i, j).G* 0.587 + src->GetPixel(i, j).B*0.114+0.5;//Gray = R*0.299 + G*0.587 + B*0.114
								dst->SetPixel(i, j, Color::FromArgb(Gray_vaule, Gray_vaule, Gray_vaule));	
						}
					break;
				
				case ToRed:
					for (int i = 0; i < src->Width; i++)
						for (int j = 0; j < src->Height; j++)
						{
							dst->SetPixel(i, j, Color::FromArgb(src->GetPixel(i, j).R, 0, 0));
						}
					break;
				case ToGreen:
					for (int i = 0; i < src->Width; i++)
						for (int j = 0; j < src->Height; j++)
						{
							dst->SetPixel(i, j, Color::FromArgb(0, src->GetPixel(i, j).G, 0));
						}
					break;
				case ToBlue:
					for (int i = 0; i < src->Width; i++)
						for (int j = 0; j < src->Height; j++)
						{
							dst->SetPixel(i, j, Color::FromArgb(0, 0, src->GetPixel(i, j).B));
						}
					break;
				default:
					break;
				}
		}
		
		else
			MessageBox::Show("No Image yet");
	}
public: void Flip(Bitmap^ src, Bitmap ^%dst, int code)
		{
			if (src != nullptr)
			{
				Bitmap^ temp = src;
				dst = gcnew Bitmap(src->Width, src->Height);
				switch (code)
				{
				case horizontal:
					for (int i = 0; i < temp->Width; i++)
						for (int j = 0; j < temp->Height; j++)
						{
							Color color = temp->GetPixel(i, j); //建立Color結構
							dst->SetPixel(temp->Width - i - 1, j, color);
						}
					break;
				case vertical:
					for (int i = 0; i < temp->Width; i++)
						for (int j = 0; j < temp->Height; j++)
						{
							Color color = temp->GetPixel(i, j); //建立Color結構
							dst->SetPixel(i, temp->Height - j - 1, color);
						}
					break;
				case diagonal:
					for (size_t i = 0; i < temp->Width; i++)
						for (size_t j = 0; j < temp->Height; j++)
						{
							Color color = temp->GetPixel(i, j); //建立Color結構
							dst->SetPixel(temp->Width - i - 1, temp->Height - j - 1, color);
						}
					break;
				default:
					break;
				}
			}
			else MessageBox::Show("No Image yet");
		}
public:void Threshold(Bitmap^ src, Bitmap ^%dst,int threshold ,int code)
{
	for (size_t i = 0; i < src->Width; i++)
		for (int j = 0; j < src->Height; j++)
		{
			if (src->GetPixel(i, j).R != src->GetPixel(i, j).G || src->GetPixel(i, j).R != src->GetPixel(i, j).B)
			{
				MessageBox::Show("Convert to Gray First");
				break;
			}
		}
	for (size_t i = 0; i < src->Width; i++)
		for (int j = 0; j < src->Height; j++)
		{
			if (src->GetPixel(i, j).R >= threshold)
			{
				if (code == THRESH_BINARY)
					src->SetPixel(i, j, Color::FromArgb(255,255,255));
				if(code== THRESH_BINARY_Inv)
					src->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			}
			else if(src->GetPixel(i, j).R<threshold)
			{
				if (code == THRESH_BINARY)
					src->SetPixel(i, j, Color::FromArgb(0, 0, 0));
				if (code == THRESH_BINARY_Inv)
					src->SetPixel(i, j, Color::FromArgb(255, 255, 255));
			}
		}
}


private: System::Void openFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ opnFileDlg = gcnew OpenFileDialog;
	opnFileDlg->Multiselect = true;
	
	if (opnFileDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if (opnFileDlg->FileName->IndexOf("jpeg") > 0 | opnFileDlg->FileName->IndexOf("jpg") > 0)
		{
			Img_Source = gcnew Bitmap(opnFileDlg->FileName);
			pictureBox1->Image = Img_Source;
		}
		if (opnFileDlg->FileName->IndexOf("pcx") > 0)
		{	
			PCXData data;
			LoadPCXFile(opnFileDlg->FileName, data);
			Img_Source = data.Image;
			pictureBox1->Image = Img_Source;
		}
	}
}
private: System::Void toolStripBtn_Gray_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	pictureBox2->Image = img_processed;
}
private: System::Void Btn_ToRed_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToRed);
	pictureBox2->Image = img_processed;
}
private: System::Void Btn_ToGreen_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToGreen);
	pictureBox2->Image = img_processed;
}
private: System::Void Btn_ToBlue_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, ToBlue);
	pictureBox2->Image = img_processed;
}
private: System::Void toolStripButton_horizontalFilp_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, horizontal);
	pictureBox2->Image = img_processed;
}
private: System::Void Btn_verticalFlip_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, vertical);
	pictureBox2->Image = img_processed;
}
private: System::Void toolStripButton_diagonal_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	Flip(Img_Source, img_processed, diagonal);
	pictureBox2->Image = img_processed;
}
private: System::Void toolStripButton_Threshold_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed,RGB2Gray);
	Threshold(img_processed, img_processed, 100,THRESH_BINARY);
	pictureBox2->Image = img_processed;
}
private: System::Void toolStripButton_Threshold_Inv_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap ^ img_processed;
	ConvertColor(Img_Source, img_processed, RGB2Gray);
	Threshold(img_processed, img_processed, 100, THRESH_BINARY_Inv);
	pictureBox2->Image = img_processed;
}

private: System::Void Btn_ZoomIn_Click(System::Object^  sender, System::EventArgs^  e) {
	double ZoomRate = System::Convert::ToDouble(TextBox_ZoomRate->Text);
	Bitmap ^ dst;
	ZoomFunction(Img_Source,dst, ZoomRate, Duplication);
	pictureBox2->Image = dst;
}
private:void ZoomFunction(Bitmap^ src, Bitmap^% dst,double Rate, int code)
{
	if (Rate > 0 && src != nullptr)
	{
	dst = gcnew Bitmap((int)src->Width*Rate + 0.5, (int)src->Height*Rate + 0.5);
	 switch (code)
	 {
	 case Duplication:
		 for(unsigned int i=0;i<dst->Width;i++)
			 for (unsigned int j = 0; j < dst->Height; j++)
			 {
				 float index_x = (float)(i / Rate);
				 float index_y = (float)(j / Rate);
				 dst->SetPixel(i, j, src->GetPixel((int)index_x + 0.5, (int)index_y+0.5));
			 }
		 break;
	 case other://若比例小於原圖用平均法，大於原圖則用差分法
		 if(Rate > 0 && Rate < 1)//縮小
		 {
		 
		 for (unsigned int i = 0; i<dst->Width; i++)
			 for (unsigned int j = 0; j < dst->Height; j++)
			 {
				 int set_x = i * Rate;
				 int set_y =j*Rate;
				 float R_x = i * Rate - set_x;
				 float R_y = j * Rate - set_y;
		     }
		 }
		 if (Rate>1)
		 {

		 }
		 break;
	 default:
		 break;
	 }
	}
	else
	{
		MessageBox::Show("No Image yet or Rate cannot be smaller than zero!");
	}
}
private: System::Void tBtn_otherZoom_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (Img_Source != nullptr) {
		Pos_X->Text = e->X.ToString();
		Pos_Y->Text = e->Y.ToString();
		System::String ^str;
		Color c = Img_Source->GetPixel(e->X, e->Y);
		str ="RGB:("+c.R.ToString()+" , " + c.G.ToString()+" , " + c.B.ToString()+ ")";
		Pos_RGBvalue->Text = str;//^^dhgdjka
	}
}
};
}
