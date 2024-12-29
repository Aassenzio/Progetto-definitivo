#include "Attivita.h"

Attivita::Attivita(wxString nuovoNome, int nuovaData, int ID, wxString nuovaDescrizione): nome(nuovoNome), data(nuovaData),
                ID(ID), descrizione(nuovaDescrizione){};

/*void Attivita::AggiungiDescrizione(std::string nuovaDescrizione) {
    descrizione = nuovaDescrizione;
}*/

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
/*
void Attivita::AggiungiOrario(orario inizio, orario fine) {
    oraInizio = inizio;
    oraFine = fine;
}*/
void Attivita::ShowAttivita(wxArrayString* arrayDeiNomi) {
    arrayDeiNomi->Add(nome);
}