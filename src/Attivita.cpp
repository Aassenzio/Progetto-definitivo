#include "Attivita.h"

Attivita::Attivita(wxString nuovoNome, GiornoDelCalendario nuovaData, int ID, wxString nuovaDescrizione, Orario inizio, Orario fine) :
        nome(nuovoNome), data(nuovaData),
        ID(ID), descrizione(nuovaDescrizione), inizioAtt(inizio), fineAtt(fine) {};

void Attivita::aggiungiNome(wxString nuovoNome) {
    nome = nuovoNome;
}


wxString Attivita::getNome()const {
    return nome;
}

GiornoDelCalendario Attivita::getData()const {
    return data;
}

int Attivita::getId()const {
    return ID;
}

wxString Attivita::getDescrizione()const {
    return descrizione;
}



wxString Attivita::getOrarioStringaCompleto() {
    wxString orarioInizioStringa = inizioAtt.getOrarioStringa();
    wxString orarioFineStringa = fineAtt.getOrarioStringa();
    wxString orarioStringaFinale = "Inizio " + orarioInizioStringa + " Fine " + orarioFineStringa;
    return orarioStringaFinale;
}

wxString Attivita::getStringaData() {
    wxString stringaData = wxString::Format(wxT("%i/%i/%i"), data.getGiorno(), data.getMese(), data.getAnno());
    return stringaData;
}

int Attivita::getNumeroRigheDescrizione() {
    int contatoreLinee = 1;
    for (size_t iter = 0; iter < descrizione.length(); ++iter) {
        if (descrizione[iter] == '\n') {
            contatoreLinee++;
        }
    }
    return contatoreLinee;
}