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
bool doesPlayer1Serve = true;
int player1Points = 0;
int player2Points = 0;
int player1Games = 0;
int player2Games = 0;
//---------------------------------------------------------------------------
__fastcall TMatchBoardForm::TMatchBoardForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void bounceBall(TImage* RacketImage)
{
        int flightDirection;

        if((MatchBoardForm->BallImage->Top >= RacketImage->Top + RacketImage->Height/2 - MatchBoardForm->BallImage->Height) && (MatchBoardForm->BallImage->Top <= RacketImage->Top + RacketImage->Height/2))
        {
                xBall = -1.14 * xBall;
                yBall = yBall / 1.07;
        }
        else
        {
                xBall = -1.07 * xBall;
                yBall = 1.07 * yBall;
        }

        flightDirection = random(2) + 1;

        if(flightDirection == 1)
        {
                yBall = -yBall;
        }
}
//---------------------------------------------------------------------------

bool isGameWon(int &winPlayerPoints, int &losePlayerPoints)
{
        if(winPlayerPoints == 4 && losePlayerPoints  <= 2) return true;
        else if(winPlayerPoints == 4 && losePlayerPoints == 4)
        {
                winPlayerPoints--;
                losePlayerPoints--;
        }
        else if(winPlayerPoints == 5) return true;
        return false;
}
//---------------------------------------------------------------------------

bool isGameOver(int &winPlayerGames, int &losePlayerGames)
{
        if(winPlayerGames == 6 && losePlayerGames  <= 4) return true;
        else if(winPlayerGames == 7) return true;
        return false;
}
//---------------------------------------------------------------------------

AnsiString viewScore(int &playerPoints)
{
        AnsiString playerScore;
        switch(playerPoints)
        {
                case 0: playerScore = "0"; break;
                case 1: playerScore = "15"; break;
                case 2: playerScore = "30"; break;
                case 3: playerScore = "40"; break;
                case 4: playerScore = "AD"; break;
        }
        return playerScore;
}
//---------------------------------------------------------------------------

void startNextRound()
{
        player1Points = 0;
        player2Points = 0;
        if(doesPlayer1Serve)
                doesPlayer1Serve = false;
        else
                doesPlayer1Serve = true;
}
//---------------------------------------------------------------------------

void viewWinPlayer(TImage* PlayerPointImage, TImage* PlayerWinImage)
{
        Application->ProcessMessages(); Sleep(2500);
        PlayerPointImage->Visible = false;
        MatchBoardForm->SetsLabel->Caption = "0 : 0";
        Application->ProcessMessages(); Sleep(500);
        sndPlaySound("snd/WinGame.wav", SND_ASYNC);
        PlayerWinImage->Visible = true;
        Application->ProcessMessages(); Sleep(9000);
}
//---------------------------------------------------------------------------

void serveBall()
{
        if(doesPlayer1Serve)
        {
                MatchBoardForm->BallImage->Left = 56;
                xBall = 15;
                yBall = 15;
        }
        else
        {
                MatchBoardForm->BallImage->Left = 808;
                xBall = -15;
                yBall = -15;
        }
        MatchBoardForm->BallImage->Top = random(MatchBoardForm->CourtImage->Height - MatchBoardForm->BallImage->Height) + MatchBoardForm->CourtImage->Top;
        MatchBoardForm->BallImage->Visible = true;
        MatchBoardForm->BallTimer->Enabled = true;
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
        else if(BallImage->Top + BallImage->Height >= CourtImage->Top + CourtImage->Height) yBall = -yBall;

        if((BallImage->Top + BallImage->Height/2 >= Racket1Image->Top) && (BallImage->Top + BallImage->Height/2 <= Racket1Image->Top + Racket1Image->Height) && (BallImage->Left - 15 <= Racket1Image->Left + Racket1Image->Width))
        {
                sndPlaySound("snd/Player1.wav", SND_ASYNC);
                bounceBall(Racket1Image);
        }
        else if((BallImage->Top + BallImage->Height/2 >= Racket2Image->Top) && (BallImage->Top + BallImage->Height/2 <= Racket2Image->Top + Racket2Image->Height) && (BallImage->Left + BallImage->Width + 15 >= Racket2Image->Left))
        {
                sndPlaySound("snd/Player2.wav", SND_ASYNC);
                bounceBall(Racket2Image);
        }
        else if((BallImage->Left + BallImage->Width <= Racket1Image->Left) || (BallImage->Left >= Racket2Image->Left + Racket2Image->Width))
        {
                sndPlaySound("snd/Win.wav", SND_ASYNC);
                BallTimer->Enabled = false;
                BallImage->Visible = false;
                if(BallImage->Left >= Racket2Image->Left + Racket2Image->Width)
                {
                        Player1PointImage->Visible = true;
                        player1Points++;
                        if(isGameWon(player1Points, player2Points))
                        {
                                player1Games++;
                                GamesLabel->Caption = IntToStr(player1Games) + " : " + IntToStr(player2Games);
                                if(isGameOver(player1Games, player2Games))
                                {
                                        viewWinPlayer(Player1PointImage, Player1WinImage);
                                        return;
                                }
                                startNextRound();
                        }
                }
                else
                {
                        Player2PointImage->Visible = true;
                        player2Points++;
                        if(isGameWon(player2Points, player1Points))
                        {
                                player2Games++;
                                GamesLabel->Caption = IntToStr(player1Games) + " : " + IntToStr(player2Games);
                                if(isGameOver(player2Games, player1Games))
                                {
                                        viewWinPlayer(Player2PointImage, Player2WinImage);
                                        return;
                                }
                                startNextRound();
                        }
                }
                SetsLabel->Caption = viewScore(player1Points) + " : " + viewScore(player2Points);
                Application->ProcessMessages(); Sleep(2500);
                Player1PointImage->Visible = false;
                Player2PointImage->Visible = false;
                serveBall();
        }

}
//---------------------------------------------------------------------------

void __fastcall TMatchBoardForm::FormCreate(TObject *Sender)
{
        randomize();
}
//---------------------------------------------------------------------------


void __fastcall TMatchBoardForm::StartGameButtonClick(TObject *Sender)
{
        StartGameButton->Visible = false;
        Application->ProcessMessages(); Sleep(800);
        BallTimer->Enabled = true;
}
//---------------------------------------------------------------------------

