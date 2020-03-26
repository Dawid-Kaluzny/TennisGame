//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMatchBoardForm *MatchBoardForm;

int xBall = 15;
int yBall = 15;
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


void __fastcall TMatchBoardForm::BallTimerTimer(TObject *Sender)
{
        BallImage->Left += xBall;
        BallImage->Top += yBall;

        if(BallImage->Top <= CourtImage->Top) yBall = -yBall;
        if(BallImage->Top + BallImage->Height >= CourtImage->Top + CourtImage->Height) yBall = -yBall;

        if((BallImage->Top + BallImage->Height/2 >= Racket1Image->Top) && (BallImage->Top + BallImage->Height/2 <= Racket1Image->Top + Racket1Image->Height) && (BallImage->Left - 10 <= Racket1Image->Left + Racket1Image->Width))
        {
                sndPlaySound("snd/Player1.wav", SND_ASYNC);
                yBall = yBall;
                xBall = -xBall;
        }

        if((BallImage->Top + BallImage->Height/2 >= Racket2Image->Top) && (BallImage->Top + BallImage->Height/2 <= Racket2Image->Top + Racket2Image->Height) && (BallImage->Left + BallImage->Width + 10 >= Racket2Image->Left))
        {
                sndPlaySound("snd/Player2.wav", SND_ASYNC);
                yBall = yBall;
                xBall = -xBall;
        }

        if((BallImage->Left + BallImage->Width <= Racket1Image->Left) || (BallImage->Left >= Racket2Image->Left + Racket2Image->Width))
        {
                BallTimer->Enabled = false;
        }

}
//---------------------------------------------------------------------------

