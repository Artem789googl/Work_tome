//---------------------------------------------------------------------------

#ifndef MainProgramH
#define MainProgramH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <DateUtils.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <SysUtils.hpp>
#include <vector>
#include <vcl.h>
#include <ComObj.hpp>
#include <vcl.h>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <map> // Для использования std::map
#include <utility> // Для std::pair, если используется
#include <Dialogs.hpp>
#pragma hdrstop

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *OtchetPanel;
	TLabel *Label_Panel;
	TButton *Button_EditData;
	TLabel *Main_label;
	TButton *Button_ReportData;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource2;
	TADOQuery *ADOQuery1;
	TPanel *ShowEditPanel;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label18;
	TDBGrid *DBGrid1;
	TComboBox *ComboBox1;
	TButton *Button_Update;
	TButton *Button_Add;
	TButton *Button_Delete;
	TEdit *SearchFam_Edit;
	TStringGrid *Table;
	TEdit *Edit1;
	TSaveDialog *SaveDialog1;
	TRadioGroup *RadioGroup1;
	TLabel *Label1;
	TDateTimePicker *DateTimePicker1;
	TButton *CreateOtchet_Button;
	TLabel *Lable4;
	TPanel *AddData_Panel;
	TPanel *Sotrudnik_Panel;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Fam_Edit;
	TEdit *Imya_Edit;
	TEdit *Otch_Edit;
	TCalendarPicker *Calendar;
	TComboBox *Dolzh_Combobox;
	TButton *AddSotr_Button;
	TButton *ClosePanelAdd_Button;
	TPanel *Dolzhnost_Panel;
	TLabel *Label8;
	TLabel *Label19;
	TEdit *Dolzhn_Edit;
	TButton *AddDolzh_Button;
	TDBGrid *DBGrid2;
	TPanel *InfoSotr_Panel;
	TLabel *Label20;
	TButton *SaveDate_Button;
	TCalendarPicker *DateEnd_Calendar;
	TCalendarPicker *DateStart_Calendar;
	TComboBox *Status_ComboBox;
	TLabel *Label17;
	TLabel *ImyaLabel;
	TLabel *FamLabel;
	TLabel *DolzhLabel;
	TLabel *Label16;
	TLabel *Label15;
	TLabel *DataNachLabel;
	TLabel *OtchestvoLabel;
	TButton *Edit_button;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *Excel1;
	TButton *Button_Admin;
	TPanel *AdminPanel;
	TLabel *Label9;
	TButton *AddUser_Button;
	TDBGrid *DBGrid3;
	TPanel *AddUserPanel;
	TLabel *AddUser_Label;
	TLabel *Login_Label;
	TLabel *Password_Label;
	TLabel *RepeatPasswordPanel;
	TEdit *Login_Edit;
	TEdit *Password_Edit;
	TEdit *RepeatPassword_Edit;
	TButton *AddUserPanel_Button;
	TComboBox *RoleCombobox;
	TLabel *Role_Label;
	TLabel *Error_Label;
	TButton *EditUser_Button;
	TButton *EditUserOnPanel_Button;
	TButton *DeleteUser_Button;
	TButton *ExitAccount_Button;
	TDataSource *DataSource1;
	TADOQuery *ADOQuery2;
	TComboBox *Sort_Combobox;
	TLabel *Sort_Label;
	TLabel *ResultLabel;
	TLabel *RestLabel;
	TLabel *SickLabel;
	TPanel *Change_Panel;
	TButton *OpenCgPas_Button;
	TLabel *Account_Label;
	TLabel *User_Label;
	TLabel *ChPas_Label;
	TLabel *PasswordAcc_Label;
	TLabel *Label10;
	TEdit *PassAcc_Edit;
	TEdit *RepPass_Edit;
	TButton *SavePass_Button;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button_UpdateClick(TObject *Sender);
	void __fastcall DBGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button_AddClick(TObject *Sender);
	void __fastcall SearchFam_EditChange(TObject *Sender);
	void __fastcall Button_DeleteClick(TObject *Sender);
	void __fastcall CreateOtchet_ButtonClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall TableMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ClosePanelAdd_ButtonClick(TObject *Sender);
	void __fastcall AddSotr_ButtonClick(TObject *Sender);
	void __fastcall AddDolzh_ButtonClick(TObject *Sender);
	void __fastcall Button_EditDataClick(TObject *Sender);
	void __fastcall Button_ReportDataClick(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall Edit_buttonClick(TObject *Sender);
	void __fastcall SaveDate_ButtonClick(TObject *Sender);
	void __fastcall DateEnd_CalendarChange(TObject *Sender);
	void __fastcall Word1Click(TObject *Sender);
	void __fastcall Button_AdminClick(TObject *Sender);
	void __fastcall AddUser_ButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AddUserPanel_ButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EditUserOnPanel_ButtonClick(TObject *Sender);
	void __fastcall DBGrid3CellClick(TColumn *Column);
	void __fastcall EditUser_ButtonClick(TObject *Sender);
	void __fastcall DeleteUser_ButtonClick(TObject *Sender);
	void __fastcall ExitAccount_ButtonClick(TObject *Sender);
	void __fastcall Sort_ComboboxChange(TObject *Sender);
	void __fastcall TableDblClick(TObject *Sender);
	void __fastcall ButtonAccCgPassDataClick(TObject *Sender);
	void __fastcall ButtonSavePasswordClick(TObject *Sender);
private:	// User declarations
	void __fastcall UpdateTableData();
	bool __fastcall CheckPassword(AnsiString Password, AnsiString RepeatPassword);
	bool IsFormed = false;
	int SelectedRow = -1; // Индекс выбранной строки
	int SelectedID = -1;  // ID выбранного сотрудника

	int SelectecUserID = -1; //ID выбранного поьзователя
	bool isEdit = false; //Режим работы с пользователям

	AnsiString SortText;//Текст для сортировки



	void __fastcall OptimizeColumnWidths(TDBGrid *Grid, TADOQuery *Query); //Метод для универсального размещение размеров колонок
public:		// User declarations
	AnsiString TextUsers;
	__fastcall TMainForm(TComponent* Owner);
    AnsiString RoleUser;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
