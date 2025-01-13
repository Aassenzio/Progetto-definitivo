
#ifndef PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
#define PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
#include <stdexcept>

class GiornoDelCalendario{
public:
    GiornoDelCalendario(int giorno, int mese, int anno);

    int getGiorno()const;

    int getMese()const;

    int getAnno()const;

    bool operator==(const GiornoDelCalendario& other)const;

    static bool isBisestile(int anno);

private:
    int giorno;
    int mese;
    int anno;

};
#endif //PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
