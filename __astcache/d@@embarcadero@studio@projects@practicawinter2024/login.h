//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TEnter : public TForm
{
__published:	// IDE-managed Components
	TLabel *EnterLabel;
	TLabel *LoginLabel;
	TEdit *login_edit;
	TLabel *PasswordLabel;
	TEdit *pass_edit;
	TButton *EnterButton;
	TLabel *Error_Label;
	void __fastcall EnterButtonClick(TObject *Sender);
	void __fastcall login_editKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall pass_editKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TEnter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEnter *Enter;
//---------------------------------------------------------------------------
#endif
