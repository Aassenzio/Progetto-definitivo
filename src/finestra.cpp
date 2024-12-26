#include "finestra.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MyFrame::MyFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title ){
    wxPanel* pannello = new wxPanel(this);
    wxStaticText* testoDiBenvenuto= new wxStaticText(pannello, wxID_ANY, "Scegli il giorno di cui vuoi visualizzare le attivita",
                                                     wxPoint(100,150), wxSize(-1,-1));
wxArrayString listaGiorni; //inizializza la lista dei giorni
int iterator;
for(iterator=1; iterator<=31;iterator++) {
    listaGiorni.Add(wxString::Format("%d", iterator));
}
wxArrayString listaMesi; //inizializza la lista dei mesi
    for(iterator=1; iterator<=12;iterator++) {
        listaMesi.Add(wxString::Format("%d", iterator));
    }
    sceltaMese= new wxChoice(pannello, wxID_ANY, wxPoint(150,200), wxSize(-1, -1), listaMesi);
    sceltaMese->Select(0);

    sceltaGiorno= new wxChoice(pannello, wxID_ANY, wxPoint(100,200), wxSize(-1, -1), listaGiorni);
    sceltaGiorno->Select(0);

    sceltaAnno= new wxSpinCtrl(pannello, wxID_ANY," ",wxPoint(200,200), wxSize(80, -1));
    sceltaAnno->SetRange(1900, 2100);

    wxButton* bottoneDiRicerca = new wxButton(pannello, wxID_ANY, "Cerca", wxPoint(480, 200),wxSize(-1, -1));

    CreateStatusBar();

    bottoneDiRicerca->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);

    wxStaticText* testoSopraMese = new wxStaticText(pannello, wxID_ANY, "Mese",
                                                    wxPoint(150,180), wxSize(-1,-1));
    wxStaticText* testoSopraGirono = new wxStaticText(pannello, wxID_ANY, "Giorno",
                                                    wxPoint(100,180), wxSize(-1,-1));
    wxStaticText* testoSopraAnno = new wxStaticText(pannello, wxID_ANY, "Anno",
                                                    wxPoint(200,180), wxSize(-1,-1));
};

    void MyFrame::OnButtonClick(wxCommandEvent& evt){
        wxString giornoSelezionato = sceltaGiorno->GetString(sceltaGiorno->GetSelection());
        wxString meseSelezionato = sceltaMese->GetString(sceltaMese->GetSelection());
        int annoSelezionato = sceltaAnno->GetValue();
        wxString messaggio = wxString::Format("Ricerca effettuata per: %s/%s/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
        SetStatusText(messaggio);
    }

