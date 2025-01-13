#include "FinestraDiAggiunta.h"

FinestraDiAggiunta::FinestraDiAggiunta(const wxString &title, Registro *registro, GiornoDelCalendario data) :
                                      wxFrame(nullptr, wxID_ANY,title),registroAttivita(registro),
                                      dataAttivitaDaAggiungere(data),testoNome(nullptr),testoDescrizione(nullptr),
                                      bottoneSalvaNuovaAttivita(nullptr),pannelloFinestraAggiunta(nullptr),
                                      oraFine(nullptr),oraInizio(nullptr),bottoneAnnulla(nullptr),minutoFine(nullptr),
                                      minutoInizio(nullptr) {
    pannelloFinestraAggiunta = new wxPanel(this);
    wxStaticText *sopraNome = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Nome", wxPoint(50, 30),
                                               wxSize(-1, -1));

    testoNome = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui il nome", wxPoint(50, 50), wxSize(150, 25));
    testoNome->SetMaxLength(23);

    wxStaticText *sopraDescrizione = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Descrizione",
                                                      wxPoint(50, 100), wxSize(-1, -1));
    testoDescrizione = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui la descrizione",
                                          wxPoint(50, 125), wxSize(170, 170) ,wxTE_MULTILINE );

    bottoneSalvaNuovaAttivita = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Salva", wxPoint(350, 280), wxSize(70, 25));
    bottoneAnnulla = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Annulla", wxPoint(275, 280), wxSize(70, 25));

    wxStaticText *sopraInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Orario inizio:", wxPoint(275, 50),
                                                 wxSize(-1, -1));
    wxStaticText *sopraOraInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Ora", wxPoint(275, 75),
                                                    wxSize(-1, -1));

    oraInizio = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(275, 100), wxSize(-1, -1));
    oraInizio->SetRange(0, 23);

    wxStaticText *sopraMinutiInizio = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Minuti", wxPoint(325, 75),
                                                       wxSize(-1, -1));
    minutoInizio = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(325, 100), wxSize(-1, -1));
    minutoInizio->SetRange(0, 59);

    wxStaticText *sopraFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Orario fine:", wxPoint(275, 150),
                                               wxSize(-1, -1));
    wxStaticText *sopraOraFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Ora", wxPoint(275, 175),
                                                  wxSize(-1, -1));

    oraFine = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(275, 200), wxSize(-1, -1));
    oraFine->SetRange(0, 23);

    wxStaticText *sopraminutoFine = new wxStaticText(pannelloFinestraAggiunta, wxID_ANY, "Minuti", wxPoint(325, 175),
                                                     wxSize(-1, -1));

    minutoFine = new wxSpinCtrl(pannelloFinestraAggiunta, wxID_ANY, "", wxPoint(325, 200), wxSize(-1, -1));
    minutoFine->SetRange(0, 59);

    bottoneSalvaNuovaAttivita->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::onBottoneSave, this);
    bottoneAnnulla->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::onBottoneAnnulla, this);
    oraInizio->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onCambioOra, this);
    minutoInizio->Bind(wxEVT_SPINCTRL, &FinestraDiAggiunta::onCambioOra, this);

};
//evento associato al tasto salva che prende i parametri inseriti e li aggiunge al registro
void FinestraDiAggiunta::onBottoneSave(wxCommandEvent &evt) {
    wxString nuovaDescrizione = testoDescrizione->GetLineText(0);

    for(int iter = 1; iter < (testoDescrizione->GetNumberOfLines()); iter ++ ){
        nuovaDescrizione.Append("\n");
        nuovaDescrizione.Append(testoDescrizione->GetLineText(iter));
    }
    //wxString nuovaDescrizione = testoDescrizione->GetLineText(0);
    Orario orarioInizioAttivita(oraInizio->GetValue(), minutoInizio->GetValue());
    Orario orarioFineAttivita(oraFine->GetValue(), minutoFine->GetValue());
    registroAttivita->addAttivita((testoNome->GetLineText(0)).ToStdString(), dataAttivitaDaAggiungere, nuovaDescrizione,
                                  orarioInizioAttivita, orarioFineAttivita);
    wxMessageBox("L'attivita' salvata correttamente!", "Conferma Salvataggio", wxOK | wxICON_INFORMATION, this);
    this->Close();
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