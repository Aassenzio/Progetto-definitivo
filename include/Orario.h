
#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
#include <wx/wx.h>
class Orario
        {
    public:
            Orario(int oraInserita, int minutoInserito):
            ore(oraInserita), minuti(minutoInserito){};

            int GetOre();
            int GetMinuti();
            wxString GetOrarioStringa();


    private:
            int ore;
            int minuti;
        };

#endif //PROGETTODEFINITIVO_ORARIO_H
