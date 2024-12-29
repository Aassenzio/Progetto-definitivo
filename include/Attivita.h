
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H
#include "orario.h"
#include <iostream>
#include <string>
#include <wx/wx.h>
class Attivita{
public:
    Attivita(wxString nome,int data, int ID);

    void AggiungiDescrizione(std::string);

    void AggiungiNome(wxString);

    wxString MostraNome();

    void AggiungiOrario(orario , orario);

    void ShowAttivita(wxArrayString* arrayDeiNomi);

    int MostraData();

    int MostraID();
private:
    //orario oraInizio;
   // orario oraFine;
   // std::string descrizione;
    wxString nome;
    int data;
    int ID;
};
#endif //PROGETTODEFINITIVO_ATTIVITA_H
