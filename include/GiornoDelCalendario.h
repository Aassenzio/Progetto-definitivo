
#ifndef PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
#define PROGETTODEFINITIVO_GIORNODELCALENDARIO_H

class GiornoDelCalendario{
public:
    GiornoDelCalendario(int giorno, int mese, int anno);

    int getGiorno()const;

    int getMese()const;

    int getAnno()const;

    bool comparaData(GiornoDelCalendario dataDaComparare);

private:
    int giorno;
    int mese;
    int anno;

};
#endif //PROGETTODEFINITIVO_GIORNODELCALENDARIO_H
