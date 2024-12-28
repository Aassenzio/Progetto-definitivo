
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H
#include "orario.h"
#include <iostream>
#include <string>
class Attivita{
public:
    void AggiungiDescrizione(std::string);
    void ShowAttivita();
private:
    orario oraInizio;
    orario oraFine;
    std::string descrizione;
    std::string nome;
};
#endif //PROGETTODEFINITIVO_ATTIVITA_H
