
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H

#include <vector>
#include "Attivita.h"

class Registro {
public:

    Registro();

    int searchDate(GiornoDelCalendario data, std::vector<Attivita*> *listaTrovati);


    int searchName(std::string nome, std::vector<Attivita*> *listaTrovati);


    void addAttivita(std::string nome, GiornoDelCalendario data, std::string descrizione, Orario inizio, Orario fine);


    void eliminaAttivita(int ID);


private:
    int contatoreAssoluto ;
    std::vector<Attivita*> vettoreAttivita;
};

#endif //PROGETTODEFINITIVO_REGISTRO_H
