
#ifndef PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
#define PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
//#include "Utility.h"
class GiornoDelCalendario{
public:
    GiornoDelCalendario(int giorno, int mese, int anno);
    int GetGiorno()const;
    int GetMese()const;
    int GetAnno()const;
    bool ComparaData(GiornoDelCalendario dataDaComparare);
private:
    int giorno;
    int mese;
    int anno;

};
#endif //PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
