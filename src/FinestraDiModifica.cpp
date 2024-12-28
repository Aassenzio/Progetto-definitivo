#include "FinestraDiModifica.h"


FrameSecondario::FrameSecondario(const wxString &title, Registro* registro ,int data):wxFrame(nullptr, wxID_ANY, title ),
                                                                    registroAttivita(registro), dataDiRicerca(data),
                                                                    listaDiQualcosa(nullptr), bottoneAddAttivita(nullptr){
    pannelloSecondario = new wxPanel(this);
    if(!listaDiQualcosa){
        listaDiQualcosa = new wxListCtrl(pannelloSecondario, wxID_ANY, wxPoint(600,200), wxSize(-1,-1),
                                         wxLC_REPORT | wxLC_SINGLE_SEL);
       listaDiQualcosa->InsertColumn(0, "ID", wxLIST_FORMAT_LEFT, 100);
        long itemIndex = listaDiQualcosa->InsertItem(0, "1");
    }
    registroAttivita->searchDate(dataDiRicerca, listaDiQualcosa);
    if(!bottoneAddAttivita){
        bottoneAddAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Aggiungi Attivita", wxPoint(300,200), wxSize(300,300));
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
    FinestraDiAggiunta* finestraDiAggiunta =new FinestraDiAggiunta("Aggiungi Attivita", registroAttivita);
    finestraDiAggiunta->SetClientSize(800, 600);
    finestraDiAggiunta->Center();
    finestraDiAggiunta->Show();
}