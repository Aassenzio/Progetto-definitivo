#include "Attivita.h"

void Attivita::AggiungiDescrizione(std::string nuovaDescrizione) {
    descrizione = nuovaDescrizione;
}

void Attivita::AggiungiNome(std::string nuovoNome) {
    nome = nuovoNome;
}

void Attivita::AggiungiOrario(orario inizio, orario fine) {
    oraInizio = inizio;
    oraFine = fine;
}
void Attivita::ShowAttivita() {
    std::cout<< nome << std::endl;
}