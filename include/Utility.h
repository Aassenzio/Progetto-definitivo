
#ifndef PROGETTODEFINITIVO_UTILITY_H
#define PROGETTODEFINITIVO_UTILITY_H
bool IsBisestile(int annoSelezionato){
    if (annoSelezionato % 4 ==0 && annoSelezionato % 100 != 0)
        return true;
    else return false;
}
#endif //PROGETTODEFINITIVO_UTILITY_H
