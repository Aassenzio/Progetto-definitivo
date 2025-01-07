
#ifndef PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H
#define PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H

#include <wx/wx.h>
#include "Registro.h"

class FinestraDiAggiunta : public wxFrame {
public:
    FinestraDiAggiunta(const wxString &title, Registro *registro, GiornoDelCalendario dataDaAggiungere);

    void onBottoneSave(wxCommandEvent &evt);

    void onBottoneAnnulla(wxCommandEvent &evt);

    void onCambioOra(wxCommandEvent &evt);

private:
    wxPanel *pannelloFinestraAggiunta;
    Registro *registroAttivita;
    wxTextCtrl *testoNome;
    wxTextCtrl *testoDescrizione;
    wxButton *bottoneSalvaNuovaAttivita;
    wxButton *bottoneAnnulla;
    wxSpinCtrl *oraInizio;
    wxSpinCtrl *oraFine;
    wxSpinCtrl *minutoInizio;
    wxSpinCtrl *minutoFine;
    GiornoDelCalendario dataAttivitaDaAggiungere;
};


#endif //PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H
