#include "Attivita.h"

Attivita::Attivita(wxString nuovoNome): nome(nuovoNome){};

void Attivita::AggiungiDescrizione(std::string nuovaDescrizione) {
    descrizione = nuovaDescrizione;
}

void Attivita::AggiungiNome(std::string nuovoNome) {
    nome = nuovoNome;
}
/*
void Attivita::AggiungiOrario(orario inizio, orario fine) {
    oraInizio = inizio;
    oraFine = fine;
}*/
void Attivita::ShowAttivita(wxArrayString* arrayDeiNomi) {
    arrayDeiNomi->Add(nome);
}