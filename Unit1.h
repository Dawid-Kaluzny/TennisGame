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
class TMatchBoard : public TForm
{
__published:	// IDE-managed Components
        TImage *Court;
        TImage *Fans;
        TImage *CourtBackground;
        TLabel *Label1;
        TLabel *Label2;
        TImage *ScoreBoard;
        TImage *Image1;
        TImage *Image2;
        TLabel *Label4;
        TLabel *Label3;
private:	// User declarations
public:		// User declarations
        __fastcall TMatchBoard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMatchBoard *MatchBoard;
//---------------------------------------------------------------------------
#endif
 