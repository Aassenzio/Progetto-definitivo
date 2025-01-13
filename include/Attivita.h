
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

    wxString getNome()const;


    wxString getDescrizione()const;

    GiornoDelCalendario getData()const;

    int getId()const;

    wxString getOrarioStringaCompleto();

    wxString getStringaData();

    int getNumeroRigheDescrizione();


private:
    Orario inizioAtt;
    Orario fineAtt;
    wxString descrizione;
    wxString nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
