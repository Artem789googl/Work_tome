object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 736
  ClientWidth = 1499
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  TextHeight = 15
  object Main_label: TLabel
    Left = 682
    Top = 25
    Width = 295
    Height = 37
    Caption = #1059#1095#1105#1090' '#1088#1072#1073#1086#1095#1077#1075#1086' '#1074#1088#1077#1084#1077#1085#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label_Panel: TLabel
    Left = 41
    Top = 103
    Width = 245
    Height = 37
    Caption = #1055#1072#1085#1077#1083#1100' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ShowEditPanel: TPanel
    Left = 319
    Top = 93
    Width = 1163
    Height = 588
    Color = clSilver
    ParentBackground = False
    TabOrder = 3
    Visible = False
    object Lable4: TLabel
      Left = 384
      Top = 19
      Width = 329
      Height = 31
      Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1080' '#1080#1079#1084#1077#1085#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object PageControl1: TPageControl
      Left = 27
      Top = 73
      Width = 1110
      Height = 498
      ActivePage = TabSheet1
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
        object Label18: TLabel
          Left = 393
          Top = 13
          Width = 196
          Height = 31
          Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -23
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Sort_Label: TLabel
          Left = 184
          Top = 15
          Width = 111
          Height = 28
          Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -20
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object DBGrid1: TDBGrid
          Left = 16
          Top = 86
          Width = 905
          Height = 351
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
          Top = 49
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
          Left = 938
          Top = 392
          Width = 143
          Height = 41
          Caption = #1054#1073#1085#1086#1074#1080#1090#1100
          TabOrder = 2
          Visible = False
          OnClick = Button_UpdateClick
        end
        object Button_Add: TButton
          Left = 936
          Top = 90
          Width = 144
          Height = 39
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 3
          OnClick = Button_AddClick
        end
        object Button_Delete: TButton
          Left = 938
          Top = 183
          Width = 143
          Height = 39
          Caption = #1059#1076#1072#1083#1080#1090#1100
          TabOrder = 4
          OnClick = Button_DeleteClick
        end
        object SearchFam_Edit: TEdit
          Left = 393
          Top = 49
          Width = 241
          Height = 31
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1092#1072#1084#1080#1083#1080#1102
          Visible = False
          OnChange = SearchFam_EditChange
        end
        object Edit_button: TButton
          Left = 936
          Top = 135
          Width = 145
          Height = 42
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099
          TabOrder = 6
          OnClick = Edit_buttonClick
        end
        object Sort_Combobox: TComboBox
          Left = 184
          Top = 49
          Width = 195
          Height = 23
          TabOrder = 7
          Text = #1054#1090#1089#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
          Visible = False
          OnChange = Sort_ComboboxChange
          Items.Strings = (
            #1055#1086' '#1085#1086#1084#1077#1088#1091' '#8593
            #1055#1086' '#1085#1086#1084#1077#1088#1091' '#8595
            #1055#1086' '#1092#1072#1084#1080#1083#1080#1080' '#8593
            #1055#1086' '#1092#1072#1084#1080#1083#1080#1080' '#8595
            #1055#1086' '#1080#1084#1077#1085#1080' '#8593
            #1055#1086' '#1080#1084#1077#1085#1080' '#8595
            #1055#1086' '#1086#1090#1095#1077#1089#1090#1074#1091' '#8593
            #1055#1086' '#1086#1090#1095#1077#1089#1090#1074#1091' '#8595
            #1055#1086' '#1076#1072#1090#1077' '#1085#1072#1095#1072#1083#1072' '#1088#1072#1073#1086#1090#1099' '#8593
            #1055#1086' '#1076#1072#1090#1077' '#1085#1072#1095#1072#1083#1072' '#1088#1072#1073#1086#1090#1099' '#8595)
        end
      end
    end
  end
  object AdminPanel: TPanel
    Left = 319
    Top = 94
    Width = 1161
    Height = 585
    Color = clSilver
    ParentBackground = False
    TabOrder = 6
    Visible = False
    object Label9: TLabel
      Left = 384
      Top = 14
      Width = 219
      Height = 31
      Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1080#1088#1086#1074#1072#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object AddUser_Button: TButton
      Left = 47
      Top = 85
      Width = 274
      Height = 56
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = AddUser_ButtonClick
    end
    object DBGrid3: TDBGrid
      Left = 560
      Top = 72
      Width = 521
      Height = 489
      DataSource = DataSource1
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'Segoe UI'
      TitleFont.Style = []
      OnCellClick = DBGrid3CellClick
    end
    object EditUserOnPanel_Button: TButton
      Left = 47
      Top = 167
      Width = 274
      Height = 56
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = EditUserOnPanel_ButtonClick
    end
    object DeleteUser_Button: TButton
      Left = 47
      Top = 246
      Width = 274
      Height = 53
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = DeleteUser_ButtonClick
    end
  end
  object OtchetPanel: TPanel
    Left = 321
    Top = 84
    Width = 1162
    Height = 653
    Color = clSilver
    ParentBackground = False
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 681
      Top = 48
      Width = 196
      Height = 31
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object ResultLabel: TLabel
      Left = 12
      Top = 553
      Width = 59
      Height = 28
      Caption = #1048#1090#1086#1075#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object RestLabel: TLabel
      Left = 39
      Top = 584
      Width = 238
      Height = 28
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1085#1077#1081' '#1086#1090#1087#1091#1089#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object SickLabel: TLabel
      Left = 39
      Top = 616
      Width = 282
      Height = 28
      Caption = #1050#1086#1083#1080#1095#1077#1089#1074#1090#1086' '#1073#1086#1083#1100#1085#1080#1095#1085#1099#1093' '#1076#1085#1077#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object Table: TStringGrid
      Left = 12
      Top = 122
      Width = 1137
      Height = 409
      TabOrder = 0
      OnDblClick = TableDblClick
      OnMouseDown = TableMouseDown
    end
    object Edit1: TEdit
      Left = 676
      Top = 85
      Width = 241
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1092#1072#1084#1080#1083#1080#1102
      Visible = False
      OnChange = Edit1Change
    end
    object RadioGroup1: TRadioGroup
      Left = 441
      Top = 18
      Width = 185
      Height = 98
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
      DoubleBuffered = False
      Items.Strings = (
        #1041#1086#1083#1100#1085#1080#1095#1085#1099#1081
        #1054#1090#1087#1091#1089#1082
        #1059#1076#1072#1083#1080#1090#1100)
      ParentDoubleBuffered = False
      TabOrder = 2
    end
    object DateTimePicker1: TDateTimePicker
      Left = 201
      Top = 73
      Width = 217
      Height = 33
      Date = 45641.000000000000000000
      Time = 0.552010555555170900
      TabOrder = 3
    end
    object CreateOtchet_Button: TButton
      Left = 12
      Top = 69
      Width = 145
      Height = 33
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1086#1090#1095#1077#1090
      TabOrder = 4
      OnClick = CreateOtchet_ButtonClick
    end
  end
  object OpenCgPas_Button: TButton
    Left = 8
    Top = 508
    Width = 305
    Height = 52
    Caption = #1051#1080#1095#1085#1099#1081' '#1082#1072#1073#1080#1085#1077#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = ButtonAccCgPassDataClick
  end
  object Change_Panel: TPanel
    Left = 319
    Top = 84
    Width = 450
    Height = 433
    Color = clSkyBlue
    ParentBackground = False
    TabOrder = 8
    Visible = False
    object Account_Label: TLabel
      Left = 64
      Top = 26
      Width = 226
      Height = 41
      Caption = #1051#1080#1095#1085#1099#1081' '#1082#1072#1073#1080#1085#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -30
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object User_Label: TLabel
      Left = 91
      Top = 95
      Width = 68
      Height = 31
      Caption = #1051#1086#1075#1080#1085':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object ChPas_Label: TLabel
      Left = 91
      Top = 156
      Width = 149
      Height = 31
      Caption = #1057#1084#1077#1085#1072' '#1087#1072#1088#1086#1083#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object PasswordAcc_Label: TLabel
      Left = 136
      Top = 193
      Width = 69
      Height = 28
      Caption = #1055#1072#1088#1086#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 136
      Top = 265
      Width = 171
      Height = 28
      Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object PassAcc_Edit: TEdit
      Left = 144
      Top = 236
      Width = 182
      Height = 23
      TabOrder = 0
      TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
    end
    object RepPass_Edit: TEdit
      Left = 144
      Top = 299
      Width = 182
      Height = 23
      TabOrder = 1
      TextHint = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
    end
    object SavePass_Button: TButton
      Left = 215
      Top = 352
      Width = 111
      Height = 33
      Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1086#1083#1100
      TabOrder = 2
      OnClick = ButtonSavePasswordClick
    end
  end
  object ExitAccount_Button: TButton
    Left = 192
    Top = 648
    Width = 107
    Height = 33
    Caption = #1042#1099#1081#1090#1080
    TabOrder = 7
    OnClick = ExitAccount_ButtonClick
  end
  object Button_EditData: TButton
    Left = 8
    Top = 152
    Width = 305
    Height = 52
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1080' '#1080#1079#1084#1077#1085#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button_EditDataClick
  end
  object Button_ReportData: TButton
    Left = 8
    Top = 222
    Width = 305
    Height = 52
    Caption = #1054#1090#1095#1077#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button_ReportDataClick
  end
  object Button_Admin: TButton
    Left = 8
    Top = 575
    Width = 305
    Height = 51
    Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1080#1088#1086#1074#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button_AdminClick
  end
  object AddData_Panel: TPanel
    Left = 0
    Top = 0
    Width = 1499
    Height = 736
    Align = alClient
    Color = clSilver
    ParentBackground = False
    TabOrder = 4
    Visible = False
    ExplicitWidth = 1493
    ExplicitHeight = 727
    object AddUserPanel: TPanel
      Left = 504
      Top = 134
      Width = 649
      Height = 460
      TabOrder = 4
      Visible = False
      object AddUser_Label: TLabel
        Left = 224
        Top = 15
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
      object Login_Label: TLabel
        Left = 67
        Top = 73
        Width = 57
        Height = 28
        Caption = #1051#1086#1075#1080#1085
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Password_Label: TLabel
        Left = 67
        Top = 153
        Width = 69
        Height = 28
        Caption = #1055#1072#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object RepeatPasswordPanel: TLabel
        Left = 67
        Top = 234
        Width = 171
        Height = 28
        Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1100' '#1087#1072#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Role_Label: TLabel
        Left = 365
        Top = 71
        Width = 44
        Height = 28
        Caption = #1056#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Error_Label: TLabel
        Left = 67
        Top = 314
        Width = 5
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Login_Edit: TEdit
        Left = 67
        Top = 115
        Width = 214
        Height = 23
        TabOrder = 0
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1083#1086#1075#1080#1085
      end
      object Password_Edit: TEdit
        Left = 67
        Top = 194
        Width = 214
        Height = 23
        TabOrder = 1
        TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
      end
      object RepeatPassword_Edit: TEdit
        Left = 67
        Top = 268
        Width = 214
        Height = 23
        TabOrder = 2
        TextHint = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
      end
      object AddUserPanel_Button: TButton
        Left = 360
        Top = 360
        Width = 251
        Height = 49
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = AddUserPanel_ButtonClick
      end
      object RoleCombobox: TComboBox
        Left = 360
        Top = 115
        Width = 145
        Height = 23
        TabOrder = 4
        Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1086#1083#1100
        Items.Strings = (
          #1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088
          #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100)
      end
      object EditUser_Button: TButton
        Left = 61
        Top = 360
        Width = 172
        Height = 49
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Visible = False
        OnClick = EditUser_ButtonClick
      end
    end
    object Sotrudnik_Panel: TPanel
      Left = 505
      Top = 135
      Width = 644
      Height = 458
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 0
      Visible = False
      object Label2: TLabel
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
      object Label3: TLabel
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
      object Label4: TLabel
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
      object Label5: TLabel
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
      object Label6: TLabel
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
      object Label7: TLabel
        Left = 54
        Top = 347
        Width = 212
        Height = 31
        Caption = #1044#1072#1090#1072' '#1085#1072#1095#1072#1083#1072' '#1088#1072#1073#1086#1090#1099
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
    object Dolzhnost_Panel: TPanel
      Left = 505
      Top = 135
      Width = 644
      Height = 458
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 2
      Visible = False
      object Label8: TLabel
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
      object Label19: TLabel
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
    object InfoSotr_Panel: TPanel
      Left = 504
      Top = 135
      Width = 645
      Height = 458
      Color = clSkyBlue
      ParentBackground = False
      TabOrder = 3
      Visible = False
      object Label20: TLabel
        Left = 199
        Top = 22
        Width = 303
        Height = 31
        Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1089#1086#1090#1088#1091#1076#1085#1080#1082#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 392
        Top = 219
        Width = 232
        Height = 28
        Caption = #1044#1072#1090#1072' '#1086#1082#1086#1085#1095#1072#1085#1080#1103' '#1087#1077#1088#1080#1086#1076#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object ImyaLabel: TLabel
        Left = 39
        Top = 120
        Width = 43
        Height = 28
        Caption = #1048#1084#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object FamLabel: TLabel
        Left = 37
        Top = 86
        Width = 88
        Height = 28
        Caption = #1060#1072#1084#1080#1083#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object DolzhLabel: TLabel
        Left = 39
        Top = 222
        Width = 107
        Height = 28
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label16: TLabel
        Left = 392
        Top = 152
        Width = 199
        Height = 28
        Caption = #1044#1072#1090#1072' '#1085#1072#1095#1072#1083#1072' '#1087#1077#1088#1080#1086#1076#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label15: TLabel
        Left = 392
        Top = 70
        Width = 75
        Height = 28
        Caption = #1057#1090#1072#1090#1091#1089#1099':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object DataNachLabel: TLabel
        Left = 39
        Top = 188
        Width = 188
        Height = 28
        Caption = #1044#1072#1090#1072' '#1085#1072#1095#1072#1083#1072' '#1088#1072#1073#1086#1090#1099':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object OtchestvoLabel: TLabel
        Left = 39
        Top = 154
        Width = 88
        Height = 28
        Caption = #1054#1090#1095#1077#1089#1090#1074#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object SaveDate_Button: TButton
        Left = 480
        Top = 336
        Width = 147
        Height = 43
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SaveDate_ButtonClick
      end
      object DateEnd_Calendar: TCalendarPicker
        Left = 392
        Top = 253
        Width = 241
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
        OnChange = DateEnd_CalendarChange
        ParentFont = False
        TabOrder = 1
        TextHint = #1074#1099#1073#1077#1088#1080#1090#1077' '#1076#1072#1090#1091
      end
      object DateStart_Calendar: TCalendarPicker
        Left = 392
        Top = 186
        Width = 241
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
        TabOrder = 2
        TextHint = #1074#1099#1073#1077#1088#1080#1090#1077' '#1076#1072#1090#1091
      end
      object Status_ComboBox: TComboBox
        Left = 392
        Top = 104
        Width = 155
        Height = 23
        TabOrder = 3
        Text = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1090#1072#1090#1091#1089
        Items.Strings = (
          #1054#1090#1087#1091#1089#1082
          #1041#1086#1083#1100#1085#1080#1095#1085#1099#1081)
      end
    end
    object ClosePanelAdd_Button: TButton
      Left = 1184
      Top = 38
      Width = 147
      Height = 43
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = ClosePanelAdd_ButtonClick
    end
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;User ID=root;Data' +
      ' Source=Univercity;Initial Catalog=univercity'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 40
    Top = 24
  end
  object DataSource2: TDataSource
    DataSet = ADOQuery1
    Left = 344
    Top = 24
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    Left = 416
    Top = 24
  end
  object SaveDialog1: TSaveDialog
    Left = 129
    Top = 24
  end
  object MainMenu1: TMainMenu
    Left = 200
    Top = 24
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1041#1044
        OnClick = N2Click
      end
      object Excel1: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' Excel'
        OnClick = Word1Click
      end
    end
  end
  object DataSource1: TDataSource
    Left = 272
    Top = 24
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 480
    Top = 24
  end
end
