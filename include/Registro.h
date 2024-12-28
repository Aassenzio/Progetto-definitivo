
#ifndef PROGETTODEFINITIVO_REGISTRO_H
#define PROGETTODEFINITIVO_REGISTRO_H
#include <map>
#include "Data.h"
#include "Attivita.h"
class Registro{
public:
    void searchDate(int data);
private:
    std::map<int, Data> mappaData;
};
#endif //PROGETTODEFINITIVO_REGISTRO_H
