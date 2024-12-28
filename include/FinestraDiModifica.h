
#ifndef PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
#define PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Utility.h"
#include "Registro.h"
class FrameSecondario:public wxFrame {
public:
    FrameSecondario(const wxString &title);
private:
    Registro* registroAttivita;
    wxPanel* pannelloSecondario;
};
#endif //PROGETTODEFINITIVO_FINESTRADIMODIFICA_H
