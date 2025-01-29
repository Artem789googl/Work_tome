﻿/*
Программа: название программы: Work_Time:MainProgram.ccp
Практика УП.02
Тема «Учёт рабочего времени сотрудников университета»
Язык программирования: C++
Разработал: Шум Артём
Дата: 18.01.25
_____________________________________________________________
Задача: Создать главную форма которая будет отвечать за работу программу, сформировывать отчёт, добавлять, изменять и удалять сотрудников
_____________________________________________________________
Переменные, используемые в программе:
	IsFormed - переменная, которая отвечает можно ли мформировать отчёт;
	SelectedRow - индекс выбранной строки;
	SelectedID - переменная, которая хранит ID выбранного сотрудника;
	SelectecUserID - переменная, которая хранит, ID выбранного поьзователя;
	isEdit - переменная, которая хранит режим работы с пользователям;
	SortText - переменная, которая хранит текст для сортировки;

Процедуры:
	UpdateTableData - для обновление таблицы на вкладке "Просмотр и изменение данных"
	CheckPassword - возваращает true или false, если пароль верный или не верный;
	OptimizeColumnWidths - делает таблице универсальный вид.
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainProgram.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	Application->MainFormOnTaskBar = true;
	ADOConnection1->Connected = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
	ADOConnection1->Connected = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
		Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	/*
	  Число роли, если
	  Роль 0 - Администратор
	  Роль 1 - Пользователь
	*/
	int role = -1;



	if (RoleUser == "user") {
		role = 1;

	}

	if (RoleUser == "admin") {
		role = 0;
	}

	switch(role){
		case 0:
			Button_Admin->Visible = true;
			Button_Update->Visible = true;
			break;
		case 1:
			Button_Admin->Visible = false;
			Button_Add->Visible = false;
            Button_Delete->Visible = false;
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_EditDataClick(TObject *Sender)
{
	ShowEditPanel->Visible = true;
	OtchetPanel->Visible = false;
	AdminPanel->Visible = false;
	Change_Panel->Visible = false;

	ADOQuery1->Close();

    	SearchFam_Edit->Visible = false;
	Label18->Visible = false;
	Sort_Label->Visible = false;
	Sort_Combobox->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_ReportDataClick(TObject *Sender)
{
	OtchetPanel->Visible = true;
	ShowEditPanel->Visible = false;
	AdminPanel->Visible = false;
	Change_Panel->Visible = false;

	Label1->Visible = false;
	Edit1->Visible = false;



	DateTimePicker1->Date=Now().CurrentDate();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonAccCgPassDataClick(TObject *Sender)
{
	OtchetPanel->Visible = false;
	ShowEditPanel->Visible = false;
	AdminPanel->Visible = false;
	Change_Panel->Visible = true;
     User_Label->Caption = "Логин: " + TextUsers;
	Label1->Visible = false;
	Edit1->Visible = false;


}
//---------------------------------------------------------------------------
 void __fastcall TMainForm::Button_AdminClick(TObject *Sender)
{
	OtchetPanel->Visible = false;
	ShowEditPanel->Visible = false;
	AdminPanel->Visible = true;
	Change_Panel->Visible = false;

	Label1->Visible = false;
	Edit1->Visible = false;

	AnsiString SQLquery;
	try{

		ADOQuery1->Close();

		SQLquery = "SELECT id_user as '№', login as 'Логин', `password` as 'Пароль', `role` as 'Роль' FROM univercity.users;";

		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();

		DataSource1->DataSet = ADOQuery1;
	}catch (const Exception &e) {
		ShowMessage("Ошибка при загрузке таблиц: " + e.Message);
	}

	for (int i = 1; i < DBGrid3->Columns->Count; i++) {
		DBGrid3->Columns->Items[i]->Width = 100; // Уменьшаем ширину всех столбцов
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonSavePasswordClick(TObject *Sender)
{

	bool isCheck = CheckPassword(PassAcc_Edit->Text, RepPass_Edit->Text);

	try{
		if (isCheck) {
			ADOQuery1->Close();
			ADOQuery1->SQL->Text = "Update users SET password = MD5('" + PassAcc_Edit->Text + "') where login = '"+ TextUsers + "'";
			ADOQuery1->ExecSQL();
			ShowMessage("Пароль сменён!");
			PassAcc_Edit->Clear();
            RepPass_Edit->Clear();
		}

	}catch (const Exception &e) {
		ShowMessage("Ошибка при сохранение пароля: " + e.Message);
	}


}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Форма с просмотром и изменения данных
//---------------------------------------------------------------------------
void __fastcall TMainForm::ComboBox1Change(TObject *Sender)
{
	SearchFam_Edit->Visible = false;
	Label18->Visible = false;
	Sort_Label->Visible = false;
	Sort_Combobox->Visible = false;
	SearchFam_Edit->Clear();
    SortText = "";
	Sort_Combobox->ItemIndex = -1;
    Sort_Combobox->Text = "Отсортировать";

	ADOQuery1->SQL->Clear();
	AnsiString tableName = ComboBox1->Text;
	AnsiString SQLquery;
	try{

		ADOQuery1->Close();

		if(tableName == "Сотрудники"){
			tableName = "sotrudnuk";
			SQLquery = "SELECT id_sotrudnik as '№', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Должность' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost order by id_sotrudnik";
			SearchFam_Edit->Visible = true;
			Sort_Label->Visible = true;
			Sort_Combobox->Visible = true;
			Label18->Visible = true;
		}

		if(tableName == "Должности"){
			tableName = "dolzhnost";
			 SQLquery = "SELECT id_dolzhnost as '№',  nazvanie as 'Должность' FROM dolzhnost";
		}



		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();

		DataSource1->DataSet = ADOQuery1;
		OptimizeColumnWidths(DBGrid1, ADOQuery1);
	} catch (const Exception &e) {
		ShowMessage("Ошибка при загрузке таблиц: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Sort_ComboboxChange(TObject *Sender)
{
	SortText = "order by ";
	AnsiString BySort = "";
	AnsiString SQLquery;
	switch(Sort_Combobox->ItemIndex){
		case 0:
			BySort = "id_sotrudnik ASC";
			break;
		case 1:
			BySort = "id_sotrudnik DESC";
			break;
		case 2:
			BySort = "familiya ASC";
			break;
		case 3:
			BySort = "familiya DESC";
			break;
		case 4:
			BySort = "imya ASC";
			break;
		case 5:
			BySort = "imya DESC";
			break;
		case 6:
			BySort = "otchestvo ASC";
			break;
		case 7:
			BySort = "otchestvo DESC";
			break;
		case 8:
			BySort = "data_nachalo_raboty ASC";
			break;
		case 9:
			BySort = "data_nachalo_raboty DESC";
			break;
	}
	SortText = SortText + BySort;
	ADOQuery1->Close();
	SQLquery = "SELECT id_sotrudnik as '№', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Должность' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost " + SortText;

	ADOQuery1->SQL->Text = SQLquery;

	ADOQuery1->Open();
	OptimizeColumnWidths(DBGrid1, ADOQuery1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit_buttonClick(TObject *Sender)
{
	try {
		if (SelectedRow == -1 || SelectedID == -1) {
			ShowMessage("Пожалуйста, выберите строку для изменения.");
			return;
		}
		// Открываем панель для редактирования
        AddData_Panel->Visible = true;
		InfoSotr_Panel->Visible = true;
		// Заполняем метки (Label) данными из выбранной строки
		FamLabel->Caption = "Фамилия: " + ADOQuery1->FieldByName("Фамилия")->AsString;
		ImyaLabel->Caption = "Имя: " + ADOQuery1->FieldByName("Имя")->AsString;
		OtchestvoLabel->Caption =  "Отчество: " + ADOQuery1->FieldByName("Отчество")->AsString;
		DataNachLabel->Caption = "Дата начала работы: " + ADOQuery1->FieldByName("Дата начало работы")->AsString;
		DolzhLabel->Caption = "Должность: " + ADOQuery1->FieldByName("Должность")->AsString;
	}
	catch (const Exception &e) {
        ShowMessage("Ошибка при изменении сотрудника: " + e.Message);
	}
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::DBGrid1CellClick(TColumn *Column)
{
	 try {
		// Получаем индекс выбранной строки
		SelectedRow = DBGrid1->DataSource->DataSet->RecNo - 1; // RecNo возвращает номер строки
		// Получаем ID выбранного сотрудника
		if (SelectedRow >= 0) {
			SelectedID = ADOQuery1->FieldByName("№")->AsInteger; // Берём ID из колонки "№"
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при выборе строки: " + e.Message);
	}
}
//---------------------------------------------------------------------------
 void __fastcall TMainForm::DateEnd_CalendarChange(TObject *Sender)
{
	try {

		TDateTime startDate = DateStart_Calendar->Date;
		TDateTime endDate = DateEnd_Calendar->Date;

		if (endDate < startDate) {
			ShowMessage("Ошибка: Дата конца не может быть меньше даты начала!");
			SaveDate_Button->Visible = false;

		}else{
            SaveDate_Button->Visible = true;
		}
	} catch (const Exception &e) {
		ShowMessage("Произошла ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SaveDate_ButtonClick(TObject *Sender)
{
	try {
		// Получаем значения из Label
		AnsiString familiya = FamLabel->Caption.SubString(10, FamLabel->Caption.Length() - 9); // Убираем "Фамилия: "
		AnsiString imya = ImyaLabel->Caption.SubString(6, ImyaLabel->Caption.Length() - 5);    // Убираем "Имя: "
		AnsiString otchestvo = OtchestvoLabel->Caption.SubString(11, OtchestvoLabel->Caption.Length() - 10); // Убираем "Отчество: "
		AnsiString dataNachalaRaboty = DataNachLabel->Caption.SubString(21, DataNachLabel->Caption.Length() - 20); // Убираем "Дата начала работы: "
		AnsiString status = Status_ComboBox->Text; // Статус берём из ComboBox
		AnsiString dataNachala = DateToStr(DateStart_Calendar->Date); // Дата начала режима
		AnsiString dataOkonchaniya = DateToStr(DateEnd_Calendar->Date); // Дата конца режима


		if (Status_ComboBox->ItemIndex == -1) {
			ShowMessage("Выберите статус");
			return;
		}

		// Форматируем даты для MySQL (YYYY-MM-DD)
		TDateTime dateStart = StrToDate(dataNachala);
		TDateTime dateEnd = StrToDate(dataOkonchaniya);
		int daysDiff = DaysBetween(dateStart, dateEnd) + 1;
		AnsiString formattedDataNachala = FormatDateTime("yyyy-mm-dd", dateStart);
		AnsiString formattedDataOkonchaniya = FormatDateTime("yyyy-mm-dd", dateEnd);
		TDateTime dateRaboty = StrToDate(dataNachalaRaboty);
		AnsiString formattedDataNachalaRaboty = FormatDateTime("yyyy-mm-dd", dateRaboty);

		// Находим ID сотрудника по фамилии, имени, отчеству и дате начала работы
		ADOQuery1->Close();
		ADOQuery1->SQL->Text =
			"SELECT id_sotrudnik FROM sotrudnuk WHERE familiya = '" + familiya +
			"' AND imya = '" + imya + "' AND (otchestvo = '" + otchestvo +
			"' OR otchestvo = '') AND data_nachalo_raboty = '" + formattedDataNachalaRaboty + "'";
		ADOQuery1->Open();

		if (ADOQuery1->RecordCount == 0) {
			ShowMessage("Сотрудник не найден!");
			return;
		}

		int sotrudnikID = ADOQuery1->FieldByName("id_sotrudnik")->AsInteger;
		int day = DayOf(dateStart);
		int year = YearOf(dateStart);
		int month = MonthOf(dateStart);
		TDateTime currentDate = dateStart; // Начальная дата
		while (currentDate <= dateEnd) {

			// Добавляем запись в таблицу rabochee_vremya
			ADOQuery1->Close();
			ADOQuery1->SQL->Text =
				"INSERT INTO rabochee_vremya (status, data_nachala, data_okonchaniya) VALUES ('" +
				status + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "')";
			ADOQuery1->ExecSQL();

			// Получаем ID последней вставленной записи (rabochee_vremya_id)
			ADOQuery1->Close();
			ADOQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS rabochee_vremya_id";
			ADOQuery1->Open();
			int rabocheeVremyaID = ADOQuery1->FieldByName("rabochee_vremya_id")->AsInteger;

			// Добавляем связь в таблицу sot_rab_vremya
			ADOQuery1->Close();
			ADOQuery1->SQL->Text =
				"INSERT INTO sot_rab_vremya (sotrudnuk_id_sotrudnik, rabochee_vremya_id) VALUES (" +
				IntToStr(sotrudnikID) + ", " + IntToStr(rabocheeVremyaID) + ")";
			ADOQuery1->ExecSQL();

			// Увеличиваем дату на 1 день
			currentDate = IncDay(currentDate, 1); // Это автоматически учитывает переход между месяцами и годами
		}



		ShowMessage("Данные успешно сохранены!");
		UpdateTableData();

		FamLabel->Caption = "Фамилия: ";
		ImyaLabel->Caption = "Имя: ";
		OtchestvoLabel->Caption = "Отчество: ";
		DataNachLabel->Caption = "Дата начала работы: ";
		DolzhLabel->Caption = "Должность: ";
		Status_ComboBox->ItemIndex = -1;
		Status_ComboBox->Text = "Выберите статус";
		AddData_Panel->Visible = true;
		AddData_Panel->Visible = false;
		InfoSotr_Panel->Visible = false;
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button_UpdateClick(TObject *Sender)
{
	AnsiString SQLquery;
	if (ComboBox1->ItemIndex > -1) {
		try {
			// Показываем окно подтверждения
			int userResponse = MessageDlg("Вы точно хотите обновить данные?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);
			// Если пользователь нажал "Да"
			if (userResponse == mrYes) {
				// Получаем текущую строку и значения
				int selectedRow = DBGrid1->DataSource->DataSet->RecNo; // Номер текущей строки
				if (selectedRow < 1) {
					ShowMessage("Выберите строку для обновления.");
					return;
				}

				AnsiString tableName = ComboBox1->Text;
				AnsiString updateQuery;
				AnsiString idValue;

				// Определяем таблицу и формируем запрос
				if (tableName == "Сотрудники") {
					tableName = "sotrudnuk";

					// Получаем значения для обновления
					AnsiString familiya = ADOQuery1->FieldByName("Фамилия")->AsString;
					AnsiString imya = ADOQuery1->FieldByName("Имя")->AsString;
					AnsiString otchestvo = ADOQuery1->FieldByName("Отчество")->AsString;
					AnsiString dataNachalo = ADOQuery1->FieldByName("Дата начало работы")->AsString;
					String formattedDateStart = FormatDateTime("yyyy-mm-dd", StrToDate(dataNachalo));
					idValue = ADOQuery1->FieldByName("№")->AsString;

					// Формируем запрос на обновление
					updateQuery = "UPDATE sotrudnuk SET familiya = '" + familiya +
								  "', imya = '" + imya +
								  "', otchestvo = '" + otchestvo +
								  "', data_nachalo_raboty = '" + formattedDateStart +
								  "' WHERE id_sotrudnik = " + idValue;

					SQLquery = "SELECT id_sotrudnik as '№', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Должность' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost order by id_sotrudnik";
				} else if (tableName == "Должности") {
					tableName = "dolzhnost";

					// Получаем значения для обновления
					AnsiString nazvanie = ADOQuery1->FieldByName("Должность")->AsString;
					idValue = ADOQuery1->FieldByName("№")->AsString;

					// Формируем запрос на обновление
					updateQuery = "UPDATE dolzhnost SET nazvanie = '" + nazvanie +
								  "' WHERE id_dolzhnost = " + idValue;

					SQLquery = "SELECT id_dolzhnost as '№',  nazvanie as 'Должность' FROM dolzhnost";
				} else {
					ShowMessage("Неизвестная таблица.");
					return;
				}

				// Выполняем запрос на обновление
				ADOQuery1->Close();
				ADOQuery1->SQL->Text = updateQuery;
				ADOQuery1->ExecSQL();

				//Запрос на отображение таблицы
				ADOQuery1->Close();
				ADOQuery1->SQL->Text = SQLquery;
				ADOQuery1->Open();
				DataSource1->DataSet = ADOQuery1;
				OptimizeColumnWidths(DBGrid1, ADOQuery1);
				ShowMessage("Данные успешно обновлены!");
			} else {
				ShowMessage("Обновление данных отменено.");
			}
		} catch (const Exception &e) {
			ShowMessage("Ошибка при обновлении данных: " + e.Message);
		}
	} else {
		ShowMessage("Нужно выбрать таблицы для работы.");
	}



}
//---------------------------------------------------------------------------
 void __fastcall TMainForm::OptimizeColumnWidths(TDBGrid *Grid, TADOQuery *Query) {
    try {
        for (int col = 0; col < Grid->Columns->Count; col++) {
            TField *field = Query->Fields->Fields[col];
            TColumn *column = Grid->Columns->Items[col];

            // Получаем ширину заголовка
            int maxWidth = Grid->Canvas->TextWidth(column->Title->Caption) + 10;

            // Проходим по всем строкам для поиска максимальной ширины
            Query->First(); // Переходим к началу данных
            while (!Query->Eof) {
                AnsiString text = field->AsString;
                int textWidth = Grid->Canvas->TextWidth(text) + 10; // Добавляем отступы
                if (textWidth > maxWidth) {
                    maxWidth = textWidth;
                }
                Query->Next();
            }

            // Устанавливаем рассчитанную ширину столбца
            column->Width = maxWidth;
        }
    } catch (const Exception &e) {
        ShowMessage("Ошибка при оптимизации ширины столбцов: " + e.Message);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
		Button_Update->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_AddClick(TObject *Sender)
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

void __fastcall TMainForm::SearchFam_EditChange(TObject *Sender)
{
    AnsiString familiya = SearchFam_Edit->Text;
	ADOQuery1->Close();
	String SQLquery = "SELECT id_sotrudnik as '№', familiya as 'Фамилия', imya as 'Имя', otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', nazvanie as 'Должность' FROM univercity.sotrudnuk join dolzhnost on id_dolzhnost = dolzhnost_id_dolzhnost where  familiya Like '" + familiya + "%' " + SortText;
	ADOQuery1->SQL->Text = SQLquery;
	ADOQuery1->Open();
	OptimizeColumnWidths(DBGrid1, ADOQuery1);

	DataSource1->DataSet = ADOQuery1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button_DeleteClick(TObject *Sender)
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
				id = ADOQuery1->FieldByName("№")->AsInteger;
			}else
			if (ComboBox1->Text == "Должности") {
			   id = ADOQuery1->FieldByName("№")->AsInteger;
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

void __fastcall TMainForm::UpdateTableData()
{
	try {
		// Закрываем предыдущий запрос
		ADOQuery1->Close();

		// Формируем запрос в зависимости от значения ComboBox1
		if (ComboBox1->Text == "Должности") {
			ADOQuery1->SQL->Text =
				"SELECT id_dolzhnost as '№', nazvanie as 'Название' FROM dolzhnost";
		} else if (ComboBox1->Text == "Сотрудники") {
			ADOQuery1->SQL->Text =
				"SELECT id_sotrudnik as '№', familiya as 'Фамилия', imya as 'Имя', "
				"otchestvo as 'Отчество', data_nachalo_raboty as 'Дата начало работы', "
				"nazvanie as 'Название' "
				"FROM sotrudnuk JOIN dolzhnost ON id_dolzhnost = dolzhnost_id_dolzhnost";
		} else {
			ShowMessage("Неизвестный выбор в ComboBox!");
			return;
		}

		// Открываем обновлённый запрос
		ADOQuery1->Open();
		OptimizeColumnWidths(DBGrid1, ADOQuery1);
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при обновлении данных: " + e.Message);
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Форма с отчётом
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateOtchet_ButtonClick(TObject *Sender)
{

	try {
		RestLabel->Caption = "";
		SickLabel->Caption = "";

		RestLabel->Visible = false;
		SickLabel->Visible = false;

		IsFormed = true;
		int year = YearOf(DateTimePicker1->DateTime);  // Год
		int month = MonthOf(DateTimePicker1->DateTime); // Месяц

		// Подготовка таблицы
		Table->RowCount = 1; // Сбрасываем строки, оставляя только заголовок
		int daysInMonth = DaysInMonth(EncodeDate(year, month, 1));
		Table->ColCount = 4 + daysInMonth; // Колонки: №, ФИО, Дата начала, Должность + дни месяца

		// Заголовки
		Table->Cells[0][0] = "№";
		Table->Cells[1][0] = "ФИО";
		Table->Cells[2][0] = "Дата начала";
		Table->Cells[3][0] = "Должность";
		for (int day = 1; day <= daysInMonth; day++) {
			Table->Cells[3 + day][0] = IntToStr(day);
		}

		// Настройка ширины столбцов
		Table->ColWidths[0] = 30;
		Table->ColWidths[1] = 150;
		Table->ColWidths[2] = 80;
		Table->ColWidths[3] = 120;
		for (int day = 1; day <= daysInMonth; day++) {
			Table->ColWidths[3 + day] = 30;
		}

		// Задаем праздничные периоды вручную (например, 28 декабря — 9 января)
		std::vector<std::pair<TDate, TDate>> holidayPeriods = {
			{EncodeDate(year, 12, 28), EncodeDate(year, 12, 31)}, // Новый год
			{EncodeDate(year, 1, 1), EncodeDate(year, 1, 9)},     // Новогодние каникулы
			{EncodeDate(year, 2, 23), EncodeDate(year, 2, 23)},   // 23 февраля
			{EncodeDate(year, 3, 8), EncodeDate(year, 3, 8)},     // 8 марта
			{EncodeDate(year, 5, 1), EncodeDate(year, 5, 5)}      // 1 - 5 мая
		};

		// Формируем запрос к базе данных
		ADOQuery1->Close();
		ADOQuery1->SQL->Text =
			"SELECT "
			"  sotrudnuk.id_sotrudnik AS id, "
			"  CONCAT(sotrudnuk.familiya, ' ', CONCAT(SUBSTRING(imya, 1, 1), '. ', SUBSTRING(otchestvo, 1, 1), '.')) AS fio, "
			"  sotrudnuk.data_nachalo_raboty, "
			"  dolzhnost.nazvanie, "
			"  rabochee_vremya.data_nachala, "
			"  rabochee_vremya.data_okonchaniya, "
			"  rabochee_vremya.status "
			"FROM sotrudnuk "
			"LEFT JOIN dolzhnost ON sotrudnuk.dolzhnost_id_dolzhnost = dolzhnost.id_dolzhnost "
			"LEFT JOIN sot_rab_vremya ON sotrudnuk.id_sotrudnik = sot_rab_vremya.sotrudnuk_id_sotrudnik "
			"LEFT JOIN rabochee_vremya ON sot_rab_vremya.rabochee_vremya_id = rabochee_vremya.id "
			"ORDER BY sotrudnuk.id_sotrudnik";
		ADOQuery1->Open();

		if (ADOQuery1->RecordCount == 0) {
			ShowMessage("Данные о сотрудниках отсутствуют.");
			return;
		}

		// Обработка данных
		int row = 1;
		int currentId = -1;
		while (!ADOQuery1->Eof) {
			int id = ADOQuery1->FieldByName("id")->AsInteger;

			// Если новый сотрудник, добавляем его в таблицу
			if (id != currentId) {
				currentId = id;
				Table->RowCount = row + 1;

				// Заполняем общие данные сотрудника
				Table->Cells[0][row] = IntToStr(row); // Номер строки
				Table->Cells[1][row] = ADOQuery1->FieldByName("fio")->AsString;
				Table->Cells[2][row] = ADOQuery1->FieldByName("data_nachalo_raboty")->AsString;
				Table->Cells[3][row] = ADOQuery1->FieldByName("nazvanie")->AsString;

				for (int day = 1; day <= daysInMonth; day++) {
					TDate date = EncodeDate(year, month, day);
					int dayOfWeek = DayOfWeek(date); // 1 = воскресенье, 7 = суббота
					// Отмечаем выходные
					if (dayOfWeek == 1 || dayOfWeek == 7) {
						Table->Cells[3 + day][row] = "В"; // Выходной
					} else {
						Table->Cells[3 + day][row] = ""; // Рабочий день
					}
					// Проверяем, не попадает ли день в диапазон праздничных дней
					for (const auto &period : holidayPeriods) {
						if (date >= period.first && date <= period.second) {
							if (Table->Cells[3 + day][row] != "В") {
								Table->Cells[3 + day][row] = "П"; // Устанавливаем П только если не выходной
							}
						}
					}
				}
				row++;
			}

			// Заполнение данных о статусах
			TDate data_nachala = ADOQuery1->FieldByName("data_nachala")->AsDateTime;
			TDate data_okonchaniya = ADOQuery1->FieldByName("data_okonchaniya")->AsDateTime;
			String dbStatus = ADOQuery1->FieldByName("status")->AsString;

			// Проставляем статус для соответствующих дней
			for (int day = 1; day <= daysInMonth; day++) {
				TDate date = EncodeDate(year, month, day);
				if (data_nachala <= date && data_okonchaniya >= date) {
					// Устанавливаем статус
					Table->Cells[3 + day][row - 1] = dbStatus == "Отпуск" ? "О" :
													 dbStatus == "Больничный" ? "Б" : dbStatus;
				}
			}

			ADOQuery1->Next();
		}
		ShowMessage("Отчёт сформирован!");
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}




}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit1Change(TObject *Sender)
{
	try {

		int year = YearOf(DateTimePicker1->DateTime);  // Год
		int month = MonthOf(DateTimePicker1->DateTime); // Месяц

		// Подготовка таблицы
		Table->RowCount = 1; // Сбрасываем строки, оставляя только заголовок
		int daysInMonth = DaysInMonth(EncodeDate(year, month, 1));
		Table->ColCount = 4 + daysInMonth; // Колонки: №, ФИО, Дата начала, Должность + дни месяца

		// Заголовки
		Table->Cells[0][0] = "№";
		Table->Cells[1][0] = "ФИО";
		Table->Cells[2][0] = "Дата начала";
		Table->Cells[3][0] = "Должность";
		for (int day = 1; day <= daysInMonth; day++) {
			Table->Cells[3 + day][0] = IntToStr(day);
		}

		// Настройка ширины столбцов
		Table->ColWidths[0] = 30;
		Table->ColWidths[1] = 150;
		Table->ColWidths[2] = 80;
		Table->ColWidths[3] = 120;
		for (int day = 1; day <= daysInMonth; day++) {
			Table->ColWidths[3 + day] = 30;
		}

		// Задаем праздничные периоды вручную (например, 28 декабря — 9 января)
		std::vector<std::pair<TDate, TDate>> holidayPeriods = {
			{EncodeDate(year, 12, 28), EncodeDate(year, 12, 31)}, // Новый год
			{EncodeDate(year, 1, 1), EncodeDate(year, 1, 9)},     // Новогодние каникулы
			{EncodeDate(year, 2, 23), EncodeDate(year, 2, 23)},    // 23 февраля
			{EncodeDate(year, 3, 8), EncodeDate(year, 3, 8)},     //	8 марта
			{EncodeDate(year, 5, 1), EncodeDate(year, 5, 5)}       // 1 - 5 мая
		};

		// Формируем запрос к базе данных
		ADOQuery1->Close();
		ADOQuery1->SQL->Text =
			"SELECT "
			"  sotrudnuk.id_sotrudnik AS id, "
			"  CONCAT(sotrudnuk.familiya, ' ', CONCAT(SUBSTRING(imya, 1, 1), '. ', SUBSTRING(otchestvo, 1, 1), '.')) AS fio, "
			"  sotrudnuk.data_nachalo_raboty, "
			"  dolzhnost.nazvanie, "
			"  rabochee_vremya.data_nachala, "
			"  rabochee_vremya.data_okonchaniya, "
			"  rabochee_vremya.status "
			"FROM sotrudnuk "
			"LEFT JOIN dolzhnost ON sotrudnuk.dolzhnost_id_dolzhnost = dolzhnost.id_dolzhnost "
			"LEFT JOIN sot_rab_vremya ON sotrudnuk.id_sotrudnik = sot_rab_vremya.sotrudnuk_id_sotrudnik "
			"LEFT JOIN rabochee_vremya ON sot_rab_vremya.rabochee_vremya_id = rabochee_vremya.id "
			"where familiya Like '"+ Edit1->Text + "%' ";
		ADOQuery1->Open();

		if (ADOQuery1->RecordCount == 0) {
			ShowMessage("Данные о сотрудниках отсутствуют.");
			return;
		}

		// Обработка данных
		int row = 1;
		int currentId = -1;
		while (!ADOQuery1->Eof) {
			int id = ADOQuery1->FieldByName("id")->AsInteger;

			// Если новый сотрудник, добавляем его в таблицу
			if (id != currentId) {
				currentId = id;
				Table->RowCount = row + 1;

				// Заполняем общие данные сотрудника
				Table->Cells[0][row] = IntToStr(row); // Номер строки
				Table->Cells[1][row] = ADOQuery1->FieldByName("fio")->AsString;
				Table->Cells[2][row] = ADOQuery1->FieldByName("data_nachalo_raboty")->AsString;
				Table->Cells[3][row] = ADOQuery1->FieldByName("nazvanie")->AsString;

				for (int day = 1; day <= daysInMonth; day++) {
					TDate date = EncodeDate(year, month, day);
					int dayOfWeek = DayOfWeek(date); // 1 = воскресенье, 7 = суббота
					// Отмечаем выходные
					if (dayOfWeek == 1 || dayOfWeek == 7) {
						Table->Cells[3 + day][row] = "В"; // Выходной
					} else {
						Table->Cells[3 + day][row] = ""; // Рабочий день
					}
					// Проверяем, не попадает ли день в диапазон праздничных дней
					for (const auto &period : holidayPeriods) {
						if (date >= period.first && date <= period.second) {
							if (Table->Cells[3 + day][row] != "В") {
								Table->Cells[3 + day][row] = "П"; // Устанавливаем П только если не выходной
							}
						}
					}
				}
				row++;
			}

			// Заполнение данных о статусах
			TDate data_nachala = ADOQuery1->FieldByName("data_nachala")->AsDateTime;
			TDate data_okonchaniya = ADOQuery1->FieldByName("data_okonchaniya")->AsDateTime;
			String dbStatus = ADOQuery1->FieldByName("status")->AsString;

			// Проставляем статус для соответствующих дней
			for (int day = 1; day <= daysInMonth; day++) {
				TDate date = EncodeDate(year, month, day);
				if (data_nachala <= date && data_okonchaniya >= date) {
					if (Table->Cells[3 + day][row - 1] == "В" || Table->Cells[3 + day][row - 1] == "П") {
						continue; // Не меняем выходные или праздничные
					}
					// Устанавливаем статус
					Table->Cells[3 + day][row - 1] = dbStatus == "Отпуск" ? "О" :
													 dbStatus == "Больничный" ? "Б" : dbStatus;
				}
			}


			ADOQuery1->Next();
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
{
	try {

		if (IsFormed == false) {
			ShowMessage("Сначала сформируйтесь отчёт!");
            return;
		}
		int year = YearOf(DateTimePicker1->DateTime);
		int month = MonthOf(DateTimePicker1->DateTime);
        // Определяем список сотрудников, для которых нужно обновить данные
        std::vector<int> modifiedRows;
		// Проверяем каждую строку таблицы
        for (int row = 1; row < Table->RowCount; row++) {
            bool hasChanges = false;
			for (int day = 1; day <= DaysInMonth(EncodeDate(year, month, 1)); day++) {
                String status = Table->Cells[3 + day][row]; // Статус в ячейке
                if (!status.IsEmpty()) {
					hasChanges = true;
                    break;
                }
            }
            if (hasChanges) {
                modifiedRows.push_back(row);
            }
		}
        // Обработка только измененных строк
        for (int row : modifiedRows) {
			// Получаем ФИО и дату начала работы
            String fio = Table->Cells[1][row];
            String dateStart = Table->Cells[2][row];
			if (fio.IsEmpty() || dateStart.IsEmpty()) continue;
            fio = StringReplace(fio, ".", "", TReplaceFlags() << rfReplaceAll);
			// Разделение ФИО
            TStringList *fioParts = new TStringList();
            fioParts->Delimiter = ' ';
            fioParts->DelimitedText = fio;
            if (fioParts->Count < 2) {
                ShowMessage("Некорректное ФИО: " + fio);
                delete fioParts;
				continue;
            }
            String familiya = fioParts->Strings[0];
			String imya = fioParts->Strings[1];
            String otchestvo = fioParts->Count >= 3 ? fioParts->Strings[2] : "";
            delete fioParts;
			familiya = familiya.Trim();
            imya = imya.Trim();
			otchestvo = otchestvo.Trim();
			String formattedDateStart = FormatDateTime("yyyy-mm-dd", StrToDate(dateStart));
			// Поиск ID сотрудника
			ADOQuery1->Close();
			ADOQuery1->SQL->Text =
				"SELECT id_sotrudnik "
                "FROM sotrudnuk "
                "WHERE familiya = '" + familiya + "' "
                "AND imya LIKE '" + imya + "%' "
				"AND (otchestvo LIKE '" + otchestvo + "%' OR '" + otchestvo + "' = '') "
                "AND data_nachalo_raboty = '" + formattedDateStart + "'";
			ADOQuery1->Open();
			if (ADOQuery1->RecordCount == 0) {
                ShowMessage("Сотрудник не найден: " + fio);
                continue;
            }
			int sotrudnikID = ADOQuery1->FieldByName("id_sotrudnik")->AsInteger;
            // Удаляем старые данные сотрудника
			ADOQuery1->Close();
			ADOQuery1->SQL->Text =
                "DELETE FROM sot_rab_vremya WHERE sotrudnuk_id_sotrudnik = " + IntToStr(sotrudnikID);
			ADOQuery1->ExecSQL();
			ADOQuery1->Close();
			ADOQuery1->SQL->Text =
                "DELETE FROM rabochee_vremya WHERE id NOT IN (SELECT rabochee_vremya_id FROM sot_rab_vremya)";
			ADOQuery1->ExecSQL();
			// Запись новых данных
			for (int day = 1; day <= DaysInMonth(EncodeDate(year, month, 1)); day++) {
				String status = Table->Cells[3 + day][row];
				TDate currentDate = EncodeDate(year, month, day);
				if (status.IsEmpty() || status == "В") {
					continue; // Пропускаем пустые или выходные дни
				}
				// Добавляем новую запись
				ADOQuery1->Close();
				ADOQuery1->SQL->Text =
					"INSERT INTO rabochee_vremya (status, data_nachala, data_okonchaniya) "
					"VALUES ('" + status + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "')";
				ADOQuery1->ExecSQL();
				ADOQuery1->Close();
				ADOQuery1->SQL->Text = "SELECT LAST_INSERT_ID()";
				ADOQuery1->Open();
				int periodID = ADOQuery1->Fields->Fields[0]->AsInteger;
				ADOQuery1->Close();
				ADOQuery1->SQL->Text =
					"INSERT INTO sot_rab_vremya (sotrudnuk_id_sotrudnik, rabochee_vremya_id) "
					"VALUES (" + IntToStr(sotrudnikID) + ", " + IntToStr(periodID) + ")";
				ADOQuery1->ExecSQL();
			}
		}
		ShowMessage("Изменения успешно сохранены.");
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TableMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    try {
		// Определяем, какая ячейка была нажата
		int col, row;
		Table->MouseToCell(X, Y, col, row);
		// Проверяем, чтобы ячейка была внутри таблицы и не в заголовке
		if (row > 0 && col > 3) { // Пропускаем первые три колонки (№, ФИО, Дата начала, Должность)
			// Получаем выбранный статус из RadioGroup
		if (Table->Cells[col][row] == "В") {
			ShowMessage("Вы не можете изменять выходные дни.");
			return; // Если ячейка содержит "В", выходим
		}
			String status;
			switch (RadioGroup1->ItemIndex) {
				case 0: status = "Б"; break; // Отпуск
				case 1: status = "О"; break; // Больничный
				case 2: status = ""; break;  // Ничего
				default:
					ShowMessage("Выберите статус.");
					return;
			}
			// Обновляем содержимое ячейки
			Table->Cells[col][row] = status;
			// Если необходимо, можно записать изменение в базу данных
			int year = YearOf(DateTimePicker1->DateTime);
			int month = MonthOf(DateTimePicker1->DateTime);
			TDate selectedDate = EncodeDate(year, month, col - 3); // Определяем дату на основе колонки
			SearchFam_Edit->Visible = true;
			Label18->Visible = true;
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Панель добавления сотрудников и должностей
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClosePanelAdd_ButtonClick(TObject *Sender)
{
	AddData_Panel->Visible = false;
	Sotrudnik_Panel->Visible = false;
	Dolzhnost_Panel->Visible = false;
	InfoSotr_Panel->Visible = false;
	AddUserPanel->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::AddSotr_ButtonClick(TObject *Sender)
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

			ComboBox1->Text = "Сотрудники";
			UpdateTableData();

			Fam_Edit->Clear();
			Imya_Edit->Clear();
			Otch_Edit->Clear();
			Dolzh_Combobox->ItemIndex = -1;
			Dolzh_Combobox->Text = "Выберите должность";

			for (int i = 0; i < DBGrid1->Columns->Count; i++) {
				DBGrid1->Columns->Items[i]->Width = 150; // Уменьшаем ширину всех столбцов
			}
			ShowMessage("Запись успешно добавлена, и таблица обновлена.");

		}catch (const Exception &e){
            ShowMessage("Ошибка при добавление данных: " + e.Message);
		}

    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddDolzh_ButtonClick(TObject *Sender)
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

            Dolzhn_Edit->Clear();
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



void __fastcall TMainForm::Word1Click(TObject *Sender)
{
	 if (!SaveDialog1->Execute())
        return; // Пользователь закрыл диалог без выбора файла
    try {
        // Создаем объект Excel
        Variant ExcelApp = CreateOleObject("Excel.Application");
        Variant Workbook = ExcelApp.OlePropertyGet("Workbooks").OleFunction("Add");
        Variant Worksheet = Workbook.OlePropertyGet("Worksheets", 1);
        // Перенос данных из StringGrid в Excel
		for (int row = 0; row < Table->RowCount; ++row) {
			for (int col = 0; col < Table->ColCount; ++col) {
				AnsiString cellValue = Table->Cells[col][row];
                Worksheet.OlePropertyGet("Cells", row + 1, col + 1).OlePropertySet("Value", cellValue);
            }
        }
        // Сохраняем файл
        Workbook.OleFunction("SaveAs", SaveDialog1->FileName);
        Workbook.OleProcedure("Close");
        ExcelApp.OleProcedure("Quit");
        ShowMessage(L"Файл успешно сохранён в формате XLS!");
	} catch (const Exception &e) {
		ShowMessage(L"Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------


 //---------------------------------------------------------------------------
 //Код работы с Панелью Администрирования
 //---------------------------------------------------------------------------


void __fastcall TMainForm::AddUser_ButtonClick(TObject *Sender)
{
	AddData_Panel->Visible = true;
	AddUserPanel->Visible = true;
	AddUserPanel_Button->Visible = true;
	EditUser_Button->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EditUserOnPanel_ButtonClick(TObject *Sender)
{
	EditUser_Button->Visible = true;
	AddUserPanel_Button->Visible = false;

	try {
		if (SelectedRow == -1 || SelectecUserID == -1) {
			ShowMessage("Пожалуйста, выберите строку для изменения.");
			return;
		}
		// Открываем панель для редактирования
		AddData_Panel->Visible = true;
		AddUserPanel->Visible = true;
		// Заполняем метки (Label) данными из выбранной строки
		Login_Edit->Text = ADOQuery1->FieldByName("Логин")->AsString;
		if (ADOQuery1->FieldByName("Роль")->AsString == "admin") {
			RoleCombobox->ItemIndex = 0;
		}else{
			RoleCombobox->ItemIndex = 1;
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при изменении сотрудника: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteUser_ButtonClick(TObject *Sender)
{

	try {
		if (SelectedRow == -1 || SelectecUserID == -1) {
			ShowMessage("Пожалуйста, выберите строку для изменения.");
			return;
		}
		if (MessageDlg("Вы действительно хотите удалить выбранную запись?",
					   mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes){
			ADOQuery1->Close();
			ADOQuery1->SQL->Text = "Delete from users where id_user = " + IntToStr(SelectecUserID);
			ADOQuery1->ExecSQL();
			Button_Admin->OnClick(Sender);
            ShowMessage("Данный пользователь удалён!");
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при изменении сотрудника: " + e.Message);
	}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::AddUserPanel_ButtonClick(TObject *Sender)
{
	AnsiString Login = Login_Edit->Text;
	AnsiString Password = Password_Edit->Text;
	AnsiString RepeatPassword = RepeatPassword_Edit->Text;
	AnsiString Role = RoleCombobox->Text;
	bool PassTrue = CheckPassword(Password, RepeatPassword);
	bool isExist = false;
	if (PassTrue) {
		ADOQuery1->Close();
		ADOQuery1->SQL->Text = "Select COUNT(*) as Count From users where login = '"+Login+"'";
		ADOQuery1->Open();
		int count = ADOQuery1->FieldByName("Count")->AsInteger;
		if (count > 0) {
			ShowMessage("Данный логин уже занят!");
			Login_Edit->Clear();
			RepeatPassword_Edit->Clear();
			Password_Edit->Clear();
			RoleCombobox->ItemIndex = -1;
			RoleCombobox->Text = "Выберите роль";
			AddData_Panel->Visible = false;
			AddData_Panel->Visible = false;
			AddUserPanel->Visible = false;
			Button_Admin->OnClick(Sender);
			return;

		}


		try{
			switch(RoleCombobox->ItemIndex ){
				case 0:
				 Role = "admin";
				 break;
				case 1:
				 Role = "user";
				 break;
			}
			ADOQuery1->Close();
			ADOQuery1->SQL->Text = "Insert Into users (login, `password`, `role`) values ('"+Login+"', MD5('"+ Password +"'), '"+ Role +"')";
			ShowMessage("Пользователь успешно добавлен!");
			ADOQuery1->ExecSQL();
			Login_Edit->Clear();
			RepeatPassword_Edit->Clear();
			Password_Edit->Clear();
			RoleCombobox->ItemIndex = -1;
			RoleCombobox->Text = "Выберите роль";
			AddData_Panel->Visible = false;
			AddUserPanel->Visible = false;
			Button_Admin->OnClick(Sender);
		}catch(const Exception &e){
			ShowMessage(L"Ошибка: " + e.Message);
		}
	}
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::CheckPassword(AnsiString Password, AnsiString RepeatPassword)
{
    bool isBigWord = false;
	bool isLetter = false;

	if (Password.Length() < 4 or Password.Length()  > 16) {
		ShowMessage("Пароль должен содержать от 4 до 16 символов!");
		return false;
	}
	else{

		String forbiddenSymbols = "*&{}|+";
		for (int i = 1; i <= Password.Length(); i++) {
			if (forbiddenSymbols.Pos(Password[i]) > 0) {
				ShowMessage("Пароль содержит недопустимые символы: * & { } | +");
				return false;
			}
		}

		String EnglishSymbols = "123456789";
		for (int i = 1; i <= Password.Length(); i++) {
			if (EnglishSymbols.Pos(Password[i]) > 0) {
			   isLetter = true;
			}
		}

		if(isLetter == false){
			ShowMessage("Отсутствует буква в пароле!");
			return false;
		}
		else{
			if (Password_Edit->Text == RepeatPassword_Edit->Text) {
				String BigEnglishSymbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				for (int i = 1; i <= Password.Length(); i++) {
					if (EnglishSymbols.Pos(Password[i]) > 0) {
					   isBigWord = true;
					}
				}

				if (isBigWord) {
					return true;
				}
				else{
					ShowMessage("В пароле нет заглавной буквы!");
					return false;
				}
			}
			else{
				ShowMessage("Пароли не совпадают!");
				return false;
			}
		}
	}
}
void __fastcall TMainForm::DBGrid3CellClick(TColumn *Column)
{
	try {
		// Получаем индекс выбранной строки
		SelectedRow = DBGrid3->DataSource->DataSet->RecNo - 1; // RecNo возвращает номер строки
		// Получаем ID выбранного сотрудника
		if (SelectedRow >= 0) {
			SelectecUserID = ADOQuery1->FieldByName("№")->AsInteger; // Берём ID из колонки "№"
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка при выборе строки: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EditUser_ButtonClick(TObject *Sender)
{
	AnsiString Login = Login_Edit->Text;
	AnsiString Password = Password_Edit->Text;
	AnsiString RepeatPassword = RepeatPassword_Edit->Text;
	AnsiString Role = RoleCombobox->Text;

	if (Login.Length() == 0 or Password.Length() == 0 or RepeatPassword.Length() == 0 or RoleCombobox->ItemIndex == -1) {
		ShowMessage("Вы должны указать все поля!");
		return;
	}

	bool PassTrue = CheckPassword(Password, RepeatPassword);
	if (PassTrue) {
		try{
			switch(RoleCombobox->ItemIndex){
				case 0:
				 Role = "admin";
				 break;
				case 1:
				 Role = "user";
				 break;
			}
			ADOQuery1->Close();
			ADOQuery1->SQL->Text = "UPDATE users SET login = '"+ Login +"', `password` = MD5('"+Password+"'), `role` = '"+Role+"' WHERE id_user = "+ SelectecUserID;
			ShowMessage("Пользователь успешно обновлён!");
			ADOQuery1->ExecSQL();
			Login_Edit->Clear();
			Password_Edit->Clear();
            RepeatPassword_Edit->Clear();
			RoleCombobox->ItemIndex = -1;
			RoleCombobox->Text = "Выберите роль";
            Button_Admin->OnClick(Sender);
			AddData_Panel->Visible = false;
			AddUserPanel->Visible = false;
		}catch (const Exception &e) {
			ShowMessage("Ошибка при сохранение пользователя: " + e.Message);
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ExitAccount_ButtonClick(TObject *Sender)
{
	Enter->Show();
	this->Hide();
     Enter->Error_Label->Caption = "";
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::TableDblClick(TObject *Sender)
{
	int SelectedRow = Table->Row;
	AnsiString FIO;
	AnsiString Data_nachala_raboty;
	AnsiString Job;
	AnsiString SQLquery;
	RestLabel->Visible = true;
	SickLabel->Visible = true;
	RestLabel->Caption = "Количествой дней отпусков";
	SickLabel->Caption = "Количество больничных дней";

    int year = YearOf(DateTimePicker1->DateTime);  // Год
	int month = MonthOf(DateTimePicker1->DateTime); // Месяц
	AnsiString CountRest;
	try{
		FIO = Table->Cells[1][SelectedRow];
		Data_nachala_raboty =  Table->Cells[2][SelectedRow];
		Job = Table->Cells[3][SelectedRow];

		String formattedDateStart = FormatDateTime("yyyy-mm-dd", StrToDate(Data_nachala_raboty));
		ADOQuery1->Close();
		SQLquery = "SELECT COUNT(*) AS Count FROM rabochee_vremya JOIN sot_rab_vremya ON sot_rab_vremya.rabochee_vremya_id = id JOIN sotrudnuk ON id_sotrudnik = sot_rab_vremya.sotrudnuk_id_sotrudnik JOIN dolzhnost ON id_dolzhnost = dolzhnost_id_dolzhnost WHERE CONCAT(sotrudnuk.familiya, ' ', CONCAT(SUBSTRING(imya, 1, 1), '. ', SUBSTRING(otchestvo, 1, 1), '.')) = '"+FIO+"' AND nazvanie = '"+Job+"' AND data_nachalo_raboty = '"+formattedDateStart+"' AND YEAR(data_nachala) = "+IntToStr(year)+" AND MONTH(data_nachala) = "+IntToStr(month)+"  AND (status = 'Отпуск' OR status = 'О');";
		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();
		CountRest = ADOQuery1->FieldByName("Count")->AsString;
		RestLabel->Caption = RestLabel->Caption + ": " + CountRest;


        ADOQuery1->Close();
		SQLquery = "SELECT COUNT(*) AS Count FROM rabochee_vremya JOIN sot_rab_vremya ON sot_rab_vremya.rabochee_vremya_id = id JOIN sotrudnuk ON id_sotrudnik = sot_rab_vremya.sotrudnuk_id_sotrudnik JOIN dolzhnost ON id_dolzhnost = dolzhnost_id_dolzhnost WHERE CONCAT(sotrudnuk.familiya, ' ', CONCAT(SUBSTRING(imya, 1, 1), '. ', SUBSTRING(otchestvo, 1, 1), '.')) = '"+FIO+"' AND nazvanie = '"+Job+"' AND data_nachalo_raboty = '"+formattedDateStart+"' AND YEAR(data_nachala) = "+IntToStr(year)+" AND MONTH(data_nachala) = "+IntToStr(month)+"  AND (status = 'Больничный' OR status = 'Б');";
		ADOQuery1->SQL->Text = SQLquery;
		ADOQuery1->Open();
		CountRest = ADOQuery1->FieldByName("Count")->AsString;
		SickLabel->Caption = SickLabel->Caption + ": " + CountRest;
	}
	catch (const Exception &e) {
			ShowMessage("Ошибка при выведение данных: " + e.Message);
	}
}
//---------------------------------------------------------------------------
