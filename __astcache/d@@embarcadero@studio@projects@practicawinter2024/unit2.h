//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <DateUtils.hpp>
#include <Vcl.Samples.Calendar.hpp>
//---------------------------------------------------------------------------
class TEditForm : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TPageControl *PageControl1;
	TDBGrid *DBGrid1;
	TTabSheet *TabSheet1;
	TADOQuery *ADOQuery1;
	TComboBox *ComboBox1;
	TADOTable *ADOTable1;
	TButton *Button_Update;
	TButton *BackButton;
	TButton *Button_Add;
	TButton *Button_Delete;
	TPanel *Sotrudnik_Panel;
	TLabel *Label1;
	TEdit *Fam_Edit;
	TEdit *Imya_Edit;
	TEdit *Otch_Edit;
	TCalendarPicker *Calendar;
	TComboBox *Dolzh_Combobox;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *AddSotr_Button;
	TPanel *AddData_Panel;
	TButton *ClosePanelAdd_Button;
	TPanel *Dolzhnost_Panel;
	TLabel *Label7;
	TEdit *Dolzhn_Edit;
	TLabel *Label8;
	TButton *AddDolzh_Button;
	TDBGrid *DBGrid2;
	TTabSheet *TabSheet2;
	TDataSource *DataSource2;
	TLabel *Label9;
	TComboBox *Fam_ComboBox;
	TComboBox *Imya_ComboBox;
	TComboBox *Otch_ComboBox;
	TComboBox *Date_ComboBox;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TComboBox *Status_ComboBox;
	TLabel *Label15;
	TCalendarPicker *DateStart_Calendar;
	TCalendarPicker *DateEnd_Calendar;
	TLabel *Label16;
	TLabel *Label17;
	TButton *SaveDate_Button;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button_UpdateClick(TObject *Sender);
	void __fastcall DBGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall Button_AddClick(TObject *Sender);
	void __fastcall AddSotr_ButtonClick(TObject *Sender);
	void __fastcall ClosePanelAdd_ButtonClick(TObject *Sender);
	void __fastcall AddDolzh_ButtonClick(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall Button_DeleteClick(TObject *Sender);
	void __fastcall UpdateTableData();
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TabSheet2Show(TObject *Sender);
	void __fastcall Fam_ComboBoxChange(TObject *Sender);
	void __fastcall Otch_ComboBoxChange(TObject *Sender);
	void __fastcall Imya_ComboBoxChange(TObject *Sender);
	void __fastcall Date_ComboBoxChange(TObject *Sender);
	void __fastcall SaveDate_ButtonClick(TObject *Sender);
private:	// User declarations
        TDateTime StartDate;
    	TDateTime EndDate;
public:		// User declarations
	__fastcall TEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditForm *EditForm;
//---------------------------------------------------------------------------
#endif
