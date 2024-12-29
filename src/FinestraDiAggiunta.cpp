#include "FinestraDiAggiunta.h"

FinestraDiAggiunta::FinestraDiAggiunta(const wxString &title, Registro* registro, int data ):wxFrame(nullptr, wxID_ANY, title ),
                                       registroAttivita(registro), dataAttivitaDaAggiungere(data), testoNome(nullptr),
                                       bottoneSalvaNuovaAttivita(nullptr), pannelloFinestraAggiunta(nullptr) {
    pannelloFinestraAggiunta = new wxPanel(this);
    if(!testoNome){
        testoNome = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui il nome", wxPoint(100,100),
                                   wxSize(-1, -1));
    }
    if(!testoDescrizione){
        testoDescrizione = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui la descrizione",
                                          wxPoint(100,200), wxSize(150, 200));
    }
    if(!bottoneSalvaNuovaAttivita){
        bottoneSalvaNuovaAttivita = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Salva", wxPoint(200, 100), wxSize(-1,-1));
    }
    bottoneSalvaNuovaAttivita->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::OnBottoneSave, this);
};
void FinestraDiAggiunta::OnBottoneSave(wxCommandEvent& evt) {
    wxString nuovoNome = testoNome->GetLineText(0);
    wxString nuovaDescrizione = testoDescrizione->GetLineText(0);
    registroAttivita->AddAttivita(nuovoNome, dataAttivitaDaAggiungere, nuovaDescrizione);
    this->Close();
    wxMessageBox("L'attivita' salvata correttamente!", "Conferma Salvataggio", wxOK | wxICON_INFORMATION, this);

}