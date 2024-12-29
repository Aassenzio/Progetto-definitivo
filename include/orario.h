//
// Created by Igor on 5/27/2024.
//

#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
class orario
        {
    public:
            orario(int oraInserita, int minutoInserito):
            ore(oraInserita), minuti(minutoInserito){};

            void stampaOrario();

    private:
            int ore;
            int minuti;
        };

#endif //PROGETTODEFINITIVO_ORARIO_H
