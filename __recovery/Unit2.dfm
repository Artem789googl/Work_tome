object EditForm: TEditForm
  Left = 0
  Top = 0
  Caption = 'EditForm'
  ClientHeight = 594
  ClientWidth = 1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 44
    Top = 88
    Width = 1029
    Height = 498
    ActivePage = TabSheet2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
      object DBGrid1: TDBGrid
        Left = 16
        Top = 45
        Width = 793
        Height = 404
        DataSource = DataSource1
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -12
        TitleFont.Name = 'Segoe UI'
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnKeyPress = DBGrid1KeyPress
      end
      object ComboBox1: TComboBox
        Left = 16
        Top = 16
        Width = 145
        Height = 23
        TabOrder = 1
        Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1072#1073#1083#1080#1094#1091
        OnChange = ComboBox1Change
        Items.Strings = (
          #1057#1086#1090#1088#1091#1076#1085#1080#1082#1080
          #1044#1086#1083#1078#1085#1086#1089#1090#1080)
      end
      object Button_Update: TButton
        Left = 824
        Top = 417
        Width = 99
        Height = 25
        Caption = #1054#1073#1085#1086#1074#1080#1090#1100
        TabOrder = 2
        Visible = False
        OnClick = Button_UpdateClick
      end
      object Button_Add: TButton
        Left = 824
        Top = 44
        Width = 97
        Height = 25
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        TabOrder = 3
        OnClick = Button_AddClick
      end
      object Button_Delete: TButton
        Left = 824
        Top = 98
        Width = 97
        Height = 25
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 4
        Visible = False
        OnClick = Button_DeleteClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1074#1088#1077#1084#1077#1085#1080
      ImageIndex = 1
      object Label9: TLabel
        Left = 32
        Top = 19
        Width = 420
        Height = 37
        Caption = #1053#1072#1079#1085#1072#1095#1077#1085#1080#1077' '#1074#1088#1077#1084#1085#1080' '#1089#1086#1090#1088#1091#1076#1085#1080#1082#1072#1084
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Calendar1: TCalendar
        Left = 60
        Top = 198
        Width = 320
        Height = 120
        StartOfWeek = 0
        TabOrder = 0
        UseCurrentDate = False
        OnClick = Calendar1Click
      end
    end
  end
  object BackButton: TButton
    Left = 994
    Top = 43
    Width = 75
    Height = 25
    Caption = #1042#1077#1088#1085#1091#1090#1100#1089#1103
    TabOrder = 1
    OnClick = BackButtonClick
  end
  object AddData_Panel: TPanel
    Left = 530
    Top = 2
    Width = 135
    Height = 106
    Align = alCustom
    Color = clCream
    ParentBackground = False
    TabOrder = 2
    Visible = False
    object Sotrudnik_Panel: TPanel
      Left = 201
      Top = 89
      Width = 644
      Height = 434
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 0
      Visible = False
      object Label1: TLabel
        Left = 36
        Top = 29
        Width = 248
        Height = 31
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 56
        Top = 83
        Width = 95
        Height = 31
        Caption = #1060#1072#1084#1080#1083#1080#1103
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 56
        Top = 149
        Width = 45
        Height = 31
        Caption = #1048#1084#1103
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 56
        Top = 215
        Width = 96
        Height = 31
        Caption = #1054#1090#1095#1077#1089#1090#1074#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 56
        Top = 281
        Width = 116
        Height = 31
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 54
        Top = 347
        Width = 213
        Height = 31
        Caption = #1044#1072#1090#1072' '#1085#1072#1095#1072#1083#1086' '#1088#1072#1073#1086#1090#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Fam_Edit: TEdit
        Left = 56
        Top = 120
        Width = 121
        Height = 23
        MaxLength = 50
        TabOrder = 0
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1092#1072#1084#1080#1083#1080#1102
      end
      object Imya_Edit: TEdit
        Left = 54
        Top = 186
        Width = 121
        Height = 23
        MaxLength = 50
        TabOrder = 1
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103
      end
      object Otch_Edit: TEdit
        Left = 56
        Top = 252
        Width = 121
        Height = 23
        MaxLength = 50
        TabOrder = 2
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1086#1090#1095#1077#1089#1090#1074#1086
      end
      object Calendar: TCalendarPicker
        Left = 273
        Top = 347
        Width = 178
        Height = 32
        CalendarHeaderInfo.DaysOfWeekFont.Charset = DEFAULT_CHARSET
        CalendarHeaderInfo.DaysOfWeekFont.Color = clWindowText
        CalendarHeaderInfo.DaysOfWeekFont.Height = -17
        CalendarHeaderInfo.DaysOfWeekFont.Name = 'Segoe UI'
        CalendarHeaderInfo.DaysOfWeekFont.Style = []
        CalendarHeaderInfo.Font.Charset = DEFAULT_CHARSET
        CalendarHeaderInfo.Font.Color = clWindowText
        CalendarHeaderInfo.Font.Height = -25
        CalendarHeaderInfo.Font.Name = 'Segoe UI'
        CalendarHeaderInfo.Font.Style = []
        Color = clWindow
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1076#1072#1090#1091
      end
      object Dolzh_Combobox: TComboBox
        Left = 56
        Top = 318
        Width = 145
        Height = 23
        TabOrder = 4
        Text = #1044#1086#1083#1078#1085#1086#1089#1090#1100
        Items.Strings = (
          '')
      end
      object AddSotr_Button: TButton
        Left = 480
        Top = 385
        Width = 139
        Height = 49
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1086#1090#1088#1091#1076#1085#1080#1082#1072
        TabOrder = 5
        OnClick = AddSotr_ButtonClick
      end
    end
    object ClosePanelAdd_Button: TButton
      Left = 944
      Top = 24
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = ClosePanelAdd_ButtonClick
    end
    object Dolzhnost_Panel: TPanel
      Left = 201
      Top = 89
      Width = 644
      Height = 434
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 2
      Visible = False
      object Label7: TLabel
        Left = 38
        Top = 24
        Width = 261
        Height = 37
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1083#1078#1085#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 38
        Top = 83
        Width = 116
        Height = 31
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Dolzhn_Edit: TEdit
        Left = 38
        Top = 120
        Width = 139
        Height = 23
        MaxLength = 50
        TabOrder = 0
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1076#1086#1083#1078#1085#1086#1089#1090#1100
      end
      object AddDolzh_Button: TButton
        Left = 50
        Top = 174
        Width = 127
        Height = 35
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1083#1078#1085#1086#1089#1090#1100
        TabOrder = 1
        OnClick = AddDolzh_ButtonClick
      end
      object DBGrid2: TDBGrid
        Left = 264
        Top = 93
        Width = 320
        Height = 292
        DataSource = DataSource1
        TabOrder = 2
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -12
        TitleFont.Name = 'Segoe UI'
        TitleFont.Style = []
      end
    end
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;User ID=root;Data' +
      ' Source=Univercity;Initial Catalog=univercity;'
    Left = 56
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 280
    Top = 16
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 416
    Top = 16
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    Left = 176
    Top = 16
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery1
    Left = 352
    Top = 16
  end
end