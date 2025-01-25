
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H

#include <vector>
#include "Attivita.h"

class Registro {
public:

    Registro();

    std::vector<Attivita*> searchDate(const GiornoDelCalendario& data);


    std::vector<Attivita*> searchName(const std::string& nome);


    void addAttivita(const std::string &nome, const GiornoDelCalendario &data, const std::string &descrizione,
                     const Orario &inizio, const Orario &fine);


    void eliminaAttivita(const int &ID);


private:
    int contatoreAssoluto;
    std::vector<Attivita *> vettoreAttivita;
};

#endif //PROGETTODEFINITIVO_REGISTRO_H
