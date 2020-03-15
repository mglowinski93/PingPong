//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *b;
        TTimer *pilkaTimer;
        TImage *gracz1;
        TTimer *gracz1_lewo;
        TTimer *gracz1_prawo;
        TButton *NastepnaRundaPrzycisk;
        TImage *gracz2;
        TTimer *gracz2_lewo;
        TTimer *gracz2_prawo;
        TStaticText *PunktInfo;
        TStaticText *Wynik;
        TStaticText *iloscOdbicText;
        void __fastcall pilkaTimerTimer(TObject *Sender);
        void __fastcall gracz1_lewoTimer(TObject *Sender);
        void __fastcall gracz1_prawoTimer(TObject *Sender);
        void __fastcall gracz2_lewoTimer(TObject *Sender);
        void __fastcall gracz2_prawoTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall NastepnaRundaPrzyciskClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
