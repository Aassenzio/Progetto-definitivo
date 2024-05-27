#include <iostream>
#include "orario.h"
#include <wx/wx.h>

int main(){
    orario prova(14,34,52);
    orario prova2(21,18,3);
orario prova3=prova.durata(prova2);
prova3.stampaOrario();

}
// Created by Igor on 4/24/2024.
//
