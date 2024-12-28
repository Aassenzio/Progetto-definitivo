#ifndef PROGETTODEFINITIVO_DATA_H
#define PROGETTODEFINITIVO_DATA_H
#include<list>
#include "Attivita.h"
class Data{
public:
    Data(int giorno, int mese, int anno);
    void ShowListaAttivita();
private:
    int _giorno;
    int _mese;
    int _anno;
    std::list<Attivita> listaAttivita;
};
#endif //PROGETTODEFINITIVO_DATA_H
