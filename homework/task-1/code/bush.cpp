//------------------------------------------------------------------------------
// bush.cpp - содержит процедуру ввода параметров
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include "bush.h"
#include <string.h>

//------------------------------------------------------------------------------
// Преобразование номера месяца в строку
const char* MonthIndexToString(int month) {
    switch(month) {
        case bush::JANUARY:
            return "january";
        case bush::FEBRUARY:
            return "february";
        case bush::MARCH:
            return "march";
        case bush::APRIL:
            return "april";
        case bush::MAY:
            return "may";
        case bush::JUNE:
            return "june";
        case bush::JULY:
            return "july";
        case bush::AUGUST:
            return "august";
        case bush::SEPTEMBER:
            return "september";
        case bush::OCTOBER:
            return "october";
        case bush::NOVEMBER:
            return "november";
        case bush::DECEMBER:
            return "december";
        default:
            return "unknown";
    }
}

//------------------------------------------------------------------------------
// Преобразование строки месяца в индекс месяца
int MonthStringToMonthIndex(const char* month) {
    if(strcmp(month, "january") == 0)
        return bush::JANUARY;
    if(strcmp(month, "february") == 0)
        return bush::FEBRUARY;
    if(strcmp(month, "march") == 0)
        return bush::MARCH;
    if(strcmp(month, "april") == 0)
        return bush::APRIL;
    if(strcmp(month, "may") == 0)
        return bush::MAY;
    if(strcmp(month, "june") == 0)
        return bush::JUNE;
    if(strcmp(month, "july") == 0)
        return bush::JULY;
    if(strcmp(month, "august") == 0)
        return bush::AUGUST;
    if(strcmp(month, "september") == 0)
        return bush::SEPTEMBER;
    if(strcmp(month, "october") == 0)
        return bush::OCTOBER;
    if(strcmp(month, "november") == 0)
        return bush::NOVEMBER;
    if(strcmp(month, "december") == 0)
        return bush::DECEMBER;
    return -1;
}

//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
void In(bush &b, ifstream &ifst) {
    char month_name[128];
    ifst >> b.name >> month_name;
    b.bloom_month = MonthStringToMonthIndex(month_name);
}

// Случайный ввод параметров кустарника
void InRnd(bush &b) {
    int length = Random(size(b.name) - 1);
    for (size_t i = 0; i < length; ++i) {
        b.name[i] = char('a' + Random(26));
    }
    b.name[length] = '\0';
    b.bloom_month = Random(12);
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в форматируемый поток
void Out(bush &b, ofstream &ofst) {
    ofst << "It is Bush: name = " << b.name << ", bloom month = " << MonthIndexToString(b.bloom_month)
         << ". hash = " << Hash(b) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление хеша имени кустарника
double Hash(bush &b) {
    int vowel_count = 0;
    for(char c : b.name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)strlen(b.name);
}
