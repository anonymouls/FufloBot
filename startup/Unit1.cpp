//---------------------------------------------------------------------------
// 5198809 - super red   4542681 - red
// PostMessage с неактивным окном
// Im2 check zone 	| 	Im screenshot 	| Im3 what is it   | Im4 History
#include <vcl.h>
#include <Vcl.Graphics.hpp>
#include <IdHashMessageDigest.hpp>
#include <string>
#include <System.IniFiles.hpp>
#include <Vcl.Forms.hpp>
#include <Clipbrd.hpp>

#pragma hdrstop

#include "Unit1.h"
//#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
//#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
HWND Wnd, H; 			// рабочее окно    + xren` dlya posta
//int Balance;			// баланс (чет чуть косо показывает)
//int CurrentS = 1; 		// текущая ставка
//int navar = 0;   		// рулетка крутится деньши мутятся
bool chk   = false; 	// проверка истории
//int StatsReds = 0, StatsNoRed = 0, StatsStavkas = 0; // Stats
String hash;    		// проверка, clone
bool Allow = false, Ethernet;
void STATUSREPORT(int,int,int);
void PLACE(int);
bool CheckIn();
//            OTHER
bool DelSelf();    // не работает
//            UNIT2
bool active = false;
String lastX, lastY;
int counter = 10;
//
TIniFile * Ini = new TIniFile(ExtractFilePath(Application->ExeName)+"SaO.ini");
TIniFile * InfoIni = new TIniFile(ExtractFilePath(Application->ExeName)+"info\\info.ini");
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if (!WT->Enabled) {
  Button1->Caption = "Пашет";
  RESP->Enabled    = true;
  SB->Panels->Items[1]->Text = "Working";
  Button2->Enabled = false;
  WT->Enabled = true;
 } else {
  WT->Enabled = false;
  Button1->Caption = "Начать";
  SB->Panels->Items[1]->Text = "Disengaged";
  Button2->Enabled = false;
  RESP->Enabled    = false;
 }
}
//---------------------------------------------------------------------------
void EthernetCheck() {
 try {
  Form1->HTTP->Get("http://www.csgodouble.com/");
  Ethernet = true;
 } catch (EIdHTTPProtocolException &se) {
   switch (se.ErrorCode) {
	case 404: break;
	case 303: break;
	case 400: break;
	 default: break;
   }
   Form1->SB->Panels->Items[1]->Text = "Error caught ProtocolException";
 }
 catch (EIdSocketError &se) {
	 if(se.LastError == 11001)  {
	 Ethernet = false;
	 Form1->SB->Panels->Items[1]->Text = "Error caught 11001";
	 }
 }
}


bool CheckIn(){
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width  = Ini->ReadInteger("Settings","WZX",0);
 int Height = Ini->ReadInteger("Settings","WZY",0);
 Form3->Im->Width = Width; 	Form3->Im->Height = Height;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 TRect R2(Ini->ReadInteger("Settings","LOL",0),Ini->ReadInteger("Settings","LOT",0),
		  Ini->ReadInteger("Settings","LOX",0),Ini->ReadInteger("Settings","LOY",0));
 TRect R1(0,0,abs(R2.Width()),abs(R2.Height()));
 Form1->Im3->Width  = abs(R2.Width());
 Form1->Im3->Height = abs(R2.Height());
 Form1->Im3->Canvas->CopyRect(R1,Form3->Im->Canvas,R2);
 bool isred = false;
 bool quit  = false;
 chk = false;
 for(int i = 0; i<Form1->Im3->Width;i++)   {
	for(int j = 0;j<Form1->Im3->Height;j++) {
	  int check = Form1->Im3->Canvas->Pixels[i][j];
	  if (check == 5198809 || check == 2896073 || check == 3619787) {
		isred = true;
		quit = true;
		break;
	  }
	 if (chk == false && (check == 14737632 || check == 16119285 || check == 16119285)) chk = true;
	}
	if (quit==true) break;
 }
 return isred;
}

void __fastcall TForm1::WTTimer(TObject *Sender)
{
 if (Wnd!=0) {
 TRect Rect;
 GetWindowRect(Wnd, &Rect);
 int Width  = Ini->ReadInteger("Settings","WZX",0);
 int Height = Ini->ReadInteger("Settings","WZY",0);
 bool ignore = false;
 Form3->Im->Width = Width; 	Form3->Im->Height = Height;
 BitBlt(Form3->Im->Canvas->Handle, 0, 0, Width, Height,GetWindowDC(Wnd), 0, 0, SRCCOPY);
 TRect R2(Ini->ReadInteger("Settings","HZL",0),Ini->ReadInteger("Settings","HZT",0),
		  Ini->ReadInteger("Settings","HZX",0),Ini->ReadInteger("Settings","HZY",0));
 TRect R1(0,0,abs(R2.Width()),abs(R2.Height()));
 Im4->Width  = abs(R2.Width());
 Im4->Height = abs(R2.Height());
 Im4->Canvas->CopyRect(R1,Form3->Im->Canvas,R2);
 if (!FileExists(ExtractFilePath(Application->ExeName)+"filecheck.jpg")) {
   Im4->Picture->SaveToFile(ExtractFilePath(Application->ExeName)+"filecheck.jpg");
   Im4->Picture->Bitmap->FreeImage();
   TIdHashMessageDigest5 *idmd5 = new TIdHashMessageDigest5();
   TFileStream *fs= new TFileStream(ExtractFilePath(Application->ExeName)+"filecheck.jpg", fmOpenRead);
   hash = idmd5->HashStreamAsHex(fs);
   fs->Free();
   idmd5 = NULL;
 } else {
   Im4->Picture->SaveToFile(ExtractFilePath(Application->ExeName)+"filecheck.jpg");
   TFileStream *fs= new TFileStream(ExtractFilePath(Application->ExeName)+"filecheck.jpg", fmOpenRead);
   TIdHashMessageDigest5 *idmd5 = new TIdHashMessageDigest5();
   String hash2 = idmd5->HashStreamAsHex(fs);
   fs->Free();
   if (hash!=hash2 || Allow==true) {
	  hash = hash2;
	  Ini->WriteBool("Debug","Idle",true);
	  } else {
	 ignore = true;
	}
   delete idmd5;
 }
 if (!ignore) {
 Ini->WriteBool("Debug","Idle",false);
 TRect R5(Ini->ReadInteger("Settings","CHL",0),Ini->ReadInteger("Settings","CHT",0),
		  Ini->ReadInteger("Settings","CHX",0),Ini->ReadInteger("Settings","CHY",0));
 TRect R4(0,0,abs(R5.Width()),abs(R5.Height()));
 Im2->Width  = abs(R5.Width());
 Im2->Height = abs(R5.Height());
 Im2->Canvas->CopyRect(R4,Form3->Im->Canvas,R5);
 bool quit = false;
 bool what;
 for(int i = 0;i < Im2->Width;i++) {
	for(int j = 0; j < Im2->Height;j++) {
	int check = Im2->Canvas->Pixels[i][j] ;
	if (check == 5198809) {
	 SB->Panels->Items[1]->Text = "Checking";
	 what = CheckIn();
	 if (what == false && chk == true){
	 //S2->Caption = "Не красное";
	 //CurrentS = CurrentS * 2;
	 //PLACE(CurrentS);
	 //Balance -= CurrentS;
	 //StatsNoRed++;
	 Allow = false;
	}
	Application->ProcessMessages();
	 if (what == true && chk == true){
	  /*S2->Caption = "Красное";
	  Balance+=CurrentS+1;
	  CurrentS = 1;
	  PLACE(CurrentS);
	  navar++;
	  StatsReds++;*/
	  Allow = false;
	}
	quit = true;
	break;
	}
   }
	if (quit==true) {
	InfoIni->WriteBool("Result","Drop",what);
	srand(time(NULL));
	InfoIni->WriteInteger("Result","Seed",rand()+1);
	InfoIni->UpdateFile();
	break;
	}  else {
	 SB->Panels->Items[1]->Text = "Ждем конца крутилки";
	 Allow = true;
	 }
  }
 Form1->Im->Picture->Bitmap->FreeImage();
 SB->Panels->Items[0]->Text = "";
 } else {
   SB->Panels->Items[1]->Text = "Ожидание следущего раунда";
  }
 } else {
	SB->Panels->Items[0]->Text = "Окно потеряно";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 String object = Ini->ReadString("AdminInfo","Object","");
 while (Wnd == NULL){
  Wnd = FindWindowEx(FindWindow(NULL, object.w_str()), 0, NULL, NULL);
 }
 //H = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, L"Chrome_RenderWidgetHostHWND", NULL);
 DeleteFile(ExtractFilePath(Application->ExeName)+"filecheck.jpg");
// Balance = Ini->ReadInteger("Personal","Balance",0)-1;
 for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
	Image1->Canvas->Pixels[i][j] = clRed;
  }
 }
 if (Ini->ReadBool("Debug","FParam",false)==true) {
  Restart->Enabled = true;
  SB->Panels->Items[1]->Text = "Working was reloaded";
  Ini->WriteString("Reloads",TimeToStr(Time()),DateToStr(Date()));
  Ini->WriteBool("Debug","FParam",false);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 /* статистика
  int tmpN = Ini->ReadInteger("OwerallStats","OVN",0);
  Ini->WriteInteger("OwerallStats","OVN",tmpN+navar);
  tmpN = Ini->ReadInteger("OwerallStats","RED",0);
  Ini->WriteInteger("OwerallStats","RED",tmpN+StatsReds);
  tmpN = Ini->ReadInteger("OwerallStats","NRED",0);
  Ini->WriteInteger("OwerallStats","NRED",tmpN+StatsNoRed);
  tmpN = Ini->ReadInteger("OwerallStats","ENG",0);
  Ini->WriteInteger("OwerallStats","ENG",tmpN+StatsStavkas);
  Ini->UpdateFile();
 */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 HWND N = FindWindow(NULL, L"CSGODouble - Google Chrome");
 ShowWindow(N, SW_SHOW);
}
//---------------------------------------------------------------------------
// X always correct here
void PLACE(int Many) {
  if (Form1->CheckBox1->Checked==false) {
   H = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, L"Chrome_RenderWidgetHostHWND", NULL);
   TRect Rect;
   GetWindowRect(H, &Rect);
   long F = Ini->ReadInteger("Settings","Xcl",0) + ((Ini->ReadInteger("Settings","Ycl",0)-Rect.Top) << 16);
   PostMessage(H, WM_LBUTTONDOWN,0,F);
   PostMessage(H, WM_LBUTTONUP,0,F);
   Sleep(50);
  for(int i = 1;i <= Many;i++) {
	F = Ini->ReadInteger("Settings","Xaddone",0) + ((Ini->ReadInteger("Settings","Yaddone",0)-Rect.Top) << 16);
	PostMessage(H, WM_LBUTTONDOWN,0,F);
	Sleep(50);
	PostMessage(H, WM_LBUTTONUP,0,F);
	Application->ProcessMessages();
  }
  F = Ini->ReadInteger("Settings","XR",0) + ((Ini->ReadInteger("Settings","YR",0)-Rect.Top) << 16);
   PostMessage(H, WM_LBUTTONDOWN,0,F);
   PostMessage(H, WM_LBUTTONUP,0,F);
  F = Ini->ReadInteger("Settings","Xcl",0) + ((Ini->ReadInteger("Settings","Ycl",0)-Rect.Top) << 16);
  PostMessage(H, WM_LBUTTONDOWN,0,F);
  PostMessage(H, WM_LBUTTONUP,0,F);
  Sleep(50);
  }
}

// UNIT DVA BLYAD

//---------------------------------------------------------------------------
void __fastcall TForm1::addoneClick(TObject *Sender)
{
 TL->Visible = true;
 TT->Visible = true;
 ShowMessage("Наведите на нужную кнопку и втыкайте 10 секунд");
 Timer2->Enabled = True;
 addone->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	TMouse * M = new TMouse;
	int x = M->CursorPos.x;
	int y = M->CursorPos.y;
	TL->Caption = "X: "+x;
	TT->Caption = "Y: "+y;
	STA->Visible = true;
	if (lastX == TL->Caption && lastY == TT->Caption) {
	 STA->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
	 counter--;
	} else counter = 10;
	if (counter == 0) {
	 Timer2->Enabled = false;
	 addone->Enabled = true;
	 Ini->WriteInteger("Settings","Xaddone",x);
	 Ini->WriteInteger("Settings","Yaddone",y);
	 TL->Caption = "Отступ направо";
	 TT->Caption = "Отступ сверху";
	 STA->Visible = false;
	 counter = 10;
	}
	lastX = TL->Caption;
	lastY = TT->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cleanClick(TObject *Sender)
{
 ShowMessage("Наведите на нужную кнопку и втыкайте 10 секунд");
 Timer4->Enabled = True;
 clean->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	TMouse * M = new TMouse;
	int x = M->CursorPos.x;
	int y = M->CursorPos.y;
	TL->Caption = "X: "+IntToStr(x);
	TT->Caption = "Y: "+IntToStr(y);
	STA->Visible = true;
	if (lastX == TL->Caption && lastY == TT->Caption) {
	 STA->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
	 counter--;
	} else counter = 10;
	if (counter == 0) {
	 Timer3->Enabled = false;
	 clean->Enabled = true;
	 Ini->WriteInteger("Settings","Xcl",x);
	 Ini->WriteInteger("Settings","Ycl",y);
	 TL->Caption = "Отступ направо";
	 TT->Caption = "Отступ сверху";
	 STA->Visible = false;
	}
	lastX = TL->Caption;
	lastY = TT->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckINClick(TObject *Sender)
{
 HWND Wnd = FindWindowEx(FindWindow(NULL, L"CSGODouble - Google Chrome"), 0, NULL, NULL);
 if (Wnd!=0) {
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
 Im->Visible = true;
 Button1->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","CHL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","CHT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","CHX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","CHY",StrToInt(Edit4->Text));
  Ini->WriteBool("Result","Danger",false);
  active = false;
  Button1->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
  Im->Visible = false;
  }
 } else {
   InfoIni->WriteBool("Result","Danger",false);
   InfoIni->UpdateFile();
 }
 active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnwzClick(TObject *Sender)
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
 TL->Visible  = false;		TT->Visible  = false;
 Edit1->Visible	  = false;		Edit2->Visible   = false;
 counter = -1;
 CheckIN->Enabled = false;		History->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","WZX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","WZY",StrToInt(Edit4->Text));
  active = false;
  CheckIN->Enabled = true;		History->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
 } else active = true;
}
//---------------------------------------------------------------------------
void Execute() {
	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = 120; //величина прозрачности (0-255)
	bf.AlphaFormat = 0;
	TRect R1(StrToInt(Form1->Edit1->Text),StrToInt(Form1->Edit2->Text),
			 StrToInt(Form1->Edit3->Text),StrToInt(Form1->Edit4->Text));
	AlphaBlend(Form3->Im->Picture->Bitmap->Canvas->Handle,
	StrToInt(Form1->Edit1->Text), StrToInt(Form1->Edit2->Text),
	abs(R1.Width()), abs(R1.Height()),
	Form1->Image1->Picture->Bitmap->Canvas->Handle, 0, 0, 8, 8,bf);
	Form1->Im->Repaint();
	Form1->Im->Canvas->CopyRect(TRect(0,0,abs(R1.Width()),abs(R1.Height())),
	Form3->Im->Canvas,	 R1);
	Form1->Im->Width  = abs(R1.Width());
	Form1->Im->Height = abs(R1.Height());
	Form1->Im->Refresh();
}

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 // сбацать проверку
 Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
 Form3->Im->Picture->Bitmap->LoadFromFile(ExtractFilePath(Application->ExeName)+"tmp.bmp");
 Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HistoryClick(TObject *Sender)
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
 Button1->Enabled = false;		CheckIN->Enabled = false;     LastO->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","HZL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","HZT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","HZX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","HZY",StrToInt(Edit4->Text));
  active = false;
  Button1->Enabled = true;		CheckIN->Enabled = true;     LastO->Enabled = true;
  Form3->Close();
 }
 active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LastOClick(TObject *Sender)
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
 Button1->Enabled = false;		History->Enabled = false;     CheckIN->Enabled = false;
 if (active != false) {
  Ini->WriteInteger("Settings","LOL",StrToInt(Edit1->Text));
  Ini->WriteInteger("Settings","LOT",StrToInt(Edit2->Text));
  Ini->WriteInteger("Settings","LOX",StrToInt(Edit3->Text));
  Ini->WriteInteger("Settings","LOY",StrToInt(Edit4->Text));
  active = false;
  Button1->Enabled = true;		History->Enabled = true;     CheckIN->Enabled = true;
  Form3->Close();
 }
 active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::balanClick(TObject *Sender)
{
 if (active==false) {
  TL->Caption = "Баланс";
  active = true;
 } else {
  active = false;
  Ini->WriteInteger("Personal","Balance",StrToInt(Edit1->Text));
  TL->Caption = "Отступ направо";
  Edit1->Text = 0;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::redlockClick(TObject *Sender)
{
 TL->Visible = true;
 TT->Visible = true;
 ShowMessage("Наведите на нужную кнопку и втыкай 10 секунд");
 Timer5->Enabled = True;
 redlock->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
 TMouse * M = new TMouse;
 int x = M->CursorPos.x;
 int y = M->CursorPos.y;
 TL->Caption = "X: "+IntToStr(x);
 TT->Caption = "Y: "+IntToStr(y);
 STA->Visible = true;
 if (lastX == TL->Caption && lastY == TT->Caption) {
  STA->Caption = "Ждите еще "+IntToStr(counter)+" секунд";
  counter--;
 } else counter = 10;
 if (counter == 0) {
  Timer5->Enabled = false;
  clean->Enabled = true;
  Ini->WriteInteger("Settings","XR",x);
  Ini->WriteInteger("Settings","YR",y);
  TL->Caption = "Отступ направо";
  TT->Caption = "Отступ сверху";
  STA->Visible = false;
 }
 lastX = TL->Caption;
 lastY = TT->Caption;
}
// OTHER
bool DelSelf()
{
  TCHAR szFile[MAX_PATH], szCmd[MAX_PATH];

  if((GetModuleFileName(0,szFile,MAX_PATH)!=0) &&
   (GetShortPathName(szFile,szFile,MAX_PATH)!=0))
  {
	lstrcpy(szCmd,L"/c del ");
	lstrcat(szCmd,szFile);
	lstrcat(szCmd,L" >> NUL");
	lstrcat(szCmd,L"pause");
  if((GetEnvironmentVariable(L"ComSpec",szFile,MAX_PATH)!=0) &&
   ((INT)ShellExecute(0,0,szFile,szCmd,0,SW_SHOW)>32))
  return TRUE;
}
  return FALSE;
}

// END OF UNIT TWO

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if (SET->Visible==false) {
  Form1->Height = 600;
  SET->Visible = true;
 } else {
  Form1->Height = 298;
  SET->Visible = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimeOutTimer(TObject *Sender)
{
// EthernetCheck();
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
 TI->Visible = false;
 WindowState = wsNormal;
 ShowWindow(Form1->Handle,SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 Ini->EraseSection("Debug");
 Ini->UpdateFile();
 Ini->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RestartTimer(TObject *Sender)
{
 Restart->Enabled = false;
 Button1->Click();
 Restart->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RESPTimer(TObject *Sender)
{
 Ini->WriteString("Debug","WS",IntToStr(rand()+1));
}
//---------------------------------------------------------------------------

