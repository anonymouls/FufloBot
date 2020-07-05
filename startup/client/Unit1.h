//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdIcmpClient.hpp>
#include <IdRawBase.hpp>
#include <IdRawClient.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TIdFTP *FTP;
	TButton *Button1;
	TButton *Button2;
	TTimer *Timer1;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
	TButton *Button3;
	TGroupBox *GroupBox1;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CheckBox1;
	TButton *Button6;
	TLabel *Label3;
	TTimer *Timeout;
	TStatusBar *SB;
	TIdIcmpClient *Ping;
	TTrayIcon *TI;
	TEdit *Edit1;
	TButton *Button7;
	TButton *Button8;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall FTPDisconnected(TObject *Sender);
	void __fastcall TimeoutTimer(TObject *Sender);
	void __fastcall PingReply(TComponent *ASender, TReplyStatus * const AReplyStatus);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall TIClick(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
