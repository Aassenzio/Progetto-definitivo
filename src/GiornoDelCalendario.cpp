#include "GiornoDelCalendario.h"

GiornoDelCalendario::GiornoDelCalendario(int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno){

    if(giorno>31 || mese> 12){
        throw std::invalid_argument("Giorno o mese invalido");
    }
    switch (mese) {
            case 2:
                if (isBisestile(anno) && giorno>29){
                    throw std::invalid_argument("Febbraio ha 29 giorni");
                }
                else {
                    if (giorno > 28)
                        throw std::invalid_argument("Febbraio ha 28 giorni");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(giorno > 30) {
                    throw std::invalid_argument("Il mese selezionato ha 30 giorni");
                }
                break;
            default:
                break;
    }

}

int GiornoDelCalendario::getAnno() const {
    return anno;
}

int GiornoDelCalendario::getMese() const {
    return mese;
}

int GiornoDelCalendario::getGiorno() const {
    return giorno;
}
bool GiornoDelCalendario::operator==(const GiornoDelCalendario &dataDaComparare) const {
    if(dataDaComparare.getGiorno() == giorno && dataDaComparare.getMese() == mese && dataDaComparare.getAnno() == anno){
        return true;
    }
            else return false ;
}

bool GiornoDelCalendario::isBisestile(int annoSelezionato) {
    if (annoSelezionato % 4 == 0 && (annoSelezionato % 100 != 0 || annoSelezionato % 400 == 0) )
        return true;
    else return false;
}
