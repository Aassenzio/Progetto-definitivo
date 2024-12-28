
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H
#include "orario.h"
#include <iostream>
#include <string>
#include <wx/wx.h>
class Attivita{
public:
    void AggiungiDescrizione(std::string);

    void AggiungiNome(std::string);

    void AggiungiOrario(orario , orario);

    void ShowAttivita(wxArrayString* arrayDeiNomi);
private:
    orario oraInizio;
    orario oraFine;
    std::string descrizione;
    wxString nome;
};
#endif //PROGETTODEFINITIVO_ATTIVITA_H
