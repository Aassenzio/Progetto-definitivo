#include "FinestraDiModifica.h"


FrameSecondario::FrameSecondario(const wxString &title, Registro* registro ,int data):wxFrame(nullptr, wxID_ANY, title ),
                                                                    registroAttivita(registro), dataDiRicerca(data),
                                                                    grigliaAttivita(nullptr), bottoneAddAttivita(nullptr){
    pannelloSecondario = new wxPanel(this);
    if(!grigliaAttivita){  //griglia con i vari campi delle attivita
        grigliaAttivita = new wxGrid(pannelloSecondario, wxID_ANY, wxPoint(25,25), wxSize(700,400));
        grigliaAttivita->CreateGrid(0,5);
        grigliaAttivita->HideCol(0);
        grigliaAttivita->SetColLabelValue(1, "Nome");
        grigliaAttivita->SetColLabelValue(2, "Data");
        grigliaAttivita->SetColLabelValue(3,"Orario inizio/fine");
        grigliaAttivita->SetColLabelValue(4, "Descrizione");
        grigliaAttivita->SetSelectionMode(wxGrid::wxGridSelectRows);
        grigliaAttivita->EnableEditing(false);
        grigliaAttivita->SetColSize(1,90);
        grigliaAttivita->SetColSize(2,70);
        grigliaAttivita->SetColSize(3,150);
        grigliaAttivita->SetColSize(4,300);
    }
    registroAttivita->searchDate(dataDiRicerca, grigliaAttivita);
    if(!bottoneAddAttivita){
        bottoneAddAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Aggiungi Attivita", wxPoint(650,475), wxSize(100,25));
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