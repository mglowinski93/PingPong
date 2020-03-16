//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=8, y=-8;
int punkty_gracza1 = 0;
int punkty_gracza2 = 0;
int iloscOdbic = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    ShowMessage("Witam w grze PingPong.\nLewy gracz steruje wciskaj¹c A oraz Z.\nPrawy gracz steruje wciskaj¹c strza³ki do w góre oraz dó³.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pilkaTimerTimer(TObject *Sender)
{
    b->Left += x;
    b->Top += y;

    if(b->Top-5 <= tlo->Top || b->Top + b->Width+5 >= tlo->Height)
    {
        y = -y;
    }


    if(b->Top > gracz1->Top - b->Width/2 && b->Top < gracz1->Top + gracz1->Height + b->Width/2 && b->Left - b->Width < gracz1->Left ||
       b->Top > gracz2->Top - b->Width/2 && b->Top < gracz2->Top + gracz2->Height + b->Width/2 && b->Left + b->Width > gracz2->Left)
    {
       iloscOdbic++;
       x = -x;
    }else if(b->Left <= gracz1->Left - b->Width/2)
    {
        punkty_gracza2 += 1;
        b->Visible = false;
        PunktInfo->Caption = "Punkt dla gracza 2!";
        PunktInfo->Visible = true;
        Wynik->Caption=IntToStr(punkty_gracza1)+ ":" + IntToStr(punkty_gracza2);
        Wynik->Visible = true;
        iloscOdbicText->Caption = "Ilosc odbic: " + IntToStr(iloscOdbic);
        iloscOdbicText->Visible = true;
        NastepnaRundaPrzycisk->Visible = true;
        NowaGraPrzycisk->Visible = true;
        pilkaTimer->Enabled = false;
    }else if(b->Left >= gracz2->Left + b->Width/2)
    {
        punkty_gracza1 += 1;
        b->Visible = false;
        PunktInfo->Caption = "Punkt dla gracza 1!";
        PunktInfo->Visible = true;
        Wynik->Caption=IntToStr(punkty_gracza1)+ ":" + IntToStr(punkty_gracza2);
        Wynik->Visible = true;
        iloscOdbicText->Caption = "Ilosc odbic: " + IntToStr(iloscOdbic);
        iloscOdbicText->Visible = true;
        NastepnaRundaPrzycisk->Visible = true;
        NowaGraPrzycisk->Visible = true;
        pilkaTimer->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gracz1_lewoTimer(TObject *Sender)
{
    if(gracz1->Top > 10) gracz1->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gracz1_prawoTimer(TObject *Sender)
{
  if(gracz1->Top + gracz1->Height < tlo->Height - 10) gracz1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gracz2_lewoTimer(TObject *Sender)
{
    if(gracz2->Top > 10) gracz2->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gracz2_prawoTimer(TObject *Sender)
{
  if(gracz2->Top + gracz2->Height < tlo->Height - 10) gracz2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ( Key == 'A' ) gracz1_lewo->Enabled = true;
    if ( Key == 'Z' ) gracz1_prawo->Enabled = true;
    if ( Key == VK_UP ) gracz2_lewo->Enabled = true;
    if ( Key == VK_DOWN ) gracz2_prawo->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ( Key == 'A' ) gracz1_lewo->Enabled = false;
    if ( Key == 'Z' ) gracz1_prawo->Enabled = false;
    if ( Key == VK_UP ) gracz2_lewo->Enabled = false;
    if ( Key == VK_DOWN ) gracz2_prawo->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NastepnaRundaPrzyciskClick(TObject *Sender)
{
        b->Left = 128;
        b->Top = 336;
        x = -x;
        y = -y;
        iloscOdbic = 0;
        b->Visible = true;
        PunktInfo->Visible = false;
        Wynik->Visible = false;
        iloscOdbicText->Visible = false;
        pilkaTimer->Enabled = true;
        NastepnaRundaPrzycisk->Visible = false;
        NowaGraPrzycisk->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NowaGraPrzyciskClick(TObject *Sender)
{
    if(Application->MessageBox("Na pewnno zacz¹c now¹ grê?", "PotwierdŸ", MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
    {
        b->Left = 128;
        b->Top = 336;
        x = -x;
        y = -y;
        iloscOdbic = 0;
        b->Visible = true;
        PunktInfo->Visible = false;
        Wynik->Visible = false;
        iloscOdbicText->Visible = false;
        pilkaTimer->Enabled = true;
        NastepnaRundaPrzycisk->Visible = false;
        NowaGraPrzycisk->Visible = false;
        punkty_gracza1 = 0;
        punkty_gracza2 = 0;
    }
}
//---------------------------------------------------------------------------

