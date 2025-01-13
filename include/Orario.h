
#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
#include<string>
#include<stdexcept>

class Orario {
public:
    Orario(int oraInserita, int minutoInserito);

    std::string toString();

    bool operator>(const Orario& other) const;

private:
    std::string ore;
    std::string minuti;
};

#endif //PROGETTODEFINITIVO_ORARIO_H
