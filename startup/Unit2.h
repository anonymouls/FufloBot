//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *addone;
	TButton *clean;
	TButton *CheckIN;
	TButton *History;
	TButton *LastO;
	TGroupBox *Zone;
	TLabel *Label1;
	TLabel *Label2;
	TButton *OKBTN;
	TLabel *Label3;
	TTimer *Timer1;
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label4;
	TEdit *Edit4;
	TTimer *Timer3;
	TImage *Im;
	TImage *Image1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label5;
	TTimer *Timer2;
	TButton *Button4;
	TTimer *Timer4;
	void __fastcall OKBTNClick(TObject *Sender);
	void __fastcall addoneClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cleanClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall CheckINClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HistoryClick(TObject *Sender);
	void __fastcall LastOClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
 //	void Execute(TImage * Image,int L ,int T,int R,int B);
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
