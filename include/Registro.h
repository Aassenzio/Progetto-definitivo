
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H

#include <vector>
#include<wx/wx.h>
#include<wx/grid.h>
#include <wx/spinctrl.h>
#include "Attivita.h"

class Registro {
public:

    Registro();

    int searchDate(GiornoDelCalendario data, std::vector<Attivita*> *listaTrovati);


    void addAttivita(std::string nome, GiornoDelCalendario data, wxString descrizione, Orario inizio, Orario fine);

    void eliminaAttivita(int ID);


private:
    int contatoreAssoluto ;
    std::vector<Attivita*> vettoreAttivita;
};

#endif //PROGETTODEFINITIVO_REGISTRO_H
