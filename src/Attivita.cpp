#include "Attivita.h"

void Attivita::AggiungiDescrizione(std::string nuovaDescrizione) {
    descrizione = nuovaDescrizione;
}

void Attivita::ShowAttivita() {
    std::cout<< nome;
}