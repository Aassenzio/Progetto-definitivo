#include "FinestraDiAggiunta.h"

FinestraDiAggiunta::FinestraDiAggiunta(const wxString &title, Registro* registro ):wxFrame(nullptr, wxID_ANY, title ),
                                       registroAttivita(registro), testoNome(nullptr), bottoneSalvaNuovaAttivita(nullptr), pannelloFinestraAggiunta(nullptr) {
    pannelloFinestraAggiunta = new wxPanel(this);
    if(!testoNome){
        testoNome = new wxTextCtrl(pannelloFinestraAggiunta, wxID_ANY, "Inserisci qui il nome", wxPoint(100,100),
                                   wxSize(-1, -1));
    }
    if(!bottoneSalvaNuovaAttivita){
        bottoneSalvaNuovaAttivita = new wxButton(pannelloFinestraAggiunta, wxID_ANY, "Salva", wxPoint(200, 100), wxSize(-1,-1));
    }
    bottoneSalvaNuovaAttivita->Bind(wxEVT_BUTTON, &FinestraDiAggiunta::OnBottoneSave, this);
};
void FinestraDiAggiunta::OnBottoneSave(wxCommandEvent& evt) {
    wxString nuovoNome = testoNome->GetLineText(0);
    registroAttivita->AddAttivita(nuovoNome);
}