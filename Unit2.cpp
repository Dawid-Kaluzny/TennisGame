//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionsForm *OptionsForm;
        AnsiString n;
//---------------------------------------------------------------------------
__fastcall TOptionsForm::TOptionsForm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TOptionsForm::OptionsButtonClick(TObject *Sender)
{
        MatchBoardForm->PlayerName1Label->Caption = OptionsForm->Player1NameEdit->Text;
        MatchBoardForm->PlayerName2Label->Caption = OptionsForm->Player2NameEdit->Text;
        OptionsForm->Visible = false;
}
//---------------------------------------------------------------------------
