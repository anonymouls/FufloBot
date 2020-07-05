//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SHDocVw_OCX.h"
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *Im2;
	TButton *Button2;
	TImage *Im3;
	TTimer *WT;
	TImage *Im4;
	TIdHTTP *HTTP;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TButton *addone;
	TButton *clean;
	TButton *CheckIN;
	TButton *History;
	TButton *LastO;
	TGroupBox *Zone;
	TLabel *TL;
	TLabel *TT;
	TLabel *WD;
	TLabel *HH;
	TLabel *STA;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit2;
	TEdit *Edit1;
	TButton *addwz;
	TButton *chat;
	TButton *balan;
	TButton *redlock;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TTimer *Timer5;
	TImage *Im;
	TLabel *STATIC1;
	TLabel *STATIC2;
	TLabel *STATIC3;
	TLabel *STATIC4;
	TGroupBox *SET;
	TImage *Image1;
	TCheckBox *CheckBox1;
	TStatusBar *SB;
	TTimer *TimeOut;
	TTrayIcon *TI;
	TTimer *Restart;
	TTimer *RESP;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall WTTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall addoneClick(TObject *Sender);
	void __fastcall cleanClick(TObject *Sender);
	void __fastcall CheckINClick(TObject *Sender);
	void __fastcall btnwzClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall HistoryClick(TObject *Sender);
	void __fastcall LastOClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Timer5Timer(TObject *Sender);
	void __fastcall balanClick(TObject *Sender);
	void __fastcall redlockClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TimeOutTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall TIClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RestartTimer(TObject *Sender);
	void __fastcall RESPTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
