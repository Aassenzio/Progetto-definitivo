#include "GiornoDelCalendario.h"

GiornoDelCalendario::GiornoDelCalendario(int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno){};

int GiornoDelCalendario::getAnno() const {
    return anno;
}

int GiornoDelCalendario::getMese() const {
    return mese;
}

int GiornoDelCalendario::getGiorno() const {
    return giorno;
}

bool GiornoDelCalendario::comparaData(GiornoDelCalendario dataDaComparare)const {
    if(dataDaComparare.getGiorno() == giorno && dataDaComparare.getMese() == mese && dataDaComparare.getAnno() == anno){
        return true;
    }
    else return false ;
}
