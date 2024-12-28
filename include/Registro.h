
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H
#include <map>
#include<wx/wx.h>
#include "Data.h"
#include "Attivita.h"
class Registro{
public:
    void searchDate(int data, wxArrayString* arrayDeiNomi);
private:
    std::map<int, Data> mappaData;
};
#endif //PROGETTODEFINITIVO_REGISTRO_H
