object Form1: TForm1
  Left = 243
  Top = 131
  Width = 1417
  Height = 884
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object btnOpen: TBitBtn
    Left = 32
    Top = 8
    Width = 73
    Height = 33
    Caption = 'Open'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = btnOpenClick
  end
  object PageControl1: TPageControl
    Left = 32
    Top = 56
    Width = 1353
    Height = 793
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Original'
      object Image1: TImage
        Left = 8
        Top = 8
        Width = 1329
        Height = 745
        AutoSize = True
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Otsu'
      ImageIndex = 1
      object Image2: TImage
        Left = 8
        Top = 8
        Width = 137
        Height = 113
        AutoSize = True
      end
    end
  end
  object Button1: TButton
    Left = 112
    Top = 8
    Width = 73
    Height = 33
    Caption = 'Otsu'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 192
    Top = 8
    Width = 75
    Height = 33
    Caption = 'Save'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 272
    Top = 8
    Width = 73
    Height = 33
    Caption = '8bit to 24bit'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 376
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Edit1'
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp|JPEG Image File (*.jpg)|*.jpg'
    Left = 1224
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 1192
  end
end
