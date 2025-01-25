
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H

#include <iostream>
#include <string>
#include "GiornoDelCalendario.h"
#include "Orario.h"

class Attivita {
public:
    Attivita(const std::string &nome, const GiornoDelCalendario &data, int ID, const std::string &descrizione,
             const Orario &inizio, const Orario &fine);

    std::string getNome() const;


    std::string getDescrizione() const;

    GiornoDelCalendario getData() const;

    int getId() const;

    std::string toStringOrario() const;

    std::string toStringData() const;

    int getRigheDescrizione() const;

    bool operator==(const Attivita& other) const;


private:
    Orario inizioAtt;
    Orario fineAtt;
    std::string descrizione;
    std::string nome;
    GiornoDelCalendario data;
    int ID;
};

#endif //PROGETTODEFINITIVO_ATTIVITA_H
