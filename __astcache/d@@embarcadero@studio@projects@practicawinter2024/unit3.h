//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <string>
//---------------------------------------------------------------------------
class TDateForm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TComboBox *ComboBox1;
	TDataSource *DataSource1;
	TButton *Button1;
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TDateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDateForm *DateForm;
//---------------------------------------------------------------------------
#endif
