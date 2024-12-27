#include "finestra.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Utility.h"
#include <wx/file.h>

MyFrame::MyFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title ){
    pannello = new wxPanel(this);
    testoDiProva = nullptr;
    wxStaticText* testoDiBenvenuto= new wxStaticText(pannello, wxID_ANY, "Scegli il giorno di cui vuoi visualizzare le attivita",
                                                     wxPoint(100,150), wxSize(-1,-1));
    sceltaMese= new wxSpinCtrl(pannello, wxID_ANY,"", wxPoint(150,200), wxSize(-1, -1));
    sceltaMese->SetRange(1,12);

    sceltaGiorno= new wxSpinCtrl(pannello, wxID_ANY,"",wxPoint(100,200), wxSize(-1, -1));
    sceltaGiorno->SetRange(1,31);

    sceltaAnno= new wxSpinCtrl(pannello, wxID_ANY," ",wxPoint(200,200), wxSize(80, -1));
    sceltaAnno->SetRange(1900, 2100);

    wxButton* bottoneDiRicerca = new wxButton(pannello, wxID_ANY, "Cerca", wxPoint(480, 200),wxSize(-1, -1));

    CreateStatusBar();

    bottoneDiRicerca->Bind(wxEVT_BUTTON, &MyFrame::OnButtonSearchClick, this);

    wxStaticText* testoSopraMese = new wxStaticText(pannello, wxID_ANY, "Mese",
                                                    wxPoint(150,180), wxSize(-1,-1));
    wxStaticText* testoSopraGirono = new wxStaticText(pannello, wxID_ANY, "Giorno",
                                                    wxPoint(100,180), wxSize(-1,-1));
    wxStaticText* testoSopraAnno = new wxStaticText(pannello, wxID_ANY, "Anno",
                                                    wxPoint(200,180), wxSize(-1,-1));
    //inserisco evento per cambio anno
    sceltaAnno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
    sceltaMese->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
    sceltaGiorno->Bind(wxEVT_SPINCTRL, &MyFrame::OnModificaData, this);
};
//bottone che cerca il giorno
void MyFrame::OnButtonSearchClick(wxCommandEvent& evt){
    if(!testoDiProva) {
        testoDiProva = new wxTextCtrl(pannello, wxID_ANY, "Testo editabile",
                                      wxPoint(100, 300), wxSize(-1, -1));
        wxButton* bottoneSalva = new wxButton(pannello, wxID_ANY, "Salva", wxPoint(200, 300), wxSize(-1, -1));
        bottoneSalva->Bind(wxEVT_BUTTON, &MyFrame::OnButtonSaveClick, this);
    }
    int giornoSelezionato = sceltaGiorno->GetValue();// Prende i valori per compattare la data
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    wxString messaggio = wxString::Format("Ricerca effettuata per: %d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    SetStatusText(messaggio);
    }
//bottone che salva il contenuto della casella di testo
void MyFrame::OnButtonSaveClick(wxCommandEvent& evt){
    if(testoDiProva) {
        wxString contenutoCasellaTesto = testoDiProva->GetValue();
        wxFile file("output.txt", wxFile::write);
        if (file.IsOpened()) {
            file.Write(contenutoCasellaTesto);
            file.Close();
            wxLogMessage("Testo salvato su file.");
        } else {
            wxLogError("Impossibile aprire il file per la scrittura.");
        }
    }
}
void MyFrame::OnModificaData(wxCommandEvent& evt){
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    switch(meseSelezionato) {
        case 2:
        if (IsBisestile(annoSelezionato))
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

