
#ifndef PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
#define PROGETTODEFINITIVO_FINESTRADIMODIFICA_H

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include "Utility.h"
#include "Registro.h"
#include "Finestra.h"
#include "FinestraDiAggiunta.h"

class FrameSecondario : public wxFrame {
public:
    FrameSecondario(const wxString &title, Registro *, int);

    void SetRegister(Registro *);

    void SetDataDiRicerca(int);

    void OnBottoneAdd(wxCommandEvent& evt);

    void OnSelezioneRiga(wxGridEvent& evt);

    void OnBottoneElimina(wxCommandEvent& evt);

private:
    int selezioneCorrente;
    int dataDiRicerca;
    wxGrid *grigliaAttivita;
    Registro *registroAttivita;
    wxPanel *pannelloSecondario;
    wxButton *bottoneAddAttivita;
    wxButton *bottoneEliminaAttivita;
};

#endif //PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
