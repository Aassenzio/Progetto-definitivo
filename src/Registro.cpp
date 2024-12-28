#include "Registro.h"

void Registro::searchDate(int dataCercata){
    auto iter = mappaData.find(dataCercata);
    if(iter == mappaData.end()){
        Data dataAggiunta= Data(dataCercata);
        mappaData.insert(std::make_pair(dataCercata, dataAggiunta));
    }else iter->second.ShowListaAttivita();

}