
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include <iostream>
#include <string>
#include <wx/wx.h>
#include "GiornoDelCalendario.h"
#include "Orario.h"

class Attivita {
public:
    Attivita(std::string nome, GiornoDelCalendario data, int ID, wxString descrizione, Orario inizio, Orario fine);

    void aggiungiDescrizione(wxString); //In caso di edit

    void aggiungiNome(wxString); //In caso di edit

    std::string getNome()const;


    std::string getDescrizione()const;

    GiornoDelCalendario getData()const;

    int getId()const;

    std::string getOrarioStringaCompleto() ;

    std::string getStringaData()const;

    int getNumeroRigheDescrizione ()const;


private:
    Orario inizioAtt;
    Orario fineAtt;
    std::string descrizione;
    std::string nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
