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
    sceltaMese= new wxSpinCtrl(pannello, wxID_ANY,"", wxPoint(150,200), wxSize(-1, -1));
    sceltaMese->SetRange(1,12);

    sceltaGiorno= new wxSpinCtrl(pannello, wxID_ANY,"",wxPoint(100,200), wxSize(-1, -1));
    sceltaGiorno->SetRange(1,31);

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
    //inserisco evento per cambio anno
    sceltaAnno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaMese, this);
    sceltaMese->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaMese, this);
    sceltaGiorno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaMese, this);
};

void MyFrame::OnButtonClick(wxCommandEvent& evt){
    int giornoSelezionato = sceltaGiorno->GetValue();
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    wxString messaggio = wxString::Format("Ricerca effettuata per: %d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    SetStatusText(messaggio);
    }
    //funzione che controlla se anno bisestile
bool MyFrame::IsBisestile(){
    int annoSelezionato = sceltaAnno->GetValue();
    if (annoSelezionato % 4 ==0 && annoSelezionato % 100 != 0)
        return true;
        else return false;
}

void MyFrame::OnModificaMese(wxCommandEvent& evt){
    int meseSelezionato = sceltaMese->GetValue();
    switch(meseSelezionato) {
        case 2:
        if (MyFrame::IsBisestile())
            sceltaGiorno->SetRange(1, 29);
        else
            sceltaGiorno->SetRange(1, 28);
        break;
        case 4: case 6: case 9: case 11:
            sceltaGiorno->SetRange(1, 30);
        break;
        default:
            sceltaGiorno->SetRange(1, 31);
        break;
    }
}

