#include "Attivita.h"

Attivita::Attivita(std::string nuovoNome, GiornoDelCalendario nuovaData, int ID, wxString nuovaDescrizione, Orario inizio, Orario fine) :
        nome(nuovoNome), data(nuovaData),
        ID(ID), descrizione(nuovaDescrizione), inizioAtt(inizio), fineAtt(fine) {};

void Attivita::aggiungiNome(wxString nuovoNome) {
    nome = nuovoNome;
}


std::string Attivita::getNome()const {
    return nome;
}

GiornoDelCalendario Attivita::getData()const {
    return data;
}

int Attivita::getId()const {
    return ID;
}

std::string Attivita::getDescrizione()const {
    return descrizione;
}



std::string Attivita::getOrarioStringaCompleto() {
    std::string orarioInizioStringa = inizioAtt.toString();
    std::string orarioFineStringa = fineAtt.toString();
    std::string orarioStringaFinale = "Inizio " + orarioInizioStringa + " Fine " + orarioFineStringa;
    return orarioStringaFinale;
}

std::string Attivita::getStringaData()const {
    std::string stringaData = std::to_string(data.getGiorno()) + "/" +
                              std::to_string(data.getMese()) + "/" +
                              std::to_string(data.getAnno());
    return stringaData;
}

int Attivita::getNumeroRigheDescrizione() const{
    int contatoreLinee = 1;
    for (size_t iter = 0; iter < descrizione.length(); ++iter) {
        if (descrizione[iter] == '\n') {
            contatoreLinee++;
        }
    }
    return contatoreLinee;
}