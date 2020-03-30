//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TOptionsForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *Player1NameEdit;
        TImage *Player1Image;
        TLabel *Player1NameLabel;
        TImage *Player2Image;
        TLabel *Player2NameLabel;
        TEdit *Player2NameEdit;
        TButton *OptionsButton;
        TImage *Background;
        void __fastcall OptionsButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOptionsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsForm *OptionsForm;
//---------------------------------------------------------------------------
#endif
