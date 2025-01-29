﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOtchetForm *OtchetForm;
//---------------------------------------------------------------------------
__fastcall TOtchetForm::TOtchetForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOtchetForm::Button2Click(TObject *Sender)
{
		this->Hide();
		MainForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TOtchetForm::Button1Click(TObject *Sender)
{
	try {
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
			{EncodeDate(year, 2, 23), EncodeDate(year, 2, 23)},    // 23 февраля
			{EncodeDate(year, 3, 8), EncodeDate(year, 3, 8)},     //	8 марта
			{EncodeDate(year, 5, 1), EncodeDate(year, 5, 5)}       // 1 - 5 мая
		};

		// Формируем запрос к базе данных
		EditForm->ADOQuery1->Close();
		EditForm->ADOQuery1->SQL->Text =
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
		EditForm->ADOQuery1->Open();

		if (EditForm->ADOQuery1->RecordCount == 0) {
			ShowMessage("Данные о сотрудниках отсутствуют.");
			return;
		}

		// Обработка данных
		int row = 1;
		int currentId = -1;
		while (!EditForm->ADOQuery1->Eof) {
			int id = EditForm->ADOQuery1->FieldByName("id")->AsInteger;

			// Если новый сотрудник, добавляем его в таблицу
			if (id != currentId) {
				currentId = id;
				Table->RowCount = row + 1;

				// Заполняем общие данные сотрудника
				Table->Cells[0][row] = IntToStr(row); // Номер строки
				Table->Cells[1][row] = EditForm->ADOQuery1->FieldByName("fio")->AsString;
				Table->Cells[2][row] = EditForm->ADOQuery1->FieldByName("data_nachalo_raboty")->AsString;
				Table->Cells[3][row] = EditForm->ADOQuery1->FieldByName("nazvanie")->AsString;

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
			TDate data_nachala = EditForm->ADOQuery1->FieldByName("data_nachala")->AsDateTime;
			TDate data_okonchaniya = EditForm->ADOQuery1->FieldByName("data_okonchaniya")->AsDateTime;
			String dbStatus = EditForm->ADOQuery1->FieldByName("status")->AsString;

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


			EditForm->ADOQuery1->Next();
		}

		ShowMessage("Отчёт сформирован.");
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TOtchetForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TOtchetForm::TableMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
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

void TOtchetForm::Button3Click(TObject *Sender)
{
	
}





//---------------------------------------------------------------------------

void __fastcall TOtchetForm::SearchFam_EditChange(TObject *Sender)
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
		EditForm->ADOQuery1->Close();
		EditForm->ADOQuery1->SQL->Text =
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
			"where familiya Like '"+ SearchFam_Edit->Text + "%' ";
		EditForm->ADOQuery1->Open();

		if (EditForm->ADOQuery1->RecordCount == 0) {
			ShowMessage("Данные о сотрудниках отсутствуют.");
			return;
		}

		// Обработка данных
		int row = 1;
		int currentId = -1;
		while (!EditForm->ADOQuery1->Eof) {
			int id = EditForm->ADOQuery1->FieldByName("id")->AsInteger;

			// Если новый сотрудник, добавляем его в таблицу
			if (id != currentId) {
				currentId = id;
				Table->RowCount = row + 1;

				// Заполняем общие данные сотрудника
				Table->Cells[0][row] = IntToStr(row); // Номер строки
				Table->Cells[1][row] = EditForm->ADOQuery1->FieldByName("fio")->AsString;
				Table->Cells[2][row] = EditForm->ADOQuery1->FieldByName("data_nachalo_raboty")->AsString;
				Table->Cells[3][row] = EditForm->ADOQuery1->FieldByName("nazvanie")->AsString;

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
			TDate data_nachala = EditForm->ADOQuery1->FieldByName("data_nachala")->AsDateTime;
			TDate data_okonchaniya = EditForm->ADOQuery1->FieldByName("data_okonchaniya")->AsDateTime;
			String dbStatus = EditForm->ADOQuery1->FieldByName("status")->AsString;

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


			EditForm->ADOQuery1->Next();
		}
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}

//---------------------------------------------------------------------------


void __fastcall TOtchetForm::N2Click(TObject *Sender)
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
            EditForm->ADOQuery1->Close();
            EditForm->ADOQuery1->SQL->Text =
				"SELECT id_sotrudnik "
                "FROM sotrudnuk "
                "WHERE familiya = '" + familiya + "' "
                "AND imya LIKE '" + imya + "%' "
				"AND (otchestvo LIKE '" + otchestvo + "%' OR '" + otchestvo + "' = '') "
                "AND data_nachalo_raboty = '" + formattedDateStart + "'";
            EditForm->ADOQuery1->Open();
			if (EditForm->ADOQuery1->RecordCount == 0) {
                ShowMessage("Сотрудник не найден: " + fio);
                continue;
            }
            int sotrudnikID = EditForm->ADOQuery1->FieldByName("id_sotrudnik")->AsInteger;
            // Удаляем старые данные сотрудника
			EditForm->ADOQuery1->Close();
            EditForm->ADOQuery1->SQL->Text =
                "DELETE FROM sot_rab_vremya WHERE sotrudnuk_id_sotrudnik = " + IntToStr(sotrudnikID);
            EditForm->ADOQuery1->ExecSQL();
            EditForm->ADOQuery1->Close();
            EditForm->ADOQuery1->SQL->Text =
                "DELETE FROM rabochee_vremya WHERE id NOT IN (SELECT rabochee_vremya_id FROM sot_rab_vremya)";
			EditForm->ADOQuery1->ExecSQL();
            // Запись новых данных
            for (int day = 1; day <= DaysInMonth(EncodeDate(year, month, 1)); day++) {
				String status = Table->Cells[3 + day][row];
                TDate currentDate = EncodeDate(year, month, day);
                if (status.IsEmpty() || status == "В") {
					continue; // Пропускаем пустые или выходные дни
                }
                // Добавляем новую запись
				EditForm->ADOQuery1->Close();
                EditForm->ADOQuery1->SQL->Text =
                    "INSERT INTO rabochee_vremya (status, data_nachala, data_okonchaniya) "
                    "VALUES ('" + status + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "', '" + FormatDateTime("yyyy-mm-dd", currentDate) + "')";
				EditForm->ADOQuery1->ExecSQL();
                EditForm->ADOQuery1->Close();
                EditForm->ADOQuery1->SQL->Text = "SELECT LAST_INSERT_ID()";
				EditForm->ADOQuery1->Open();
                int periodID = EditForm->ADOQuery1->Fields->Fields[0]->AsInteger;
                EditForm->ADOQuery1->Close();
				EditForm->ADOQuery1->SQL->Text =
                    "INSERT INTO sot_rab_vremya (sotrudnuk_id_sotrudnik, rabochee_vremya_id) "
                    "VALUES (" + IntToStr(sotrudnikID) + ", " + IntToStr(periodID) + ")";
                EditForm->ADOQuery1->ExecSQL();
			}
        }
		ShowMessage("Изменения успешно сохранены.");
	}
	catch (const Exception &e) {
		ShowMessage("Ошибка: " + e.Message);
	}
}
//---------------------------------------------------------------------------


