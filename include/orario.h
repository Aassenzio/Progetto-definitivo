//
// Created by Igor on 5/27/2024.
//

#ifndef PROGETTODEFINITIVO_ORARIO_H
#define PROGETTODEFINITIVO_ORARIO_H
class orario
        {
    public:
            orario(int oraInserita, int minutoInserito, int secondoInserito=0):
            ore(oraInserita), minuti(minutoInserito), secondi(secondoInserito){};
            void stampaOrario();
            orario durata(const orario&)const;
    private:
            int ore;
            int minuti;
            int secondi;
        };

#endif //PROGETTODEFINITIVO_ORARIO_H
