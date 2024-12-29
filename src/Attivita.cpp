#include "Attivita.h"

Attivita::Attivita(wxString nuovoNome, int nuovaData, int ID, wxString nuovaDescrizione, Orario inizio, Orario fine):
                nome(nuovoNome), data(nuovaData),
                ID(ID), descrizione(nuovaDescrizione), inizioAtt(inizio), fineAtt(fine){};

void Attivita::AggiungiNome(wxString nuovoNome){
    nome = nuovoNome;
}
wxString Attivita::MostraNome() {
    return nome;
}
int Attivita::MostraData() {
    return data;
}
int Attivita::MostraID() {
    return ID;
}
wxString Attivita::MostraDescrizione() {
    return descrizione;
}

void Attivita::ShowAttivita(wxArrayString* arrayDeiNomi) {
    arrayDeiNomi->Add(nome);
}