#include "FinestraDiAggiunta.h"

FinestraDiAggiunta::FinestraDiAggiunta(const wxString &title, Registro *registro, GiornoDelCalendario data, std::string nome) :
                                      wxFrame(nullptr, wxID_ANY,title),registroAttivita(registro),
                                      dataAttivitaDaAggiungere(data),testoNome(nullptr),testoDescrizione(nullptr),
                                      bottoneSalvaNuovaAttivita(nullptr),pannelloFinestraAggiunta(nullptr),
                                      oraFine(nullptr),oraInizio(nullptr),bottoneAnnulla(nullptr),minutoFine(nullptr),
                                      minutoInizio(nullptr), sceltaAnnoAggiunta(nullptr), sceltaGiornoAggiunta(nullptr),
                                      sceltaMeseAggiunta(nullptr), nomeDaAggiungere(nome){
    pannelloFinestraAggiunta = new wxPanel(this);
    wxStaticText *sopraNome = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Nome", wxPoint(50, 25),
                                               wxSize(-1, -1));

    testoNome = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, nomeDaAggiungere, wxPoint(50, 45), wxSize(150, 25));
    testoNome->SetMaxLength(23);

    wxStaticText *sopraMese = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Mese", wxPoint(100,70));
    sceltaMeseAggiunta = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(100, 90), wxSize(-1, -1));
    sceltaMeseAggiunta->SetRange(1, 12);
    sceltaMeseAggiunta->SetValue(dataAttivitaDaAggiungere.getMese());

    wxStaticText *sopraGiorno = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Giorno", wxPoint(50,70));
    sceltaGiornoAggiunta = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(50, 90), wxSize(-1, -1));
    sceltaGiornoAggiunta->SetRange(1, 31);
    sceltaGiornoAggiunta->SetValue(dataAttivitaDaAggiungere.getGiorno());

    wxStaticText *sopraAnno = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Anno", wxPoint(150,70));
    sceltaAnnoAggiunta = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, " ", wxPoint(150, 90), wxSize(80, -1));
    sceltaAnnoAggiunta->SetRange(1900, 2100);
    sceltaAnnoAggiunta->SetValue(dataAttivitaDaAggiungere.getAnno());


    wxStaticText *sopraDescrizione = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Descrizione",
                                                      wxPoint(50, 125), wxSize(-1, -1));
    testoDescrizione = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui la descrizione",
                                          wxPoint(50, 150), wxSize(170, 170) ,wxTE_MULTILINE );

    bottoneSalvaNuovaAttivita = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Salva", wxPoint(350, 305), wxSize(70, 25));
    bottoneAnnulla = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Annulla", wxPoint(275, 305), wxSize(70, 25));

    wxStaticText *sopraInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Orario inizio:", wxPoint(275, 75),
                                                 wxSize(-1, -1));
    wxStaticText *sopraOraInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Ora", wxPoint(275, 100),
                                                    wxSize(-1, -1));

    oraInizio = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(275, 125), wxSize(-1, -1));
    oraInizio->SetRange(0, 23);

    wxStaticText *sopraMinutiInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Minuti", wxPoint(325, 100),
                                                       wxSize(-1, -1));
    minutoInizio = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(325, 125), wxSize(-1, -1));
    minutoInizio->SetRange(0, 59);

    wxStaticText *sopraFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Orario fine:", wxPoint(275, 175),
                                               wxSize(-1, -1));
    wxStaticText *sopraOraFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Ora", wxPoint(275, 200),
                                                  wxSize(-1, -1));

    oraFine = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(275, 225), wxSize(-1, -1));
    oraFine->SetRange(0, 23);

    wxStaticText *sopraminutoFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Minuti", wxPoint(325, 200),
                                                     wxSize(-1, -1));

    minutoFine = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(325, 225), wxSize(-1, -1));
    minutoFine->SetRange(0, 59);

    bottoneSalvaNuovaAttivita->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::onBottoneSave, this);
    bottoneAnnulla->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::onBottoneAnnulla, this);
    oraInizio->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onCambioOra, this);
    minutoInizio->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onCambioOra, this);
    sceltaAnnoAggiunta->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onModificaDataDiAggiunta, this);
    sceltaMeseAggiunta->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onModificaDataDiAggiunta, this);
    sceltaGiornoAggiunta->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onModificaDataDiAggiunta, this);

};
//evento associato al tasto salva che prende i parametri inseriti e li aggiunge al registro
void FinestraDiAggiunta::onBottoneSave(wxCommandEvent &evt) {
    std::string nuovaDescrizione = (testoDescrizione->GetLineText(0)).ToStdString();

    for(int iter = 1; iter < (testoDescrizione->GetNumberOfLines()); iter ++ ){
        nuovaDescrizione.append("\n");
        nuovaDescrizione.append((testoDescrizione->GetLineText(iter)).ToStdString());
    }
    try {
        Orario orarioInizioAttivita(oraInizio->GetValue(), minutoInizio->GetValue());
        Orario orarioFineAttivita(oraFine->GetValue(), minutoFine->GetValue());
        GiornoDelCalendario giornoAggiunta(sceltaGiornoAggiunta->GetValue(), sceltaMeseAggiunta->GetValue(),
                                           sceltaAnnoAggiunta->GetValue());
        registroAttivita->addAttivita((testoNome->GetLineText(0)).ToStdString(), giornoAggiunta,
                                      nuovaDescrizione,
                                      orarioInizioAttivita, orarioFineAttivita);
        wxMessageBox("L'attivita' salvata correttamente!", "Conferma Salvataggio", wxOK | wxICON_INFORMATION, this);
        this->Close();
    }
    catch (const std::invalid_argument& e){
        wxMessageBox(wxString(e.what()), "Errore", wxOK | wxICON_ERROR, this);
    }

}

void FinestraDiAggiunta::onBottoneAnnulla(wxCommandEvent &evt) {
    this->Close();
}
//funzione che controlla dinamicamente che l'orario inserito di fine attivita non sia antecendente all'orario di inizio
void FinestraDiAggiunta::onCambioOra(wxCommandEvent &evt) {
    oraFine->SetRange(oraInizio->GetValue(), 23);
    if (oraInizio->GetValue() == oraFine->GetValue()) {
        minutoFine->SetRange(minutoInizio->GetValue(), 59);
    } else minutoFine->SetRange(0, 59);


}

void FinestraDiAggiunta::onModificaDataDiAggiunta(wxCommandEvent &evt) {
    int meseSelezionato = sceltaMeseAggiunta->GetValue();
    int annoSelezionato = sceltaAnnoAggiunta->GetValue();
    switch (meseSelezionato) {
        case 2:
            if (GiornoDelCalendario::isBisestile(annoSelezionato))
                sceltaGiornoAggiunta->SetRange(1, 29);
            else
                sceltaGiornoAggiunta->SetRange(1, 28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sceltaGiornoAggiunta->SetRange(1, 30);
            break;
        default:
            sceltaGiornoAggiunta->SetRange(1, 31);
            break;
    }
}