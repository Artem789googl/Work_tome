//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <iostream>
#pragma hdrstop

#include "Unit2.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditForm *EditForm;
//---------------------------------------------------------------------------
__fastcall TEditForm::TEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEditForm::FormCreate(TObject *Sender)
{
	ADOConnection1->Connected = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::FormDestroy(TObject *Sender)
{
	ADOConnection1->Connected = false;
}
//---------------------------------------------------------------------------
void __fastcall TEditForm::FormClose(TObject *Sender, TCloseAction &Action)
{
		Application->Terminate();	
}
//---------------------------------------------------------------------------



void __fastcall TEditForm::ComboBox1Change(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	AnsiString tableName = ComboBox1->Text;
	AnsiString SQLquery;
	try{

		ADOQuery1->Close();

		if(tableName == "����������"){
			tableName = "sotrudnuk";
			SQLquery = "SELECT id_sotrudnik as '����� ����������', familiya as '�������', imya as '���', otchestvo as '��������', data_nachalo_raboty as '���� ������ ������', nazvanie as '��������' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost";
		}

		if(tableName == "���������"){
			tableName = "dolzhnost";
			 SQLquery = "SELECT id_dolzhnost as '����� ���������',  nazvanie as '��������' FROM dolzhnost";
		}

		ADOTable1->TableName = tableName;



		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();

		DataSource1->DataSet = ADOQuery1;
        for (int i = 0; i < DBGrid1->Columns->Count; i++) {
			DBGrid1->Columns->Items[i]->Width = 150; // ��������� ������ ���� ��������
		}
	} catch (const Exception &e) {
		ShowMessage("������ ��� �������� ������: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Button_UpdateClick(TObject *Sender)
{
    try {
        // ���������� ���� �������������
        int userResponse = MessageDlg("�� ����� ������ �������� ������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
        // ���� ������������ ����� "��"
        if (userResponse == mrYes) {
            if (ADOQuery1->State == dsEdit || ADOQuery1->State == dsInsert) {
                ADOQuery1->Post(); // ��������� ���������
                ADOQuery1->UpdateBatch(arAll); // ���������� ��������� � ����
                ShowMessage("������ ������� ���������!");
            } else {
                ShowMessage("��� ��������� ��� ����������.");
            }
        } else {
			ShowMessage("���������� ������ ��������.");
		}
	} catch (const Exception &e) {
		ShowMessage("������ ��� ���������� ������: " + e.Message);
    }

	Button_Update->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
	Button_Update->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::BackButtonClick(TObject *Sender)
{
		EditForm->Hide();
		MainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Button_AddClick(TObject *Sender)
{

	if(ComboBox1->ItemIndex > -1){
		if(ComboBox1->Text == "����������"){
			AddData_Panel->Visible = true;
			Sotrudnik_Panel->Visible = true;

			ADOQuery1->SQL->Clear();

			// ������������� ����� �������
			ADOQuery1->SQL->Text = "SELECT * FROM univercity.dolzhnost;";
			ADOQuery1->Open(); // ��������� ������
			// ������� ComboBox ����� ����������� ������
			Dolzh_Combobox->Items->Clear();
			// ���������� ������ ���������� � ��������� �� � ComboBox
			while (!ADOQuery1->Eof) {
				String nazvanie = ADOQuery1->FieldByName("nazvanie")->AsString;
				Dolzh_Combobox->Items->Add(nazvanie); // ��������� �������� ���������
				ADOQuery1->Next(); // ��������� � ��������� ������
			}

            ADOQuery1->Close();
		}
		else if(ComboBox1->Text == "���������"){
			AddData_Panel->Visible = true;
            Dolzhnost_Panel->Visible = true;
		}

	}else{
		ShowMessage("����� ������� ������� ��� ������");
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::AddSotr_ButtonClick(TObject *Sender)
{
	if((Fam_Edit->GetTextLen() < 0) or (Imya_Edit->GetTextLen() < 0) or
	(Dolzh_Combobox->ItemIndex == -1) or (Calendar->IsEmpty)){
		ShowMessage("�� ��� ���� ���������");
	}else{

		try{

			int idDolzhnost = 0;
			AnsiString tableName = ComboBox1->Text;



			//����� id ���������
			ADOQuery1->SQL->Clear();
			ADOQuery1->Close();

			ADOQuery1->SQL->Text = "SELECT id_dolzhnost FROM dolzhnost WHERE nazvanie = '" + Dolzh_Combobox->Text + "'";
			ADOQuery1->Open();
			if (!ADOQuery1->Eof) {
				idDolzhnost = ADOQuery1->FieldByName("id_dolzhnost")->AsInteger; // ��������� � ����������
			} else {
                return;
			}

			//���������� ����������
			ADOQuery1->SQL->Clear();
			String query = "INSERT INTO sotrudnuk (familiya, imya, otchestvo, data_nachalo_raboty, dolzhnost_id_dolzhnost) VALUES ('"
               + Fam_Edit->Text + "', '"
               + Imya_Edit->Text + "', '"
               + Otch_Edit->Text + "', '"
			   + FormatDateTime("yyyy-mm-dd", Calendar->Date) + "', "
               + IntToStr(idDolzhnost) + ");";
			ADOQuery1->SQL->Text = query;
			ADOQuery1->ExecSQL();

			ADOQuery1->SQL->Clear();
			ADOQuery1->Close(); // ��������� ���������� ������
			ADOQuery1->SQL->Text = "SELECT id_sotrudnik as '����� ����������', familiya as '�������', imya as '���', otchestvo as '��������', data_nachalo_raboty as '���� ������ ������', nazvanie as '��������' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost"; // ����� ������ ��� ����������
			ADOQuery1->Open(); // ��������� ������
			DataSource1->DataSet = ADOQuery1;
			ComboBox1->Text = "����������";

			for (int i = 0; i < DBGrid1->Columns->Count; i++) {
				DBGrid1->Columns->Items[i]->Width = 150; // ��������� ������ ���� ��������
			}
			ShowMessage("������ ������� ��������� � ������� ���������.");

		}catch (const Exception &e){
            ShowMessage("������ ��� ���������� ������: " + e.Message);
		}

    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::ClosePanelAdd_ButtonClick(TObject *Sender)
{
	AddData_Panel->Visible = false;
	Sotrudnik_Panel->Visible = false;
	Dolzhnost_Panel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::AddDolzh_ButtonClick(TObject *Sender)
{
	try {
        // �������� ����� �� Edit
		AnsiString  nazvanie = Dolzhn_Edit->Text;

        // ���������, ��� ����� �� ������
        if (nazvanie.IsEmpty()) {
            ShowMessage("�������� ��������� �� ����� ���� ������!");
            return;
        }

        // SQL-������ ��� �������� ������������� ������
        ADOQuery1->Close();
		ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM dolzhnost WHERE nazvanie = '" + nazvanie + "'";
		ADOQuery1->Open();

        // �������� ���������
        int count = ADOQuery1->FieldByName("Count")->AsInteger;
        ADOQuery1->Close();

        if (count > 0) {
			ShowMessage("����� ��������� ��� ����������!");
        } else {
            // SQL-������ ��� ���������� ������
			ADOQuery1->SQL->Text = "INSERT INTO dolzhnost (nazvanie) VALUES ('" + nazvanie + "')";
            ADOQuery1->ExecSQL();

            ShowMessage("��������� ������� ���������!");
		}



		ADOQuery1->SQL->Clear();
		ADOQuery1->Close(); // ��������� ���������� ������
		ADOQuery1->SQL->Text = "SELECT id_dolzhnost as '����� ���������',  nazvanie as '��������' FROM dolzhnost"; // ����� ������ ��� ����������
		ADOQuery1->Open(); // ��������� ������
		DataSource1->DataSet = ADOQuery1;
    }
    catch (const Exception &e) {
        ShowMessage("������: " + e.Message);
    }

}
//---------------------------------------------------------------------------

void __fastcall TEditForm::DBGrid1CellClick(TColumn *Column)
{
	Button_Delete->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Button_DeleteClick(TObject *Sender)
{
	     try {
        // ���������, ���� �� ������ � DBGrid1
        if (ADOQuery1->RecordCount == 0) {
			ShowMessage("��� ������� ��� ��������!");
            return;
        }

        // ��������, ������������� �� ������������ ����� ������� ������
        if (MessageDlg("�� ������������� ������ ������� ��������� ������?",
                       mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            
            // �������� ��������� ������ � �������� ��������� ����
			int id = -1;
			if (ComboBox1->Text == "����������") {
				id = ADOQuery1->FieldByName("����� ����������")->AsInteger;
			}else
			if (ComboBox1->Text == "���������") {
			   id = ADOQuery1->FieldByName("����� ���������")->AsInteger; 
			}

			if (id == -1) {
				ShowMessage("��� ������� ��� ��������!");
				return;	
			}

            // ��������� ������ �� �������� � ����������� �� ���������� �������� ComboBox1
            ADOQuery1->Close();
            if (ComboBox1->Text == "���������") {
                ADOQuery1->SQL->Text = "DELETE FROM dolzhnost WHERE id_dolzhnost = :id";
            } else if (ComboBox1->Text == "����������") {
                ADOQuery1->SQL->Text = "DELETE FROM sotrudnuk WHERE id_sotrudnik = :id";
            } else {
                ShowMessage("����������� ����� � ComboBox!");
                return;
            }

            // ����������� �������� id � ������
            ADOQuery1->Parameters->ParamByName("id")->Value = id;

            // ��������� ������
            ADOQuery1->ExecSQL();

            // ��������� �������, ����� ���������� ���������
            UpdateTableData();

            ShowMessage("������ ������� �������!");
        }
    }
    catch (const Exception &e) {
        ShowMessage("������ ��� �������� ������: " + e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::UpdateTableData()
{
    try {
        // ��������� ���������� ������
        ADOQuery1->Close();

        // ��������� ������ � ����������� �� �������� ComboBox1
        if (ComboBox1->Text == "���������") {
            ADOQuery1->SQL->Text = 
                "SELECT id_dolzhnost as '����� ���������', nazvanie as '��������' FROM dolzhnost";
        } else if (ComboBox1->Text == "����������") {
            ADOQuery1->SQL->Text = 
				"SELECT id_sotrudnik as '����� ����������', familiya as '�������', imya as '���', "
                "otchestvo as '��������', data_nachalo_raboty as '���� ������ ������', "
                "nazvanie as '��������' "
                "FROM sotrudnuk JOIN dolzhnost ON id_dolzhnost = dolzhnost_id_dolzhnost";
        } else {
            ShowMessage("����������� ����� � ComboBox!");
            return;
		}

		// ��������� ���������� ������
		ADOQuery1->Open();
	}
	catch (const Exception &e) {
		ShowMessage("������ ��� ���������� ������: " + e.Message);
	}
}

void __fastcall TEditForm::Calendar1Click(TObject *Sender)
{
    // ���� ��������� ���� �� �����������, ������������� � ��� ���������
    if (StartDate.IsNull())
    {
        StartDate = Calendar1->SelectedDate;
    }
    else
    {
        // ���� ��������� ���� ��� �����������, ������������� �������� ����
        EndDate = Calendar1->SelectedDate;

        // ���� �������� ���� ������ ���������, ������ �� �������
        if (EndDate < StartDate)
        {
            TDateTime temp = StartDate;
            StartDate = EndDate;
            EndDate = temp;
        }
    }

    // ����� ���� ��� ��� ���� �������, �������� ��������
    if (!StartDate.IsNull() && !EndDate.IsNull())
    {
        Calendar1->ClearSelection(); // ������� ������� ����� ���������� ���������
        Calendar1->SelectRange(StartDate, EndDate); // �������� ��������
    }
}
//---------------------------------------------------------------------------
