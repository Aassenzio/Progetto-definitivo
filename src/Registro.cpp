#include "Registro.h"

Registro::Registro(): contatoreAssoluto(0){}//il contatore assoluto inizalizzato a 0 va solo avanti anche in caso di eliminazione


int Registro::searchDate(GiornoDelCalendario dataCercata, std::vector<Attivita*> *listaTrovati) {
    int contatoreTrovati = 0;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if(vettoreAttivita[iter]) { // in caso non ci sia nulla in questa posizione salta l'iterazione
        if ((vettoreAttivita[iter]->getData()).comparaData(dataCercata)) {
            listaTrovati->push_back(vettoreAttivita[iter]);
            contatoreTrovati++;
            }
        }
    }
    return contatoreTrovati;
}


void Registro::addAttivita(std::string nome, GiornoDelCalendario data, wxString descrizione, Orario inizio,
                           Orario fine) {
    vettoreAttivita.push_back(new Attivita(nome, data, contatoreAssoluto, descrizione, inizio,
                                           fine));
    contatoreAssoluto++;
}

void Registro::eliminaAttivita(int ID) {
    delete vettoreAttivita[ID];
    vettoreAttivita[ID] = nullptr;
}