object Enter: TEnter
  Left = 0
  Top = 0
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1080#1103
  ClientHeight = 390
  ClientWidth = 427
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object EnterLabel: TLabel
    Left = 32
    Top = 16
    Width = 71
    Height = 45
    Caption = #1042#1093#1086#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LoginLabel: TLabel
    Left = 72
    Top = 96
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
  object PasswordLabel: TLabel
    Left = 72
    Top = 176
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
  object Error_Label: TLabel
    Left = 16
    Top = 256
    Width = 5
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object login_edit: TEdit
    Left = 72
    Top = 130
    Width = 241
    Height = 23
    TabOrder = 0
    TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1083#1086#1075#1080#1085
    OnKeyPress = login_editKeyPress
  end
  object pass_edit: TEdit
    Left = 72
    Top = 210
    Width = 241
    Height = 23
    PasswordChar = '*'
    TabOrder = 1
    TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
    OnKeyPress = pass_editKeyPress
  end
  object EnterButton: TButton
    Left = 200
    Top = 309
    Width = 113
    Height = 41
    Caption = #1042#1086#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = EnterButtonClick
  end
end
