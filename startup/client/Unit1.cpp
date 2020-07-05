//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
String Path;
String STA;
int Lasthash = 0,hash, BETS = 0, WONS = 0;
int X,Y,LX,LY,CS = 1, iteration = 0;
bool OkayExit = true;
TIniFile * Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"SET.ini");
TTime Tik = Time();
//
HWND Wnd;
//---------------------------------------------------------------------------
void PLACE(int Many) {
 if (CS > (Ini->ReadInteger("Settinds","Danger",0))) {
  if (Wnd!=0) {
   Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, 0, NULL);
   TRect Rect;
   GetWindowRect(Wnd, &Rect);
   long F = Ini->ReadInteger("Settings","XC",0) + ((Ini->ReadInteger("Settings","YC",0)-Rect.Top) << 16);
   PostMessage(Wnd, WM_LBUTTONDOWN,0,F);
   PostMessage(Wnd, WM_LBUTTONUP,0,F);
  for(int i = 1;i<=Many;i++) {
	F = Ini->ReadInteger("Settings","X1",0) + ((Ini->ReadInteger("Settings","Y1",0)-Rect.Top) << 16);
	PostMessage(Wnd, WM_LBUTTONDOWN,0,F);
	PostMessage(Wnd, WM_LBUTTONUP,0,F);
	Application->ProcessMessages();
  }
  F = Ini->ReadInteger("Settings","XR",0) + ((Ini->ReadInteger("Settings","YR",0)-Rect.Top) << 16);
  if (Form1->CheckBox1->Checked==false) {
   PostMessage(Wnd, WM_LBUTTONDOWN,0,F);
   PostMessage(Wnd, WM_LBUTTONUP,0,F);
  }
   F = Ini->ReadInteger("Settings","XC",0) + ((Ini->ReadInteger("Settings","YC",0)-Rect.Top) << 16);
   PostMessage(Wnd, WM_LBUTTONDOWN,0,F);
   PostMessage(Wnd, WM_LBUTTONUP,0,F);
 } else {
   ShowMessage("Проблемы с захватом окна браузера"); }
 } else {
   Form1->SB->Panels->Items[0]->Text = "Danger Level Released, Stopping";
   Form1->Button2->Click();
 }
}
//-------------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 if (Wnd!=0) {
 try {
  FTP->Connect();
  Timer1->Enabled = true;
  Button1->Enabled = false;
  Button2->Enabled = true;
  SB->Panels->Items[0]->Text = "WORKING";
 } catch (...) {
  ShowMessage("Server is dead... Try later");
  Timer1->Enabled = false;
 }
 } else {
  SB->Panels->Items[0]->Text = "Problem with window of browser. Try again.";
  Button1->Enabled = true;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 SB->Panels->Items[0]->Text = "WORKING";
 if (FTP->Connected()) {
  DeleteFile(ExtractFilePath(Application->ExeName)+"info.ini");
  FTP->Get("/info/info.ini",ExtractFilePath(Application->ExeName)+"info.ini",true,true);
  TIniFile * Check = new TIniFile(ExtractFilePath(Application->ExeName)+"info.ini");
  hash = Check->ReadInteger("Result","Seed",0);
  if (hash!= 0 && hash!= Lasthash) {
	Lasthash = hash;
	if (Check->ReadBool("Result","Drop",false)==false) {
	 CS *= 2;
	 BETS++;
	 Label3->Caption = "Выпало НЕ красное";
	 PLACE(CS);
	} else {
	 CS = Ini->ReadInteger("Settings","Start",1);
	 Label3->Caption = "Выпало красное";
	 BETS++;
	 WONS++;
	 PLACE(CS);
	}
   Label1->Caption = "Текущая ставка: "+IntToStr(CS);
   Label2->Caption = "Навар: "		   +IntToStr(WONS);
  }
    if (OkayExit != true) {
		Ini->EraseSection("Result");
		OkayExit = true;  }
  }
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 CS = Ini->ReadInteger("Settings","Start",1);
 Constraints->MaxHeight = 319;
 Constraints->MaxWidth  = 379;
 Path  = ExtractFilePath(Application->ExeName);
 BETS  = Ini->ReadInteger("Stats","BT",0); 	 BETS /= 3;
 WONS  = Ini->ReadInteger("Stats","WN",0);   WONS /= 2;
 OkayExit = Ini->ReadBool("Return","Safe",true);
 FTP->Host  	= Ini->ReadString("LogInfo","IP","");
 FTP->Password  = Ini->ReadString("LogInfo","P","");
 FTP->Username  = Ini->ReadString("LogInfo","N","");
 if (OkayExit != true) {
  Lasthash = Ini->ReadInteger("Return","hash",0);
  CS 	   = Ini->ReadInteger("Return","CurS",1);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Label2->Visible = false;
 Label1->Visible = true;
 Timer1->Enabled = false;
 Timeout->Enabled= false;
 Button1->Enabled = true;
 Button2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 if (Lasthash != 0) {
  TIniFile * Deploy = new TIniFile(ExtractFilePath(Application->ExeName)+"FN.ini");
  Deploy->WriteInteger("Stats","BETS",BETS);
  Deploy->WriteInteger("Stats","WONS",WONS);
  Deploy->WriteTime("Stats","TimeofWork",Time()-Tik);
  Deploy->UpdateFile();
  Deploy->Free();
  srand(time(NULL));
  int S = rand();
  if (FTP->Connected()) {
   FTP->Put(ExtractFilePath(Application->ExeName)+"FN.ini","/data/"+IntToStr(S)+".ini",true);
   FTP->Disconnect(true);
  }
  Ini->WriteInteger("Stats","BT",BETS*3);
  Ini->WriteInteger("Stats","WN",WONS*2);
  Ini->UpdateFile();
   if (OkayExit != true) {
	Ini->WriteBool("Return","Safe",OkayExit);
  }
  Ini->Free();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if (GroupBox1->Visible==false) {
  GroupBox1->Visible = true;
 } else {
  GroupBox1->Visible = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 ShowMessage("Наведи на +1 и 10 втыкай секунд");
 for (int i = 10; i > -1; i--) {
   TMouse * M = new TMouse;
   int Y = M->CursorPos.x;
   int X = M->CursorPos.y;
   if (LX!= X || LY != Y) {
	 i = 10;
   }
   LX = X; LY =Y;
   Sleep(1000);
  }
  Ini->WriteInteger("Settings","X1",LY);
  Ini->WriteInteger("Settings","Y1",LX);
  Beep(50,1200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 ShowMessage("Наведи на clean и 10 втыкай секунд");
 for (int i = 10; i > -1; i--) {
   TMouse * M = new TMouse;
   int Y = M->CursorPos.x;
   int X = M->CursorPos.y;
   if (LX!= X || LY != Y) {
	 i = 10;
   }
   LX = X; LY =Y;
   Sleep(1000);
  }
  Ini->WriteInteger("Settings","XC",LY);
  Ini->WriteInteger("Settings","YC",LX);
  Beep(50,1200);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
ShowMessage("Наведи на красное и 10 втыкай секунд");
 for (int i = 10; i > -1; i--) {
   TMouse * M = new TMouse;
   int Y = M->CursorPos.x;
   int X = M->CursorPos.y;
   if (LX!= X || LY != Y) {
	 i = 10;
   }
   LX = X; LY =Y;
   Sleep(1000);
  }
  Ini->WriteInteger("Settings","XR",LY);
  Ini->WriteInteger("Settings","YR",LX);
  Beep(50,1200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FTPDisconnected(TObject *Sender)
{
 Timer1->Enabled = false;
 Timeout->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimeoutTimer(TObject *Sender)
{
/* Ping->ReceiveTimeout = 1000;
 Ping->Host = Ini->ReadString("LogInfo","Host","");
 Ping->Ping();
 Application->ProcessMessages();*/
 if (Lasthash == hash && iteration == 3) {
  TI->BalloonTimeout = 500000;
  TI->Hint = "CONNECTION LOST OR SERVER DEAD";
 }
 if (Lasthash != hash) iteration = 0; else iteration++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PingReply(TComponent *ASender, TReplyStatus * const AReplyStatus){
 if(AReplyStatus->BytesReceived>0) {
  Button1->Click();
  Timeout->Enabled = true;
  SB->Panels->Items[0]->Text = "CONNECTION DEAD. WAITING TO RECONNECT";
  Ini->WriteInteger("Return","CurS",CS);
  Ini->WriteInteger("Return","hash",Lasthash);
  Ini->UpdateFile();
 } else {
 SB->Panels->Items[0]->Text = "CONNECTION RETURNED. STARTING WORK";
 Timeout->Enabled = false;
 TForm1::Button2Click(NULL);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
 if (WindowState == wsMinimized) {
  TI->Visible = true;
  ShowWindow(Form1->Handle,SW_HIDE);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TIClick(TObject *Sender)
{
 WindowState = wsNormal;
 ShowWindow(Form1->Handle,SW_SHOW);
 TI->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 String S = Edit1->Text;
 if (Edit1->Enabled == false) {
 Edit1->Enabled = true;
 Button8->Enabled = false;
 Button7->Caption = "Save";
 } else {
   if (S.Length()>0) {
	Ini->WriteInteger("Settings","Start",StrToInt(Edit1->Text));
	Button8->Enabled = true;
	Edit1->Enabled   = false;
	Edit1->Text 	 = 1;
	Button7->Caption = "First Bet";
 } else {
   Edit1->Text = "Enter correctly";
   Sleep(3000);
   Edit1->Text = 1;
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Click(TObject *Sender)
{
 Edit1->Text = "1";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 String S = Edit1->Text;
 if (Edit1->Enabled == false) {
 Edit1->Enabled = true;
 Button7->Enabled = false;
 Button8->Caption = "Save";
 } else {
   if (S.Length()>0) {
	Ini->WriteInteger("Settings","Danger",StrToInt(Edit1->Text));
	Button8->Enabled = true;
	Edit1->Enabled   = false;
	Edit1->Text 	 = 1;
	Button7->Caption = "Danger Level";
 } else {
   Edit1->Text = "Enter correctly";
   Sleep(3000);
   Edit1->Text = 1;
  }
 }
}
//---------------------------------------------------------------------------


