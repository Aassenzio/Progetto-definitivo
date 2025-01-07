
#ifndef PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
#define PROGETTODEFINITIVO_FINESTRADIMODIFICA_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include "Utility.h"
#include "Registro.h"
#include "FinestraPrincipale.h"
#include "FinestraDiAggiunta.h"

class FrameSecondario : public wxFrame {
public:
    FrameSecondario(const wxString &title, Registro *, GiornoDelCalendario);

    void setRegister(Registro *); //in caso di edit button


    void onBottoneAdd(wxCommandEvent& evt);

    void onSelezioneRiga(wxGridEvent& evt);

    void onBottoneElimina(wxCommandEvent& evt);

private:
    int selezioneCorrente;
    GiornoDelCalendario dataDiRicerca;
    wxGrid *grigliaAttivita;
    Registro *registroAttivita;
    wxPanel *pannelloSecondario;
    wxButton *bottoneAddAttivita;
    wxButton *bottoneEliminaAttivita;
};

#endif //PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
