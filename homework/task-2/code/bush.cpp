//------------------------------------------------------------------------------
// bush.cpp - содержит процедуру ввода параметров
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include "bush.h"
#include <cstring>
#include <sstream>

//------------------------------------------------------------------------------
// Преобразование номера месяца в строку
const char* MonthIndexToString(bush::month month) {
    switch(month) {
        case bush::month::JANUARY:
            return "january";
        case bush::month::FEBRUARY:
            return "february";
        case bush::month::MARCH:
            return "march";
        case bush::month::APRIL:
            return "april";
        case bush::month::MAY:
            return "may";
        case bush::month::JUNE:
            return "june";
        case bush::month::JULY:
            return "july";
        case bush::month::AUGUST:
            return "august";
        case bush::month::SEPTEMBER:
            return "september";
        case bush::month::OCTOBER:
            return "october";
        case bush::month::NOVEMBER:
            return "november";
        case bush::month::DECEMBER:
            return "december";
        default:
            return "unknown";
    }
}

//------------------------------------------------------------------------------
// Преобразование строки месяца в индекс месяца
bush::month MonthStringToMonthIndex(const char* month) {
    if(strcmp(month, "january") == 0)
        return bush::month::JANUARY;
    if(strcmp(month, "february") == 0)
        return bush::month::FEBRUARY;
    if(strcmp(month, "march") == 0)
        return bush::month::MARCH;
    if(strcmp(month, "april") == 0)
        return bush::month::APRIL;
    if(strcmp(month, "may") == 0)
        return bush::month::MAY;
    if(strcmp(month, "june") == 0)
        return bush::month::JUNE;
    if(strcmp(month, "july") == 0)
        return bush::month::JULY;
    if(strcmp(month, "august") == 0)
        return bush::month::AUGUST;
    if(strcmp(month, "september") == 0)
        return bush::month::SEPTEMBER;
    if(strcmp(month, "october") == 0)
        return bush::month::OCTOBER;
    if(strcmp(month, "november") == 0)
        return bush::month::NOVEMBER;
    if(strcmp(month, "december") == 0)
        return bush::month::DECEMBER;
    return (bush::month)-1;
}

//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
bush::bush(ifstream& ifst) {
    std::string month_name;
    ifst >> name >> month_name;
    bloom_month = MonthStringToMonthIndex(month_name.c_str());
}

// Случайный ввод параметров кустарника
bush::bush(const Random& rand) {
    int length = rand(128);
    name.resize(length);
    for (size_t i = 0; i < length; ++i) {
        name[i] = char('a' + rand(26));
    }
    bloom_month = (bush::month)rand(12);
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в виде строки
std::string bush::toString() const {
    std::stringstream osst;
    osst << "It is Bush: name = " << name << ", bloom month = " << MonthIndexToString(bloom_month)
         << ". hash = " << Hash() << "\n";
    return osst.str();
}

//------------------------------------------------------------------------------
// Вычисление хеша имени кустарника
double bush::Hash() const {
    int vowel_count = 0;
    for(char c : name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)name.size();
}
