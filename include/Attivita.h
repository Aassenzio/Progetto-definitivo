
#ifndef PROGETTODEFINITIVO_ATTIVITA_H
#define PROGETTODEFINITIVO_ATTIVITA_H
#include "orario.h"
#include <string>
class Attivita{
public:
    void AggiungiDescrizione(std::string);
private:
    orario oraInizio;
    orario oraFine;
    std::string descrizione;
};
#endif //PROGETTODEFINITIVO_ATTIVITA_H
