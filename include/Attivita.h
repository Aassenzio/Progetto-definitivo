
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include <iostream>
#include <string>
#include "GiornoDelCalendario.h"
#include "Orario.h"

class Attivita {
public:
    Attivita(const std::string &nome, const GiornoDelCalendario &data, const int &ID, const std::string &descrizione,
             const Orario &inizio, const Orario &fine);

    std::string getNome() const;


    std::string getDescrizione() const;

    GiornoDelCalendario getData() const;

    int getId() const;

    std::string orarioToString() const;

    std::string dataToString() const;

    int getNumeroRigheDescrizione() const;


private:
    Orario inizioAtt;
    Orario fineAtt;
    std::string descrizione;
    std::string nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
