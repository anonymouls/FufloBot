//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>

#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
String lastX, lastY;
int counter = 10;
TIniFile * Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"SaO.ini");
bool active = false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::OKBTNClick(TObject *Sender)
{
 Form2->Close();
 Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::addoneClick(TObject *Sender)
{
 Label1->Visible = true;
 Label2->Visible = true;
 ShowMessage("Наведите на нужную кнопку и втыкайте 10 секунд");
 Timer1->Enabled = True;
 addone->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	TMouse * M = new TMouse;
	int x = M->CursorPos.x;
	int y = M->CursorPos.y;
	Label1->Caption = "X: "+x;
	Label2->Caption = "Y: "+y;
	Label5->Visible = true;
	if (lastX == Label1->Caption && lastY == Label2->Caption) {
	 Label5->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
	 counter--;
	} else counter = 10;
	if (counter == 0) {
	 Timer1->Enabled = false;
	 addone->Enabled = true;
	 Ini->WriteInteger("Settings","Xaddone",x);
	 Ini->WriteInteger("Settings","Yaddone",y);
	 Label1->Caption = "Отступ направо";
	 Label2->Caption = "Отступ сверху";
	 Label5->Visible = false;
	 counter = 10;
	}
	lastX = Label1->Caption;
	lastY = Label2->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cleanClick(TObject *Sender)
{
 ShowMessage("Наведите на нужную кнопку и втыкайте 10 секунд");
 Timer2->Enabled = True;
 clean->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
	TMouse * M = new TMouse;
	int x = M->CursorPos.x;
	int y = M->CursorPos.y;
	Label1->Caption = "X: "+IntToStr(x);
	Label2->Caption = "Y: "+IntToStr(y);
	Label5->Visible = true;
	if (lastX == Label1->Caption && lastY == Label2->Caption) {
	 Label3->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
	 counter--;
	} else counter = 10;
	if (counter == 0) {
	 Timer2->Enabled = false;
	 clean->Enabled = true;
	 Ini->WriteInteger("Settings","Xcl",x);
	 Ini->WriteInteger("Settings","Ycl",y);
	 Label1->Caption = "Отступ направо";
	 Label2->Caption = "Отступ сверху";
	 Label5->Visible = false;
	}
	lastX = Label1->Caption;
	lastY = Label2->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckINClick(TObject *Sender)
{
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width =  Ini->ReadInteger("Settings","WZX",0);
 int Height = Ini->ReadInteger("Settings","WZY",0);
 Form3->Im->Width = Width; 		   Form3->Im->Height = Height;
 Form3->Width = Width+100;   Form3->Height	  = Height+100;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 Form3->Im->Picture->Bitmap->SaveToFile(ExtractFilePath(Application->ExeName)+"tmp.bmp");
 Form3->Show();
 Timer3->Enabled  = true;
 Button1->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","CHL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","CHT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","CHX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","CHY",StrToInt(Edit4->Text));
  active = false;
  Button1->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
 }
 active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width =  (Rect.Right) - (Rect.Left);
 int Height = (Rect.Bottom) - (Rect.Top);
 Form3->Im->Width = Width; 		   Form3->Im->Height = Height;
 Form3->Width = Width+100;   Form3->Height	  = Height+100;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 Form3->Im->Picture->Bitmap->SaveToFile(ExtractFilePath(Application->ExeName)+"tmp.bmp");
 Form3->Show();
 Timer3->Enabled  = true;
 Label1->Visible  = false;		Label2->Visible  = false;
 Edit1->Visible	  = false;		Edit2->Visible   = false;
 counter = -1;  				active = true;
 CheckIN->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","WZX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","WZY",StrToInt(Edit4->Text));
  active = false;
  CheckIN->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
  counter = 10;
 }

}
//---------------------------------------------------------------------------
void Execute() {
// if (counter == -1) {
	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = 120; //величина прозрачности (0-255)
	bf.AlphaFormat = 0;
	AlphaBlend(Form3->Im->Picture->Bitmap->Canvas->Handle,
	StrToInt(Form2->Edit1->Text), StrToInt(Form2->Edit2->Text),
	StrToInt(Form2->Edit3->Text), StrToInt(Form2->Edit4->Text),
	Form2->Image1->Picture->Bitmap->Canvas->Handle, 0, 0, 8, 8,bf);
	Form3->Im->Repaint(); //}
  //else {
	 Form2->Im->Canvas->CopyRect(TRect(0,0,StrToInt(Form2->Edit3->Text),StrToInt(Form2->Edit4->Text)),
	 Form3->Im->Canvas,
	 TRect(StrToInt(Form2->Edit1->Text),StrToInt(Form2->Edit2->Text),
	 StrToInt(Form2->Edit3->Text),StrToInt(Form2->Edit4->Text)));
	// Form3->Im->Height = StrToInt(Form2->Edit1->Text) - StrToInt(Form2->Edit2->Text);
	// Form3->Im->Width  = StrToInt(Form2->Edit3->Text) - StrToInt(Form2->Edit4->Text);
	// Form3->Im->Repaint();
   //	}   */
	Form2->Im->Width  = StrToInt(Form2->Edit3->Text);
	Form2->Im->Height = StrToInt(Form2->Edit4->Text);
}

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
 // сбацать проверку
 Execute();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
 DeleteFile(ExtractFilePath(ExtractFilePath(Application->ExeName)+"tmp.bmp"));
 Form3->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Timer3Timer(TObject *Sender)
{
 Form3->Im->Picture->Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName)+"tmp.bmp");
 Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
 for(int i = 0;i<8;i++) {
	 for (int j = 0; j < 8; j++) {
		Image1->Canvas->Pixels[i][j] = 4542681;
	 }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::HistoryClick(TObject *Sender)
{
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width =  Ini->ReadInteger("Settings","WZX",0);
 int Height = Ini->ReadInteger("Settings","WZY",0);
 Form3->Im->Width = Width; 		   Form3->Im->Height = Height;
 Form3->Width = Width+100;   Form3->Height	  = Height+100;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 Form3->Im->Picture->Bitmap->SaveToFile(ExtractFilePath(Application->ExeName)+"tmp.bmp");
 Form3->Show();
 Timer3->Enabled  = true;
 Button1->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","HZL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","HZT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","HZX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","HZY",StrToInt(Edit4->Text));
  active = false;
  Button1->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
 }
 active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LastOClick(TObject *Sender)
{
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width =  Ini->ReadInteger("Settings","WZX",0);
 int Height = Ini->ReadInteger("Settings","WZY",0);
 Form3->Im->Width = Width; 		   Form3->Im->Height = Height;
 Form3->Width = Width+100;   Form3->Height	  = Height+100;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 Form3->Show();
 Timer3->Enabled  = true;
 Button1->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","LOL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","LOT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","LOX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","LOY",StrToInt(Edit4->Text));
  active = false;
  Button1->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
 }
 active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
 Label1->Visible = true;
 Label2->Visible = true;
 ShowMessage("Наведите на нужную кнопку и втыкайте 10 секунд");
 Timer1->Enabled = True;
 Button2->Enabled = false;
 Label5->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
 if (active==false) {
  Label1->Caption = "Баланс";
  active = true;
 } else {
  active = false;
  Ini->WriteInteger("Personal","Balance",StrToInt(Edit1->Text));
  Label1->Caption = "Отступ направо";
  Edit1->Text = 0;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
 Label1->Visible = true;
 Label2->Visible = true;
 ShowMessage("Наведите на нужную кнопку и втыкай 10 секунд");
 Timer4->Enabled = True;
 Button4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer4Timer(TObject *Sender)
{
 TMouse * M = new TMouse;
 int x = M->CursorPos.x;
 int y = M->CursorPos.y;
 Label1->Caption = "X: "+IntToStr(x);
 Label2->Caption = "Y: "+IntToStr(y);
 Label5->Visible = true;
 if (lastX == Label1->Caption && lastY == Label2->Caption) {
  Label5->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
  counter--;
 } else counter = 10;
 if (counter == 0) {
  Timer4->Enabled = false;
  clean->Enabled = true;
  Ini->WriteInteger("Settings","XR",x);
  Ini->WriteInteger("Settings","YR",y);
  Label1->Caption = "Отступ направо";
  Label2->Caption = "Отступ сверху";
  Label5->Visible = false;
 }
 lastX = Label1->Caption;
 lastY = Label2->Caption;
}
//---------------------------------------------------------------------------

