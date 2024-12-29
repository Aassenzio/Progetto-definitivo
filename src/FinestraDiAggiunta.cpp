#include "FinestraDiAggiunta.h"

FinestraDiAggiunta::FinestraDiAggiunta(const wxString &title, Registro* registro, int data ):wxFrame(nullptr, wxID_ANY, title ),
                                       registroAttivita(registro), dataAttivitaDaAggiungere(data), testoNome(nullptr),
                                       bottoneSalvaNuovaAttivita(nullptr), pannelloFinestraAggiunta(nullptr),
                                       oraFine(nullptr), oraInizio(nullptr) , bottoneAnnulla(nullptr),
                                       minutoFine(nullptr), minutoInizio(nullptr){
    pannelloFinestraAggiunta = new wxPanel(this);
    if(!testoNome){
        testoNome = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui il nome", wxPoint(50,50),
                                   wxSize(150, 25));
    }
    if(!testoDescrizione){
        testoDescrizione = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui la descrizione",
                                          wxPoint(50,125), wxSize(200, 175));
    }
    if(!bottoneSalvaNuovaAttivita){
        bottoneSalvaNuovaAttivita = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Salva", wxPoint(350, 300), wxSize(70,25));
    }
    if(!bottoneAnnulla){
        bottoneAnnulla = new wxButton(pannelloFinestraAggiunta,wxID_ANY ,"Annulla", wxPoint(275, 300), wxSize(70,25) );
    }
    if(!oraInizio){
        oraInizio = new wxSpinCtrl(pannelloFinestraAggiunta,wxID_ANY, "", wxPoint(275, 150), wxSize(-1, -1));
        oraInizio->SetRange(0,23);
    }
    if(!minutoInizio){
        minutoInizio = new wxSpinCtrl(pannelloFinestraAggiunta,wxID_ANY, "", wxPoint(325, 150), wxSize(-1, -1));
        minutoInizio->SetRange(0,59);
    }
    if(!oraFine){
        oraFine = new wxSpinCtrl(pannelloFinestraAggiunta,wxID_ANY, "", wxPoint(275, 200), wxSize(-1, -1));
        oraFine->SetRange(0,23);
    }
    if(!minutoFine){
        minutoFine = new wxSpinCtrl(pannelloFinestraAggiunta,wxID_ANY, "", wxPoint(325, 200), wxSize(-1, -1));
        minutoFine->SetRange(0,59);
    }
    bottoneSalvaNuovaAttivita->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::OnBottoneSave, this);
    bottoneAnnulla->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::OnBottoneAnnulla, this);
    oraInizio->Bind(wxEVT_SPINCTRL , &FinestraDiAggiunta::OnCambioOra , this);
    minutoInizio->Bind(wxEVT_SPINCTRL , &FinestraDiAggiunta::OnCambioOra , this);
};
void FinestraDiAggiunta::OnBottoneSave(wxCommandEvent& evt) {
    wxString nuovaDescrizione = testoDescrizione->GetLineText(0);
    Orario orarioInizioAttivita(oraInizio->GetValue(), minutoInizio->GetValue());
    Orario orarioFineAttivita(oraFine->GetValue(), minutoFine->GetValue());
    registroAttivita->AddAttivita(testoNome->GetLineText(0), dataAttivitaDaAggiungere, nuovaDescrizione ,
                                  orarioInizioAttivita, orarioFineAttivita);
    this->Close();
    wxMessageBox("L'attivita' salvata correttamente!", "Conferma Salvataggio", wxOK | wxICON_INFORMATION, this);

}
void FinestraDiAggiunta::OnBottoneAnnulla(wxCommandEvent &evt) {
    this->Close();
}

void FinestraDiAggiunta::OnCambioOra(wxCommandEvent &evt) {
    oraFine->SetRange(oraInizio->GetValue(), 23);
    if(oraInizio->GetValue() == oraFine->GetValue()){
        minutoFine->SetRange(minutoInizio->GetValue(), 59);
    }else minutoFine->SetRange(0,59);


}