#include "Attivita.h"

Attivita::Attivita(wxString nuovoNome, GiornoDelCalendario nuovaData, int ID, wxString nuovaDescrizione, Orario inizio, Orario fine) :
        nome(nuovoNome), data(nuovaData),
        ID(ID), descrizione(nuovaDescrizione), inizioAtt(inizio), fineAtt(fine) {};

void Attivita::AggiungiNome(wxString nuovoNome) {
    nome = nuovoNome;
}


wxString Attivita::MostraNome()const {
    return nome;
}

GiornoDelCalendario Attivita::MostraData()const {
    return data;
}

int Attivita::MostraID()const {
    return ID;
}

wxString Attivita::MostraDescrizione()const {
    return descrizione;
}

void Attivita::ShowAttivita(wxArrayString *arrayDeiNomi) {
   arrayDeiNomi->Add(nome);
}


wxString Attivita::GetOrarioStringaCompleto() {
    wxString orarioInizioStringa = inizioAtt.GetOrarioStringa();
    wxString orarioFineStringa = fineAtt.GetOrarioStringa();
    wxString orarioStringaFinale = "Inizio " + orarioInizioStringa + " Fine " + orarioFineStringa;
    return orarioStringaFinale;
}

wxString Attivita::StampaData() {
    wxString stringaData = wxString::Format(wxT("%i/%i/%i"),data.GetGiorno(),data.GetMese(),data.GetAnno());
    return stringaData;
}