#include "Data.h"
#include <iostream>

Data::Data(int giorno = 1, int mese = 1, int anno =1990): _giorno(giorno),
      _mese(mese), _anno(anno){};
Data::Data(int dataCompatta){};
void Data::ShowListaAttivita(wxArrayString* arrayDeiNomi) {
    for(auto iter = listaAttivita.begin(); iter != listaAttivita.end() ;
                                                               iter++){
        iter->ShowAttivita(arrayDeiNomi);

    }
    std::cout<<"Fine lista";
}

void Data::AddAttivita(Attivita nuovaAggiunta){
    listaAttivita.push_back(nuovaAggiunta);
}