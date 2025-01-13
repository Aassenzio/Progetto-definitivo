
#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
#include<string>
#include <wx/wx.h>

class Orario {
public:
    Orario(int oraInserita, int minutoInserito);

    std::string toString();


private:
    std::string ore;
    std::string minuti;
};

#endif //PROGETTODEFINITIVO_ORARIO_H
