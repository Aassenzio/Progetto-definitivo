
#ifndef PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#define PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Utility.h"
#include "Registro.h"
#include "FinestraDiModifica.h"
#include "GiornoDelCalendario.h"
class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title);

    Registro *GetRegisterAddress();

private:
    Registro *registroAttivita;

    void OnButtonSearchClick(wxCommandEvent &evt);

    void OnModificaData(wxCommandEvent &evt);

    //  void OnButtonSaveClick(wxCommandEvent& evt);
    // void OnButtonApplyClick(wxCommandEvent& evt);
    wxSpinCtrl *sceltaGiorno = nullptr;
    wxSpinCtrl *sceltaMese = nullptr;
    wxSpinCtrl *sceltaAnno = nullptr;
    wxButton *bottoneModifica = nullptr;
    wxButton *bottoneDiConfermaModifiche = nullptr;
    wxPanel *pannello = nullptr;
};

#endif //PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
