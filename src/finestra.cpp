
#include "finestra.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

#include <wx/file.h>

MyFrame::MyFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    pannello = new wxPanel(this);
    registroAttivita = new Registro;
    wxStaticText *testoDiBenvenuto = new wxStaticText(pannello, wxID_ANY,
                                                      "Seleziona il giorno di cui vuoi visualizzare le attivita",
                                                      wxPoint(50, 20), wxSize(-1, -1));
    sceltaMese = new wxSpinCtrl(pannello, wxID_ANY, "", wxPoint(100, 75), wxSize(-1, -1));
    sceltaMese->SetRange(1, 12);

    sceltaGiorno = new wxSpinCtrl(pannello, wxID_ANY, "", wxPoint(50, 75), wxSize(-1, -1));
    sceltaGiorno->SetRange(1, 31);

    sceltaAnno = new wxSpinCtrl(pannello, wxID_ANY, " ", wxPoint(150, 75), wxSize(80, -1));
    sceltaAnno->SetRange(1900, 2100);

    wxButton *bottoneDiRicerca = new wxButton(pannello, wxID_ANY, "Cerca", wxPoint(250, 75), wxSize(-1, -1));


    bottoneDiRicerca->Bind(wxEVT_BUTTON, &MyFrame::OnButtonSearchClick, this);

    wxStaticText *testoSopraMese = new wxStaticText(pannello, wxID_ANY, "Mese",
                                                    wxPoint(100, 50), wxSize(-1, -1));
    wxStaticText *testoSopraGirono = new wxStaticText(pannello, wxID_ANY, "Giorno",
                                                      wxPoint(50, 50), wxSize(-1, -1));
    wxStaticText *testoSopraAnno = new wxStaticText(pannello, wxID_ANY, "Anno",
                                                    wxPoint(150, 50), wxSize(-1, -1));
    //inserisco evento per cambio anno
    sceltaAnno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
    sceltaMese->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
    sceltaGiorno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
};

Registro *MyFrame::GetRegisterAddress() {
    return registroAttivita;
};

//funzione del bottone che cerca il giorno
void MyFrame::OnButtonSearchClick(wxCommandEvent &evt) {
    int giornoSelezionato = sceltaGiorno->GetValue();// Prende i valori per compattare la data
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    int dataEstesaSelezionata = CompattaData(annoSelezionato, meseSelezionato, giornoSelezionato);
    FrameSecondario *secondaFinestra = new FrameSecondario("Finestra Secondaria", registroAttivita,
                                                           dataEstesaSelezionata);
    secondaFinestra->SetClientSize(800, 600);
    secondaFinestra->Center();
    secondaFinestra->Show();
}

void MyFrame::OnModificaData(wxCommandEvent &evt) {
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    switch (meseSelezionato) {
        case 2:
            if (IsBisestile(annoSelezionato))
                sceltaGiorno->SetRange(1, 29);
            else
                sceltaGiorno->SetRange(1, 28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sceltaGiorno->SetRange(1, 30);
            break;
        default:
            sceltaGiorno->SetRange(1, 31);
            break;
    }
}

