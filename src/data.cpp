#include "Data.h"
#include <iostream>

Data::Data(int giorno = 1, int mese = 1, int anno =1990): _giorno(giorno),
      _mese(mese), _anno(anno){}

void Data::ShowListaAttivita() {
    for(auto iter = listaAttivita.begin(); iter != listaAttivita.end() ;
                                                               iter++){
        iter->ShowAttivita();

    }
}
