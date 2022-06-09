//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "jpeg.hpp"
#include "Unit1.h"
#include <cfloat>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)

{
        _control87(MCW_EM, MCW_EM);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnOpenClick(TObject *Sender)
{
        TJPEGImage *TheJPEG;
    if(OpenPictureDialog1->Execute()){
        if (OpenPictureDialog1->FilterIndex==2)
        {
                TheJPEG= new TJPEGImage;
                TheJPEG->LoadFromFile(OpenPictureDialog1->FileName);
                Image1->Picture->Bitmap->Assign(TheJPEG);
                Image2->Picture->Bitmap->Assign(TheJPEG);
                delete TheJPEG;
        }
        else if (OpenPictureDialog1->FilterIndex==1)
        {
                Image1->Picture->Bitmap->LoadFromFile(OpenPictureDialog1->FileName);
                Image2->Picture->Bitmap->LoadFromFile(OpenPictureDialog1->FileName);

        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        BYTE *ptr,*ptr2;
        int iWidth,iHeight;
        iWidth = Image1->Picture->Bitmap->Width;
        iHeight = Image1->Picture->Bitmap->Height;
        int      getpixel;
        float   imgsize = iWidth * iHeight;
        float   threshold = 0;
        float   histogram[256] = {0};
        float   sum_back,sum_front;
        float   N0 = 0.,N1 = 0.,w = 0.,tempg = -1,g = -1;
        if(Image1->Picture->Bitmap->PixelFormat==pf8bit){
                for(int i=0;i<iHeight;i++){
                        ptr=(BYTE *)Image1->Picture->Bitmap->ScanLine[i];
                        for(int j=0;j<iWidth;j++ ){
                                getpixel = ptr[j];
                                histogram[int(getpixel)]++;
                        }
                }
                for(int i = 1;i<256;i++)
                        sum_front +=  i*histogram[i];
                for(int i=1; i<256; i++ ){     // i§@¬°ìH­È
                        N0 += histogram[i];
                        N1 = imgsize-N0;
                        if ( N0 == 0 || N1 == 0 ) continue;
                        sum_back = sum_back + i*histogram[i];
                        if ( sum_back == 0) continue;
                        w = (sum_front - sum_back) / N1;
                        if ( w == 0 ) continue;
                        g = N0 * N1 * ( (sum_back/N0) - w ) * ( (sum_back/N0) - w );
                        if ( g == 0 ) continue;
                        if (g >= tempg){
                                threshold = i;
                                tempg = g;
                        }
                }
                Edit1->Text = threshold;
                for (int i=0;i<iHeight;i++){
                        ptr=(BYTE*)Image1->Picture->Bitmap->ScanLine[i];
                        ptr2=(BYTE*)Image2->Picture->Bitmap->ScanLine[i];
                        for(int j = 0; j < iWidth; j++){
                                if(ptr[j] > threshold){
                                        ptr2[j]=255;
                                }
                                else if(ptr[j] <= threshold){
                                        ptr2[j]=0;
                                }
                        }
                }


        }
        Image2->Refresh();
        Image2->Picture->Bitmap->SaveToFile("D:\\C++ Builder DIP Code\\Otsu Algorithm\\Result\\Otsu.bmp");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(SavePictureDialog1->Execute()){
                Image2->Picture->SaveToFile(SavePictureDialog1->FileName);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Image2->Picture->Bitmap->PixelFormat=pf24bit;
        Image2->Picture->Bitmap->SaveToFile("D:\\C++ Builder DIP Code\\Otsu Algorithm\\Result\\24bit.bmp");

}
//---------------------------------------------------------------------------

