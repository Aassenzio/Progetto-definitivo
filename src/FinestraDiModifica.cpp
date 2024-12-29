#include "FinestraDiModifica.h"


FrameSecondario::FrameSecondario(const wxString &title, Registro* registro ,int data):wxFrame(nullptr, wxID_ANY, title ),
                                                                    registroAttivita(registro), dataDiRicerca(data),
                                                                    grigliaAttivita(nullptr), bottoneAddAttivita(nullptr){
    pannelloSecondario = new wxPanel(this);
    if(!grigliaAttivita){  //griglia con i vari campi delle attivita
        grigliaAttivita = new wxGrid(pannelloSecondario, wxID_ANY, wxPoint(100,100), wxSize(500,300));
        grigliaAttivita->CreateGrid(0,5);
        grigliaAttivita->HideCol(0);
        grigliaAttivita->SetColLabelValue(1, "Nome");
        grigliaAttivita->SetColLabelValue(2, "Data");
        grigliaAttivita->SetColLabelValue(3,"Orario Durata");
        grigliaAttivita->SetColLabelValue(4, "Descrizione");
        grigliaAttivita->SetSelectionMode(wxGrid::wxGridSelectRows);
        grigliaAttivita->EnableEditing(false);
    }
    registroAttivita->searchDate(dataDiRicerca, grigliaAttivita);
    if(!bottoneAddAttivita){
        bottoneAddAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Aggiungi Attivita", wxPoint(600,200), wxSize(100,100));
    }
    bottoneAddAttivita->Bind(wxEVT_BUTTON, &FrameSecondario::OnBottoneAdd, this);
}

void FrameSecondario::SetRegister(Registro * registro) {
    registroAttivita = registro;
}

void FrameSecondario::SetDataDiRicerca(int data) {
    dataDiRicerca = data;
}

void FrameSecondario::OnBottoneAdd(wxCommandEvent& evt){
    FinestraDiAggiunta* finestraDiAggiunta =new FinestraDiAggiunta("Aggiungi Attivita", registroAttivita, dataDiRicerca);
    finestraDiAggiunta->SetClientSize(475, 400);
    finestraDiAggiunta->Center();
    finestraDiAggiunta->Show();
    this->Close();
}