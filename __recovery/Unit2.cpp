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

		if(tableName == "Сотрудники"){
			tableName = "sotrudnuk";
			SQLquery = "SELECT id_sotrudnik as 'Номер сотрудника', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Название' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost";
		}

		if(tableName == "Должности"){
			tableName = "dolzhnost";
			 SQLquery = "SELECT id_dolzhnost as 'Номер должности',  nazvanie as 'Название' FROM dolzhnost";
		}

		ADOTable1->TableName = tableName;



		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();

		DataSource1->DataSet = ADOQuery1;
        for (int i = 0; i < DBGrid1->Columns->Count; i++) {
			DBGrid1->Columns->Items[i]->Width = 150; // Уменьшаем ширину всех столбцов
		}
	} catch (const Exception &e) {
		ShowMessage("Ошибка при загрузке таблиц: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Button_UpdateClick(TObject *Sender)
{
    try {
        // Показываем окно подтверждения
        int userResponse = MessageDlg("Вы точно хотите обновить данные?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
        // Если пользователь нажал "Да"
        if (userResponse == mrYes) {
            if (ADOQuery1->State == dsEdit || ADOQuery1->State == dsInsert) {
                ADOQuery1->Post(); // Фиксируем изменения
                ADOQuery1->UpdateBatch(arAll); // Отправляем изменения в базу
                ShowMessage("Данные успешно обновлены!");
            } else {
                ShowMessage("Нет изменений для сохранения.");
            }
        } else {
			ShowMessage("Обновление данных отменено.");
		}
	} catch (const Exception &e) {
		ShowMessage("Ошибка при обновлении данных: " + e.Message);
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
		if(ComboBox1->Text == "Сотрудники"){
			AddData_Panel->Visible = true;
			Sotrudnik_Panel->Visible = true;

			ADOQuery1->SQL->Clear();

			// Устанавливаем текст запроса
			ADOQuery1->SQL->Text = "SELECT * FROM univercity.dolzhnost;";
			ADOQuery1->Open(); // Выполняем запрос
			// Очищаем ComboBox перед добавлением данных
			Dolzh_Combobox->Items->Clear();
			// Перебираем строки результата и добавляем их в ComboBox
			while (!ADOQuery1->Eof) {
				String nazvanie = ADOQuery1->FieldByName("nazvanie")->AsString;
				Dolzh_Combobox->Items->Add(nazvanie); // Добавляем название должности
				ADOQuery1->Next(); // Переходим к следующей строке
			}

            ADOQuery1->Close();
		}
		else if(ComboBox1->Text == "Должности"){
			AddData_Panel->Visible = true;
            Dolzhnost_Panel->Visible = true;
		}

	}else{
		ShowMessage("Нужно выбрать таблицы для работы");
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::AddSotr_ButtonClick(TObject *Sender)
{
	if((Fam_Edit->GetTextLen() < 0) or (Imya_Edit->GetTextLen() < 0) or
	(Dolzh_Combobox->ItemIndex == -1) or (Calendar->IsEmpty)){
		ShowMessage("Не все поля заполнены");
	}else{

		try{

			int idDolzhnost = 0;
			AnsiString tableName = ComboBox1->Text;



			//Поиск id должности
			ADOQuery1->SQL->Clear();
			ADOQuery1->Close();

			ADOQuery1->SQL->Text = "SELECT id_dolzhnost FROM dolzhnost WHERE nazvanie = '" + Dolzh_Combobox->Text + "'";
			ADOQuery1->Open();
			if (!ADOQuery1->Eof) {
				idDolzhnost = ADOQuery1->FieldByName("id_dolzhnost")->AsInteger; // Сохраняем в переменную
			} else {
                return;
			}

			//Добавление сотрудника
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
			ADOQuery1->Close(); // Закрываем предыдущий запрос
			ADOQuery1->SQL->Text = "SELECT id_sotrudnik as 'Номер сотрудника', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Название' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost"; // Новый запрос для обновления
			ADOQuery1->Open(); // Выполняем запрос
			DataSource1->DataSet = ADOQuery1;
			ComboBox1->Text = "Сотрудники";

			for (int i = 0; i < DBGrid1->Columns->Count; i++) {
				DBGrid1->Columns->Items[i]->Width = 150; // Уменьшаем ширину всех столбцов
			}
			ShowMessage("Запись успешно добавлена и таблица обновлена.");

		}catch (const Exception &e){
            ShowMessage("Ошибка при добавление данных: " + e.Message);
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
        // Получаем текст из Edit
		AnsiString  nazvanie = Dolzhn_Edit->Text;

        // Проверяем, что текст не пустой
        if (nazvanie.IsEmpty()) {
            ShowMessage("Название должности не может быть пустым!");
            return;
        }

        // SQL-запрос для проверки существования записи
        ADOQuery1->Close();
		ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM dolzhnost WHERE nazvanie = '" + nazvanie + "'";
		ADOQuery1->Open();

        // Получаем результат
        int count = ADOQuery1->FieldByName("Count")->AsInteger;
        ADOQuery1->Close();

        if (count > 0) {
			ShowMessage("Такая должность уже существует!");
        } else {
            // SQL-запрос для добавления записи
			ADOQuery1->SQL->Text = "INSERT INTO dolzhnost (nazvanie) VALUES ('" + nazvanie + "')";
            ADOQuery1->ExecSQL();

            ShowMessage("Должность успешно добавлена!");
		}



		ADOQuery1->SQL->Clear();
		ADOQuery1->Close(); // Закрываем предыдущий запрос
		ADOQuery1->SQL->Text = "SELECT id_dolzhnost as 'Номер должности',  nazvanie as 'Название' FROM dolzhnost"; // Новый запрос для обновления
		ADOQuery1->Open(); // Выполняем запрос
		DataSource1->DataSet = ADOQuery1;
    }
    catch (const Exception &e) {
        ShowMessage("Ошибка: " + e.Message);
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
        // Проверяем, есть ли записи в DBGrid1
        if (ADOQuery1->RecordCount == 0) {
			ShowMessage("Нет записей для удаления!");
            return;
        }

        // Уточняем, действительно ли пользователь хочет удалить запись
        if (MessageDlg("Вы действительно хотите удалить выбранную запись?",
                       mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
            
            // Получаем выбранную строку и значение ключевого поля
			int id = -1;
			if (ComboBox1->Text == "Сотрудники") {
				id = ADOQuery1->FieldByName("Номер сотрудника")->AsInteger;
			}else
			if (ComboBox1->Text == "Должности") {
			   id = ADOQuery1->FieldByName("Номер должности")->AsInteger; 
			}

			if (id == -1) {
				ShowMessage("Нет записей для удаления!");
				return;	
			}

            // Формируем запрос на удаление в зависимости от выбранного значения ComboBox1
            ADOQuery1->Close();
            if (ComboBox1->Text == "Должности") {
                ADOQuery1->SQL->Text = "DELETE FROM dolzhnost WHERE id_dolzhnost = :id";
            } else if (ComboBox1->Text == "Сотрудники") {
                ADOQuery1->SQL->Text = "DELETE FROM sotrudnuk WHERE id_sotrudnik = :id";
            } else {
                ShowMessage("Неизвестный выбор в ComboBox!");
                return;
            }

            // Подставляем значение id в запрос
            ADOQuery1->Parameters->ParamByName("id")->Value = id;

            // Выполняем запрос
            ADOQuery1->ExecSQL();

            // Обновляем таблицу, чтобы отобразить изменения
            UpdateTableData();

            ShowMessage("Запись успешно удалена!");
        }
    }
    catch (const Exception &e) {
        ShowMessage("Ошибка при удалении записи: " + e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::UpdateTableData()
{
    try {
        // Закрываем предыдущий запрос
        ADOQuery1->Close();

        // Формируем запрос в зависимости от значения ComboBox1
        if (ComboBox1->Text == "Должности") {
            ADOQuery1->SQL->Text = 
                "SELECT id_dolzhnost as 'Номер должности', nazvanie as 'Название' FROM dolzhnost";
        } else if (ComboBox1->Text == "Сотрудники") {
            ADOQuery1->SQL->Text = 
				"SELECT id_sotrudnik as 'Номер сотрудника', familiya as 'Фамилия', imya as 'Имя', "
                "otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', "
                "nazvanie as 'Название' "
                "FROM sotrudnuk JOIN dolzhnost ON id_dolzhnost = dolzhnost_id_dolzhnost";
        } else {
            ShowMessage("Неизвестный выбор в ComboBox!");
            return;
		}

		// Открываем обновлённый запрос
		ADOQuery1->Open();
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при обновлении данных: " + e.Message);
	}
}

void __fastcall TEditForm::Calendar1Click(TObject *Sender)
{
 // Получаем текущую выбранную дату
    TDateTime selectedDate = Calendar1->CalendarDate();

    // Если начальная дата не задана, задаем её
    if (StartDate == TDateTime()) 
    {
        StartDate = selectedDate; 
    }
    else
    {
	// Если начальная дата задана, задаем конечную дату
	EndDate = selectedDate;

	// Если конечная дата меньше начальной, меняем их местами
	if (EndDate < StartDate)
	{
		TDateTime temp = StartDate;
		StartDate = EndDate;
		EndDate = temp;
	}
}
//---------------------------------------------------------------------------
