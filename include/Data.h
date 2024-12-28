#ifndef PROGETTODEFINITIVO_DATA_H
#define PROGETTODEFINITIVO_DATA_H
#include<list>
#include <wx/wx.h>
#include "Attivita.h"
class Data{
public:
    Data(int);
    Data(int giorno, int mese, int anno);
    void ShowListaAttivita(wxArrayString* arrayDeiNomi);
    void AddAttivita(Attivita);
private:
    int _giorno;
    int _mese;
    int _anno;
    std::list<Attivita> listaAttivita;
};
#endif //PROGETTODEFINITIVO_DATA_H
