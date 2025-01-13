
#ifndef PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#define PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#include <ctime>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Registro.h"
#include "FinestraVisualizzaGriglia.h"
#include "GiornoDelCalendario.h"
class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title);


private:

    void onButtonSearchDateClick(wxCommandEvent &evt);

    void onButtonSearchNameClick(wxCommandEvent &evt);

    void onModificaData(wxCommandEvent &evt);

    Registro *registroAttivita;
    wxSpinCtrl *sceltaGiorno;
    wxSpinCtrl *sceltaMese ;
    wxSpinCtrl *sceltaAnno ;
    wxButton *bottoneDiRicercaData;
    wxButton *bottoneDiRicercaNome;
    wxTextCtrl *casellaRicercaNome;
    wxStaticText *testoDiBenvenuto;
    wxStaticText *testoSopraMese;
    wxStaticText *testoSopraGiorno;
    wxStaticText *testoSopraAnno;
    wxPanel *pannello;
};

#endif //PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
