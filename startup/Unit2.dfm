object Form2: TForm2
  Left = 0
  Top = 0
  AlphaBlendValue = 150
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
  ClientHeight = 328
  ClientWidth = 819
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Im: TImage
    Left = 408
    Top = 21
    Width = 401
    Height = 276
  end
  object addone: TButton
    Left = 8
    Top = 8
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' +1'
    TabOrder = 0
    OnClick = addoneClick
  end
  object clean: TButton
    Left = 8
    Top = 39
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' Clear'
    TabOrder = 1
    OnClick = cleanClick
  end
  object CheckIN: TButton
    Left = 8
    Top = 102
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1091#1102' '#1079#1086#1085#1091
    TabOrder = 2
    OnClick = CheckINClick
  end
  object History: TButton
    Left = 8
    Top = 133
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1080#1089#1090#1086#1088#1080#1102
    TabOrder = 3
    OnClick = HistoryClick
  end
  object LastO: TButton
    Left = 8
    Top = 164
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1078#1088#1077#1073#1080#1081
    TabOrder = 4
    OnClick = LastOClick
  end
  object Zone: TGroupBox
    Left = 199
    Top = 8
    Width = 203
    Height = 281
    Caption = #1047#1086#1085#1072
    TabOrder = 5
    object Label1: TLabel
      Left = 16
      Top = 23
      Width = 82
      Height = 13
      Caption = #1054#1090#1089#1090#1091#1087' '#1085#1072#1087#1088#1072#1074#1086
    end
    object Label2: TLabel
      Left = 16
      Top = 67
      Width = 75
      Height = 13
      Caption = #1054#1090#1089#1090#1091#1087' '#1089#1074#1077#1088#1093#1091
    end
    object Label3: TLabel
      Left = 16
      Top = 113
      Width = 40
      Height = 13
      Caption = #1064#1080#1088#1080#1085#1072
    end
    object Label4: TLabel
      Left = 16
      Top = 159
      Width = 37
      Height = 13
      Caption = #1042#1099#1089#1086#1090#1072
    end
    object Image1: TImage
      Left = 195
      Top = 21
      Width = 8
      Height = 8
      Visible = False
    end
    object Label5: TLabel
      Left = 24
      Top = 218
      Width = 31
      Height = 13
      Caption = 'Label5'
      Visible = False
    end
    object Edit3: TEdit
      Left = 16
      Top = 132
      Width = 177
      Height = 21
      TabOrder = 0
      Text = '0'
      OnChange = Edit1Change
    end
    object Edit4: TEdit
      Left = 16
      Top = 178
      Width = 177
      Height = 21
      TabOrder = 1
      Text = '0'
      OnChange = Edit1Change
    end
    object Edit2: TEdit
      Left = 17
      Top = 86
      Width = 176
      Height = 21
      TabOrder = 2
      Text = '0'
      OnChange = Edit1Change
    end
    object Edit1: TEdit
      Left = 16
      Top = 42
      Width = 173
      Height = 21
      TabOrder = 3
      Text = '0'
      OnChange = Edit1Change
    end
  end
  object Button1: TButton
    Left = 8
    Top = 71
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1088#1072#1073#1086#1095#1091#1102' '#1079#1086#1085#1091
    TabOrder = 6
    OnClick = Button1Click
  end
  object OKBTN: TButton
    Left = 8
    Top = 295
    Width = 394
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 7
    OnClick = OKBTNClick
  end
  object Button2: TButton
    Left = 8
    Top = 195
    Width = 185
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1095#1072#1090'('#1073#1091#1076#1091#1097#1077#1077')'
    TabOrder = 8
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 226
    Width = 185
    Height = 25
    Caption = #1042#1074#1077#1089#1090#1080' '#1073#1072#1083#1072#1085#1089
    TabOrder = 9
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 257
    Width = 185
    Height = 25
    Caption = #1050#1085#1086#1087#1082#1072' '#1085#1072' '#1050#1056#1040#1057#1053#1054#1045
    TabOrder = 10
    OnClick = Button4Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 312
    Top = 24
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer3Timer
    Left = 312
    Top = 136
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 312
    Top = 80
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer4Timer
    Left = 312
    Top = 192
  end
end
