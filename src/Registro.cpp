#include "Registro.h"
void Registro::searchDate(int dataCercata, wxGrid* griglia){
    int contatoreRighe=0;
    for(int iter = 0; iter < contatoreAssoluto; iter++) {
        if (vettoreAttivita[iter].MostraData() == dataCercata){
            griglia->AppendRows(1);
            griglia->SetCellValue(contatoreRighe,0,wxString::Format(wxT("%i"),vettoreAttivita[iter].MostraID()));
            griglia->SetCellValue(contatoreRighe,1, vettoreAttivita[iter].MostraNome());
            griglia->SetCellValue(contatoreRighe,2, wxString::Format(wxT("%i"),vettoreAttivita[iter].MostraData()));
            griglia->SetCellValue(contatoreRighe,3, vettoreAttivita[iter].GetOrarioStringaCompleto());
            griglia->SetCellValue(contatoreRighe,4 , vettoreAttivita[iter].MostraDescrizione() );
            contatoreRighe++;
        }
    }
}

int Registro::GetAbsCounter() {
    return contatoreAssoluto;
}

void Registro::AddAttivita(wxString nomeAttivita, int dataAttivita, wxString descrizioneAttivita, Orario inizioAtt,
                           Orario fineAtt) {
    vettoreAttivita.push_back(Attivita(nomeAttivita, dataAttivita, contatoreAssoluto, descrizioneAttivita, inizioAtt,
                                       fineAtt));
    contatoreAssoluto++;
}