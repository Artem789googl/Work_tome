object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1043#1083#1072#1074#1085#1072#1103' '#1089#1090#1088#1072#1085#1080#1094#1072
  ClientHeight = 545
  ClientWidth = 946
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  OnCreate = FormCreate
  TextHeight = 15
  object Main_label: TLabel
    Left = 8
    Top = 24
    Width = 927
    Height = 37
    Caption = 
      #1044#1086#1073#1088#1086' '#1087#1086#1078#1072#1083#1086#1074#1072#1090#1100' '#1074' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' "'#1059#1095#1077#1090' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1103' '#1088#1072#1073#1086#1095#1077#1075#1086' '#1074#1088#1077#1084#1077#1085 +
      #1080'"'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 32
    Top = 88
    Width = 345
    Height = 377
    Lines.Strings = (
      #1053#1072#1096#1072' '#1087#1088#1086#1075#1088#1072#1084#1084#1072' '#1087#1088#1077#1076#1085#1072#1079#1085#1072#1095#1077#1085#1072' '#1076#1083#1103' '#1088#1072#1073#1086#1090#1099'....'
      ''
      #1056#1091#1082#1086#1074#1086#1076#1089#1090#1074#1086':'
      '   '#1050#1085#1086#1087#1082#1072' "'#1055#1088#1086#1089#1084#1086#1090#1088' '#1076#1072#1085#1085#1099#1093'" - '#1087#1086#1079#1074#1086#1083#1103#1077#1090'...')
    TabOrder = 0
  end
  object Main_Panel: TPanel
    Left = 424
    Top = 88
    Width = 489
    Height = 377
    Color = clSilver
    ParentBackground = False
    TabOrder = 1
    object Label_Panel: TLabel
      Left = 88
      Top = 8
      Width = 312
      Height = 37
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Button_ShowData: TButton
      Left = 40
      Top = 72
      Width = 137
      Height = 41
      Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1076#1072#1085#1085#1099#1093
      TabOrder = 0
    end
    object Button_EditData: TButton
      Left = 40
      Top = 144
      Width = 137
      Height = 41
      Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
      TabOrder = 1
      OnClick = Button_EditDataClick
    end
    object Button_ReportData: TButton
      Left = 40
      Top = 216
      Width = 137
      Height = 41
      Caption = #1054#1090#1095#1077#1090
      TabOrder = 2
    end
    object Button_AboutAvtor: TButton
      Left = 336
      Top = 328
      Width = 137
      Height = 33
      Caption = #1054#1073' '#1072#1074#1090#1086#1088#1077
      TabOrder = 3
    end
  end
  object Button_CloseForm: TBitBtn
    Left = 832
    Top = 496
    Width = 81
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 2
  end
end