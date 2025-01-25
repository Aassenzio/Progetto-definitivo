#include "Registro.h"

Registro::Registro() : contatoreAssoluto(
        0) {}//il contatore assoluto inizalizzato a 0 va solo avanti anche in caso di eliminazione


std::vector<Attivita*> Registro::searchDate(const GiornoDelCalendario& dataCercata) {
    std::vector<Attivita*> vettoreTrovati;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if (vettoreAttivita[iter]) { // in caso non ci sia nulla in questa posizione salta l'iterazione
            if ((vettoreAttivita[iter]->getData()) == dataCercata) {
                vettoreTrovati.push_back(vettoreAttivita[iter]);
            }
        }
    }
    return vettoreTrovati;
}

std::vector<Attivita*> Registro::searchName(const std::string& nomeCercato) {
    std::vector<Attivita*> vettoreTrovati;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if (vettoreAttivita[iter]) {
            if ((vettoreAttivita[iter]->getNome()).find(nomeCercato) != std::string::npos) {
                vettoreTrovati.push_back(vettoreAttivita[iter]);
            }
        }
    }
    return vettoreTrovati;
}

void Registro::addAttivita(const std::string &nome, const GiornoDelCalendario &data, const std::string &descrizione,
                           const Orario &inizio, const Orario &fine) {
    vettoreAttivita.push_back(new Attivita(nome, data, contatoreAssoluto, descrizione, inizio,
                                           fine));
    contatoreAssoluto++;
}

void Registro::eliminaAttivita(const int &ID) {
    delete vettoreAttivita[ID];
    vettoreAttivita[ID] = nullptr;
}