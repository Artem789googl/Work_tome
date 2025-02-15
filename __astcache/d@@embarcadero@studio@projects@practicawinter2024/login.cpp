//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainProgram.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEnter *Enter;
//---------------------------------------------------------------------------
__fastcall TEnter::TEnter(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TEnter::EnterButtonClick(TObject *Sender)
{
	MainForm->ADOConnection1->Connected = true;

	MainForm->ADOQuery1->Close();
	MainForm->ADOQuery1->SQL->Text =  "Select role From users where login = '" + login_edit->Text + "' and password = MD5('" + pass_edit->Text + "')";

	try {
		MainForm->ADOQuery1->Open();

		if (!MainForm->ADOQuery1->IsEmpty()) {

			MainForm->RoleUser = MainForm->ADOQuery1->FieldByName("role")->AsString;
			Application->ShowMainForm = true;
			MainForm->TextUsers = login_edit->Text;
			login_edit->Clear();
			pass_edit->Clear();
            login_edit->SetFocus();
			Enter->Hide();
			MainForm->Show();
		} else {
			Error_Label->Caption = "Логин/Пароль введены неверно!";
		}
	} catch (Exception &e) {
		ShowMessage("Ошибка выполнения запроса: " + e.Message);
	}

	
}
//---------------------------------------------------------------------------



void __fastcall TEnter::login_editKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13){
		pass_edit->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TEnter::pass_editKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13){
		EnterButton->OnClick(Sender);
	}
}
//---------------------------------------------------------------------------

