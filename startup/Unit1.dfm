object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ACRG'
  ClientHeight = 261
  ClientWidth = 376
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Im2: TImage
    Left = 256
    Top = 53
    Width = 65
    Height = 80
  end
  object Im3: TImage
    Left = 17
    Top = 51
    Width = 217
    Height = 80
  end
  object Im4: TImage
    Left = 17
    Top = 156
    Width = 225
    Height = 80
  end
  object Image1: TImage
    Left = 127
    Top = 52
    Width = 42
    Height = 44
    Visible = False
  end
  object STATIC1: TLabel
    Left = 256
    Top = 34
    Width = 52
    Height = 13
    Caption = #1063#1077#1082' '#1087#1086#1080#1085#1090
  end
  object STATIC3: TLabel
    Left = 17
    Top = 137
    Width = 81
    Height = 13
    Caption = #1048#1089#1090#1086#1088#1080#1103' '#1093#1088#1077#1085#1077#1081
  end
  object STATIC4: TLabel
    Left = 17
    Top = 34
    Width = 88
    Height = 13
    Caption = #1055#1086#1089#1083#1077#1076#1085#1103#1103' '#1093#1088#1077#1085#1100
  end
  object Button1: TButton
    Left = 8
    Top = 1
    Width = 75
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 174
    Top = 1
    Width = 75
    Height = 25
    Caption = 'Settings'
    TabOrder = 1
    OnClick = Button2Click
  end
  object SET: TGroupBox
    Left = 8
    Top = 259
    Width = 585
    Height = 291
    Caption = 'Settings'
    TabOrder = 2
    Visible = False
    object Im: TImage
      Left = 423
      Top = 45
      Width = 105
      Height = 105
    end
    object STATIC2: TLabel
      Left = 423
      Top = 26
      Width = 54
      Height = 13
      Caption = #1069#1082#1079#1077#1084#1087#1083#1103#1088
    end
    object CheckIN: TButton
      Left = 3
      Top = 173
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1091#1102' '#1079#1086#1085#1091
      TabOrder = 0
      OnClick = CheckINClick
    end
    object clean: TButton
      Left = 3
      Top = 48
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' Clear'
      TabOrder = 1
      OnClick = cleanClick
    end
    object addone: TButton
      Left = 3
      Top = 17
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' +1'
      TabOrder = 2
      OnClick = addoneClick
    end
    object chat: TButton
      Left = 3
      Top = 79
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1095#1072#1090'('#1073#1091#1076#1091#1097#1077#1077')'
      TabOrder = 3
    end
    object balan: TButton
      Left = 3
      Top = 110
      Width = 185
      Height = 25
      Caption = #1042#1074#1077#1089#1090#1080' '#1073#1072#1083#1072#1085#1089
      TabOrder = 4
      OnClick = balanClick
    end
    object addwz: TButton
      Left = 3
      Top = 141
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1088#1072#1073#1086#1095#1091#1102' '#1079#1086#1085#1091
      TabOrder = 5
      OnClick = btnwzClick
    end
    object History: TButton
      Left = 3
      Top = 204
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1080#1089#1090#1086#1088#1080#1102
      TabOrder = 6
      OnClick = HistoryClick
    end
    object LastO: TButton
      Left = 3
      Top = 235
      Width = 185
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1078#1088#1077#1073#1080#1081
      TabOrder = 7
      OnClick = LastOClick
    end
    object redlock: TButton
      Left = 3
      Top = 263
      Width = 185
      Height = 25
      Caption = #1050#1085#1086#1087#1082#1072' '#1085#1072' '#1050#1056#1040#1057#1053#1054#1045
      TabOrder = 8
      OnClick = redlockClick
    end
    object Zone: TGroupBox
      Left = 199
      Top = 17
      Width = 203
      Height = 274
      Caption = #1047#1086#1085#1072
      TabOrder = 9
      object TL: TLabel
        Left = 16
        Top = 23
        Width = 82
        Height = 13
        Caption = #1054#1090#1089#1090#1091#1087' '#1085#1072#1087#1088#1072#1074#1086
      end
      object TT: TLabel
        Left = 16
        Top = 67
        Width = 75
        Height = 13
        Caption = #1054#1090#1089#1090#1091#1087' '#1089#1074#1077#1088#1093#1091
      end
      object WD: TLabel
        Left = 16
        Top = 113
        Width = 40
        Height = 13
        Caption = #1064#1080#1088#1080#1085#1072
      end
      object HH: TLabel
        Left = 16
        Top = 159
        Width = 37
        Height = 13
        Caption = #1042#1099#1089#1086#1090#1072
      end
      object STA: TLabel
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
      end
      object Edit4: TEdit
        Left = 16
        Top = 178
        Width = 177
        Height = 21
        TabOrder = 1
        Text = '0'
      end
      object Edit2: TEdit
        Left = 17
        Top = 86
        Width = 176
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object Edit1: TEdit
        Left = 16
        Top = 42
        Width = 173
        Height = 21
        TabOrder = 3
        Text = '0'
      end
    end
  end
  object CheckBox1: TCheckBox
    Left = 270
    Top = 8
    Width = 97
    Height = 17
    Caption = #1055#1088#1077#1076#1086#1093#1088#1072#1085#1080#1090#1077#1083#1100
    Checked = True
    State = cbChecked
    TabOrder = 3
  end
  object SB: TStatusBar
    Left = 0
    Top = 242
    Width = 376
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 50
      end>
    ExplicitTop = 261
    ExplicitWidth = 667
  end
  object WT: TTimer
    Enabled = False
    Interval = 2500
    OnTimer = WTTimer
    Left = 120
    Top = 48
  end
  object HTTP: TIdHTTP
    IOHandler = IdSSLIOHandlerSocketOpenSSL1
    AllowCookies = True
    HandleRedirects = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Chrome/50.0.2661.102'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 120
    Top = 160
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 120
    Top = 104
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 328
    Top = 304
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer4Timer
    Left = 328
    Top = 416
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer3Timer
    Left = 328
    Top = 360
  end
  object Timer5: TTimer
    Enabled = False
    OnTimer = Timer5Timer
    Left = 328
    Top = 464
  end
  object TimeOut: TTimer
    Interval = 45000
    OnTimer = TimeOutTimer
    Left = 184
    Top = 48
  end
  object TI: TTrayIcon
    OnClick = TIClick
    Left = 184
    Top = 96
  end
  object Restart: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = RestartTimer
    Left = 264
    Top = 144
  end
  object RESP: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = RESPTimer
    Left = 264
    Top = 192
  end
end
