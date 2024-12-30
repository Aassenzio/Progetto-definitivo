
#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
#include <wx/wx.h>
class Orario
        {
    public:
            Orario(int oraInserita, int minutoInserito);

            wxString GetOrarioStringa();


    private:
            wxString ore;
            wxString minuti;
        };

#endif //PROGETTODEFINITIVO_ORARIO_H
