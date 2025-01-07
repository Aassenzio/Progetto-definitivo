
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include "Orario.h"
#include <iostream>
#include <string>
#include <wx/wx.h>
#include "GiornoDelCalendario.h"

class Attivita {
public:
    Attivita(wxString nome, GiornoDelCalendario data, int ID, wxString descrizione, Orario inizio, Orario fine);

    void AggiungiDescrizione(std::string);

    void AggiungiNome(wxString);

    wxString MostraNome()const;

   void ShowAttivita(wxArrayString *arrayDeiNomi);

    wxString MostraDescrizione()const;

    GiornoDelCalendario MostraData()const;

    int MostraID()const;

    wxString GetOrarioStringaCompleto();

    wxString StampaData();


private:
    Orario inizioAtt;
    Orario fineAtt;
    wxString descrizione;
    wxString nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
