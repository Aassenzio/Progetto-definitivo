#include "Registro.h"

void Registro::searchDate(int dataCercata, wxArrayString* arrayDeiNomi, Data*& dataCorrente){
    arrayDeiNomi->Add("Aggiungi Nuova Attivita'");
    auto iter = mappaData.find(dataCercata);
    if(iter == mappaData.end()){
        Data dataAggiunta= Data(dataCercata);
        mappaData.insert(std::make_pair(dataCercata, dataAggiunta));
        dataCorrente = &dataAggiunta;
    }else{dataCorrente = &iter->second;
        iter->second.ShowListaAttivita(arrayDeiNomi);
    }

}