
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include "Orario.h"
#include <iostream>
#include <string>
#include <wx/wx.h>

class Attivita {
public:
    Attivita(wxString nome, int data, int ID, wxString descrizione, Orario inizio, Orario fine);

    void AggiungiDescrizione(std::string);

    void AggiungiNome(wxString);

    wxString MostraNome();

    void ShowAttivita(wxArrayString *arrayDeiNomi);

    wxString MostraDescrizione();

    int MostraData();

    int MostraID();

    wxString GetOrarioStringaCompleto();


private:
    Orario inizioAtt;
    Orario fineAtt;
    wxString descrizione;
    wxString nome;
    int data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
