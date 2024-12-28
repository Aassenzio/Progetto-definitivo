
#include "finestra.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

#include <wx/file.h>

MyFrame::MyFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title ){
    pannello = new wxPanel(this);
    registroAttivita = new Registro;
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
//funzione del bottone che cerca il giorno
void MyFrame::OnButtonSearchClick(wxCommandEvent& evt){
    int giornoSelezionato = sceltaGiorno->GetValue();// Prende i valori per compattare la data
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    wxArrayString scelte; //array che contiene i nomi delle attivita
    scelte.Add("Aggiungi Nuova Attivita'");
    int dataEstesaSelezionata = CompattaData(annoSelezionato, meseSelezionato, giornoSelezionato);
    registroAttivita->searchDate(dataEstesaSelezionata, &scelte); //cerco nel registro il giorno corrispondente
    wxString dataEstesaStringa = wxString::Format("%d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    wxStaticText* dataSopraAttivita = new wxStaticText(pannello, wxID_ANY, dataEstesaStringa,
                                                       wxPoint(100, 275), wxSize (-1,-1));

        scelte.Add("item 2");
        listBoxDiProva = new wxListBox(pannello, wxID_ANY, wxPoint(100, 300), wxSize(-1, -1), scelte);
        wxButton* bottoneSalva = new wxButton(pannello, wxID_ANY, "Modifica", wxPoint(400, 300), wxSize(-1, -1));
        bottoneSalva->Bind(wxEVT_BUTTON, &MyFrame::OnButtonSaveClick, this);

    wxString messaggio = wxString::Format("Ricerca effettuata per: %d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    SetStatusText(messaggio);
    }
//bottone che salva il contenuto della casella di testo
void MyFrame::OnButtonSaveClick(wxCommandEvent& evt){
        wxString contenutoCasellaTesto = "Funziona ";
        wxFile file("output.txt", wxFile::write);
        if (file.IsOpened()) {
            file.Write(contenutoCasellaTesto);
            file.Close();
            wxLogMessage("Testo salvato su file.");
        } else {
            wxLogError("Impossibile aprire il file per la scrittura.");
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

