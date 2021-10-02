//------------------------------------------------------------------------------
// flower.cpp - содержит процедуру ввода параметров
// для уже созданного цветка
//------------------------------------------------------------------------------

#include "flower.h"
#include <string.h>

//------------------------------------------------------------------------------
// Преобразование типа цветка в строку
const char* FlowerTypeToString(int type) {
    switch(type) {
        case flower::HOME:
            return "home";
        case flower::GARDEN:
            return "garden";
        case flower::WILD:
            return "wild";
        default:
            return "unknown";
    }
}

//------------------------------------------------------------------------------
// Преобразование строки типа цветка в тип
int StringToFlowerType(const char* type) {
    if(strcmp(type, "home") == 0) {
        return flower::HOME;
    }
    if(strcmp(type, "garden") == 0) {
        return flower::GARDEN;
    }
    if(strcmp(type, "wild") == 0) {
        return flower::WILD;
    }
    return -1;
}

//------------------------------------------------------------------------------
// Ввод параметров цветка из файла
void In(flower &f, ifstream &ifst) {
    char flower_type[128];
    ifst >> f.name >> flower_type;
    f.flower_type = StringToFlowerType(flower_type);
}

// Случайный ввод параметров цветка
void InRnd(flower &f) {
    int length = Random(size(f.name) - 1);
    for (size_t i = 0; i < length; ++i) {
        f.name[i] = char('a' + Random(26));
    }
    f.name[length] = '\0';
    f.flower_type = Random(3);
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void Out(flower &f, ofstream &ofst) {
    ofst << "It is Flower: name = " << f.name << ", flower type = " << FlowerTypeToString(f.flower_type)
         << ". hash = " << Hash(f) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление хеша имени цветка
double Hash(flower &f) {
    int vowel_count = 0;
    for(char c : f.name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)strlen(f.name);
}
