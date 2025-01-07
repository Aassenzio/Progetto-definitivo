
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include <iostream>
#include <wx/wx.h>
#include "GiornoDelCalendario.h"
#include "Orario.h"

class Attivita {
public:
    Attivita(wxString nome, GiornoDelCalendario data, int ID, wxString descrizione, Orario inizio, Orario fine);

    void aggiungiDescrizione(wxString); //In caso di edit

    void aggiungiNome(wxString); //In caso di edit

    wxString mostraNome()const;


    wxString mostraDescrizione()const;

    GiornoDelCalendario mostraData()const;

    int mostraId()const;

    wxString getOrarioStringaCompleto();

    wxString stampaData();


private:
    Orario inizioAtt;
    Orario fineAtt;
    wxString descrizione;
    wxString nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
