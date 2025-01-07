#include "GiornoDelCalendario.h"

GiornoDelCalendario::GiornoDelCalendario(int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno){};

int GiornoDelCalendario::GetAnno() const {
    return anno;
}

int GiornoDelCalendario::GetMese() const {
    return mese;
}

int GiornoDelCalendario::GetGiorno() const {
    return giorno;
}

bool GiornoDelCalendario::ComparaData(GiornoDelCalendario dataDaComparare) {
    if(dataDaComparare.GetGiorno() == giorno && dataDaComparare.GetMese() == mese && dataDaComparare.GetAnno() == anno){
        return true; }
    else return false ;
}
