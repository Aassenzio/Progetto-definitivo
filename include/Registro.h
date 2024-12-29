
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H
#include <vector>
#include<wx/wx.h>
#include<wx/grid.h>
#include "Data.h"
#include "Attivita.h"
class Registro{
public:
    void searchDate(int data, wxGrid* listaDiQualcosa);
    int GetAbsCounter();
    void AddAttivita(wxString nome, int data);
private:
    int contatoreAssoluto = 0;
    std::vector<Attivita> vettoreAttivita;
};
#endif //PROGETTODEFINITIVO_REGISTRO_H
