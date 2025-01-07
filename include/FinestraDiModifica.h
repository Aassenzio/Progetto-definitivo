
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

    void SetRegister(Registro *);


    void OnBottoneAdd(wxCommandEvent& evt);

    void OnSelezioneRiga(wxGridEvent& evt);

    void OnBottoneElimina(wxCommandEvent& evt);

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
