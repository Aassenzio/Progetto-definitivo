#include <iostream>
#include "orario.h"
void orario:: stampaOrario(){
    std::cout<< orario::ore<< ":"<< orario::minuti<<":"<<orario::secondi;
}
orario orario::durata(const orario& oraDue)const{
    int secondiTotaliPrima;
    int secondiTotaliSeconda;
    secondiTotaliPrima=this->secondi+(this->minuti)*60+(this->ore)*3600;
    secondiTotaliSeconda=oraDue.secondi+(oraDue.minuti)*60+(oraDue.ore)*3600;
    int secondiFinali=secondiTotaliPrima-secondiTotaliSeconda;
    if (secondiFinali<0){
        std::cout<<"non puoi tornare indietro nel tempo"<<std::endl;
        return orario(0,0,0);
    }
    int numeroOre=secondiFinali/3600;
    int numeroMinuti=(secondiFinali-numeroOre*3600)/60;
    int numeroSecondi=secondiFinali-numeroOre*3600-numeroMinuti*60;
    return orario(numeroOre,numeroMinuti,numeroSecondi);
}