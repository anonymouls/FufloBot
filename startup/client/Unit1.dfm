object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Client'
  ClientHeight = 280
  ClientWidth = 363
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
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 17
    Top = 61
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 26
    Top = 80
    Width = 3
    Height = 13
  end
  object Image1: TImage
    Left = 224
    Top = 120
    Width = 105
    Height = 129
    Visible = False
  end
  object Label3: TLabel
    Left = 26
    Top = 99
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 17
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 209
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 98
    Top = 8
    Width = 105
    Height = 25
    Caption = 'Settings'
    TabOrder = 2
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 18
    Top = 80
    Width = 185
    Height = 175
    Caption = 'Settings'
    TabOrder = 3
    Visible = False
    object Button4: TButton
      Left = 16
      Top = 24
      Width = 161
      Height = 25
      Caption = 'Choose +1'
      TabOrder = 0
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 16
      Top = 55
      Width = 161
      Height = 25
      Caption = 'Choose clean'
      TabOrder = 1
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 16
      Top = 86
      Width = 161
      Height = 25
      Caption = 'Choose RED'
      TabOrder = 2
      OnClick = Button6Click
    end
    object Edit1: TEdit
      Left = 81
      Top = 147
      Width = 96
      Height = 21
      Enabled = False
      TabOrder = 3
      OnClick = Edit1Click
    end
    object Button7: TButton
      Left = 16
      Top = 147
      Width = 59
      Height = 25
      Caption = 'First Bet'
      TabOrder = 4
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 16
      Top = 117
      Width = 161
      Height = 25
      Caption = 'Danger Level'
      TabOrder = 5
      OnClick = Button8Click
    end
  end
  object CheckBox1: TCheckBox
    Left = 26
    Top = 39
    Width = 177
    Height = 17
    Caption = #1061#1086#1083#1086#1089#1090#1086#1081' '#1088#1077#1078#1080#1084
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object SB: TStatusBar
    Left = 0
    Top = 261
    Width = 363
    Height = 19
    Panels = <
      item
        Width = 50
      end>
  end
  object FTP: TIdFTP
    OnDisconnected = FTPDisconnected
    IPVersion = Id_IPv4
    ConnectTimeout = 0
    Username = 'Me'
    NATKeepAlive.UseKeepAlive = False
    NATKeepAlive.IdleTimeMS = 0
    NATKeepAlive.IntervalMS = 0
    ProxySettings.ProxyType = fpcmNone
    ProxySettings.Port = 0
    Left = 232
    Top = 80
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 3500
    OnTimer = Timer1Timer
    Left = 232
    Top = 40
  end
  object Timeout: TTimer
    Enabled = False
    Interval = 10000
    OnTimer = TimeoutTimer
    Left = 272
    Top = 40
  end
  object Ping: TIdIcmpClient
    Protocol = 1
    ProtocolIPv6 = 58
    IPVersion = Id_IPv4
    OnReply = PingReply
    Left = 272
    Top = 80
  end
  object TI: TTrayIcon
    BalloonTimeout = 5000
    OnClick = TIClick
    Left = 232
    Top = 112
  end
end
