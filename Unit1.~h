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
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TMatchBoardForm : public TForm
{
__published:	// IDE-managed Components
        TImage *FansImage;
        TImage *CourtBackgroundImage;
        TLabel *SetsLabel;
        TLabel *GamesLabel;
        TImage *ScoreBoardImage;
        TImage *Player1Image;
        TImage *Player2Image;
        TLabel *PlayerName1Label;
        TLabel *PlayerName2Label;
        TImage *Racket1Image;
        TImage *Racket2Image;
        TTimer *Player1UpTimer;
        TTimer *Player1DownTimer;
        TTimer *Player2UpTimer;
        TTimer *Player2DownTimer;
        TImage *CourtImage;
        TImage *BallImage;
        TTimer *BallTimer;
        TImage *Player2PointImage;
        TImage *Player1PointImage;
        TImage *Player1WinImage;
        TImage *Player2WinImage;
        TButton *StartGameButton;
        void __fastcall Player1UpTimerTimer(TObject *Sender);
        void __fastcall Player1DownTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Player2UpTimerTimer(TObject *Sender);
        void __fastcall Player2DownTimerTimer(TObject *Sender);
        void __fastcall BallTimerTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall StartGameButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMatchBoardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMatchBoardForm *MatchBoardForm;
//---------------------------------------------------------------------------
#endif
 