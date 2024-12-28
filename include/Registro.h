
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H
#include <vector>
#include<wx/wx.h>
#include<wx/listctrl.h>
#include "Data.h"
#include "Attivita.h"
class Registro{
public:
    void searchDate(int data, wxListCtrl* listaDiQualcosa);
    int GetAbsCounter();
    void AddAttivita(wxString);
private:
    int contatoreAssoluto = 0;
    std::vector<Attivita> vettoreAttivita;
};
#endif //PROGETTODEFINITIVO_REGISTRO_H
