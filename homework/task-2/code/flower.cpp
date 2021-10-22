//------------------------------------------------------------------------------
// flower.cpp - содержит процедуру ввода параметров
// для уже созданного цветка
//------------------------------------------------------------------------------

#include "flower.h"
#include <cstring>
#include <sstream>

//------------------------------------------------------------------------------
// Преобразование типа цветка в строку
const char* FlowerTypeToString(flower::flower_type type) {
    switch(type) {
        case flower::flower_type::HOME:
            return "home";
        case flower::flower_type::GARDEN:
            return "garden";
        case flower::flower_type::WILD:
            return "wild";
        default:
            return "unknown";
    }
}

//------------------------------------------------------------------------------
// Преобразование строки типа цветка в тип
flower::flower_type StringToFlowerType(const char* type) {
    if(strcmp(type, "home") == 0) {
        return flower::flower_type::HOME;
    }
    if(strcmp(type, "garden") == 0) {
        return flower::flower_type::GARDEN;
    }
    if(strcmp(type, "wild") == 0) {
        return flower::flower_type::WILD;
    }
    return (flower::flower_type)-1;
}

//------------------------------------------------------------------------------
// Ввод параметров цветка из файла
flower::flower(ifstream &ifst) {
    std::string flower_type;
    ifst >> name >> flower_type;
    type = StringToFlowerType(flower_type.c_str());
}

// Случайный ввод параметров цветка
flower::flower(const Random& rand) {
    int length = rand(128);
    name.resize(length);
    for (size_t i = 0; i < length; ++i) {
        name[i] = char('a' + rand(26));
    }
    type = (flower::flower_type)rand(3);
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в виде строки
std::string flower::toString() const {
    std::stringstream osst;
    osst << "It is Flower: name = " << name << ", flower type = " << FlowerTypeToString(type)
         << ". hash = " << Hash() << "\n";
    return osst.str();
}

//------------------------------------------------------------------------------
// Вычисление хеша имени цветка
double flower::Hash() const {
    int vowel_count = 0;
    for(char c : name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)name.size();
}
