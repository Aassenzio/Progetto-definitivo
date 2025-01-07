#include "Registro.h"

Registro::Registro(): contatoreAssoluto(0){}
void Registro::searchDate(GiornoDelCalendario dataCercata, wxGrid *griglia) {
    int contatoreRighe = 0;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if(!vettoreAttivita[iter]) {}
        else{
            if ((vettoreAttivita[iter]->mostraData()).comparaData(dataCercata)) {
                griglia->AppendRows(1);
                griglia->SetCellValue(contatoreRighe, 0,
                                      wxString::Format(wxT("%i"), vettoreAttivita[iter]->mostraId()));
                griglia->SetCellValue(contatoreRighe, 1, vettoreAttivita[iter]->mostraNome());
                griglia->SetCellValue(contatoreRighe, 2, vettoreAttivita[iter]->stampaData());
                griglia->SetCellValue(contatoreRighe, 3, vettoreAttivita[iter]->getOrarioStringaCompleto());
                griglia->SetCellValue(contatoreRighe, 4, vettoreAttivita[iter]->mostraDescrizione());
                contatoreRighe++;
            }
        }
    }
}


void Registro::addAttivita(wxString nome, GiornoDelCalendario data, wxString descrizione, Orario inizio,
                           Orario fine) {
    vettoreAttivita.push_back(new Attivita(nome, data, contatoreAssoluto, descrizione, inizio,
                                           fine));
    contatoreAssoluto++;
}

void Registro::eliminaAttivita(int ID) {
    delete vettoreAttivita[ID];
    vettoreAttivita[ID] = nullptr;
}