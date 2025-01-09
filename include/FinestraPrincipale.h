
#ifndef PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#define PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
#include <ctime>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "ControlloAnno.h"
#include "Registro.h"
#include "FinestraVisualizzaGriglia.h"
#include "GiornoDelCalendario.h"
class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title);


private:

    void onButtonSearchClick(wxCommandEvent &evt);

    void onModificaData(wxCommandEvent &evt);

    Registro *registroAttivita;
    wxSpinCtrl *sceltaGiorno;
    wxSpinCtrl *sceltaMese ;
    wxSpinCtrl *sceltaAnno ;
    wxButton *bottoneDiRicerca;
    wxStaticText *testoDiBenvenuto;
    wxStaticText *testoSopraMese;
    wxStaticText *testoSopraGiorno;
    wxStaticText *testoSopraAnno;
    wxPanel *pannello;
};

#endif //PROGETTODEFINITIVO_FINESTRAPRINCIPALE_H
