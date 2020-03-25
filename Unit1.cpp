//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMatchBoardForm *MatchBoardForm;
//---------------------------------------------------------------------------
__fastcall TMatchBoardForm::TMatchBoardForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::Player1UpTimerTimer(TObject *Sender)
{
        if(Racket1Image->Top > CourtImage->Top)
        {
                Racket1Image->Top -= 10;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::Player1DownTimerTimer(TObject *Sender)
{
        if(Racket1Image->Top + Racket1Image->Height < CourtImage->Top + CourtImage->Height)
        {
                Racket1Image->Top += 10;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::Player2UpTimerTimer(TObject *Sender)
{
        if(Racket2Image->Top > CourtImage->Top)
        {
                Racket2Image->Top -= 10;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::Player2DownTimerTimer(TObject *Sender)
{
        if(Racket2Image->Top + Racket2Image->Height < CourtImage->Top + CourtImage->Height)
        {
                Racket2Image->Top += 10;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'a' || Key == 'A') Player1UpTimer->Enabled = true;
        if(Key == 'z' || Key == 'Z') Player1DownTimer->Enabled = true;
        if(Key == VK_UP) Player2UpTimer->Enabled = true;
        if(Key == VK_DOWN) Player2DownTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'a' || Key == 'A') Player1UpTimer->Enabled = false;
        if(Key == 'z' || Key == 'Z') Player1DownTimer->Enabled = false;
        if(Key == VK_UP) Player2UpTimer->Enabled = false;
        if(Key == VK_DOWN) Player2DownTimer->Enabled = false;
}
//---------------------------------------------------------------------------


