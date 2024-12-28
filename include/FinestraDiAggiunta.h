
#ifndef PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H
#define PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H
#include <wx/wx.h>
#include "Registro.h"

class FinestraDiAggiunta:public wxFrame {
public:
    FinestraDiAggiunta(const wxString &title, Registro *registro);
    void OnBottoneSave(wxCommandEvent& evt);
private:
    wxPanel* pannelloFinestraAggiunta ;
    Registro* registroAttivita;
    wxTextCtrl* testoNome;
    wxButton* bottoneSalvaNuovaAttivita ;
};


#endif //PROGETTODEFINITIVO_FINESTRADIAGGIUNTA_H
