
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
Registro* MyFrame::GetRegisterAddress() {
    return registroAttivita;
};
void MyFrame::OnButtonSearchClick(wxCommandEvent& evt){
    int giornoSelezionato = sceltaGiorno->GetValue();// Prende i valori per compattare la data
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    int dataEstesaSelezionata = CompattaData(annoSelezionato, meseSelezionato, giornoSelezionato);
   /* wxArrayString scelte; //array che contiene i nomi delle attivita
    //scelte.Insert("Aggiungi Nuova Attivita'",0);

    registroAttivita->searchDate(dataEstesaSelezionata, &scelte, dataCorrente); //cerco nel registro il giorno corrispondente
    wxString dataEstesaStringa = wxString::Format("%d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    wxStaticText* dataSopraAttivita = new wxStaticText(pannello, wxID_ANY, dataEstesaStringa,
                                                       wxPoint(100, 275), wxSize (-1,-1));
    if(!listBoxDiProva) {
        listBoxDiProva = new wxListBox(pannello, wxID_ANY, wxPoint(100, 300), wxSize(-1, -1), scelte);
    }else {
        delete listBoxDiProva;
        listBoxDiProva = new wxListBox(pannello, wxID_ANY, wxPoint(100, 300), wxSize(-1, -1), scelte);
    }
    if(!bottoneModifica) {
        bottoneModifica = new wxButton(pannello, wxID_ANY, "Modifica", wxPoint(400, 300), wxSize(-1, -1));
    }else{
        delete bottoneModifica;
        bottoneModifica = new wxButton(pannello, wxID_ANY, "Modifica", wxPoint(400, 300), wxSize(-1, -1));
    }
    bottoneModifica->Bind(wxEVT_BUTTON, &MyFrame::OnButtonSaveClick, this);

    wxString messaggio = wxString::Format("Ricerca effettuata per: %d/%d/%d", giornoSelezionato, meseSelezionato, annoSelezionato);
    SetStatusText(messaggio);
    */
    FrameSecondario* secondaFinestra =new FrameSecondario("Finestra Secondaria", registroAttivita, dataEstesaSelezionata);
    secondaFinestra->SetClientSize(800, 600);
    secondaFinestra->Center();
    secondaFinestra->Show();
    }
//bottone che salva il contenuto della casella di testo
void MyFrame::OnButtonSaveClick(wxCommandEvent& evt){
    wxString nomeAttSelezionata = listBoxDiProva->GetString(listBoxDiProva->GetSelection());
    if(!nomeAttivita) {
        nomeAttivita = new wxTextCtrl(pannello, wxID_ANY, nomeAttSelezionata, wxPoint(400, 400), wxSize(200, 30));
    }else {
        delete nomeAttivita;
        nomeAttivita = new wxTextCtrl(pannello, wxID_ANY, nomeAttSelezionata, wxPoint(400, 400), wxSize(200, 30));
    }
    if(!bottoneDiConfermaModifiche){
        bottoneDiConfermaModifiche = new wxButton(pannello, wxID_ANY, "Applica/Salva", wxPoint(400, 500),
                                                  wxSize(100,100));
    }
    bottoneDiConfermaModifiche->Bind(wxEVT_BUTTON, &MyFrame::OnButtonApplyClick, this);
     /*   wxString contenutoCasellaTesto = "Funziona ";
        wxFile file("output.txt", wxFile::write);
        if (file.IsOpened()) {
            file.Write(contenutoCasellaTesto);
            file.Close();
            wxLogMessage("Testo salvato su file.");
        } else {
            wxLogError("Impossibile aprire il file per la scrittura.");
        }*/
    }
    //prende il nome nella casella di testo e aggiorna l attivita
void MyFrame::OnButtonApplyClick(wxCommandEvent &evt) {
        wxString nomeAttuale  = listBoxDiProva->GetString(listBoxDiProva->GetSelection());
        wxString nomeNellCasella = nomeAttivita->GetLineText(0);
    if(listBoxDiProva->GetSelection() == 0) {
        dataCorrente->AddAttivita(Attivita(nomeNellCasella));
    }else {
        dataCorrente->EditAttivita(nomeAttuale , nomeNellCasella);

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

