//------------------------------------------------------------------------------
// tree.cpp - содержит процедуру ввода параметров
// для уже созданного дерева
//------------------------------------------------------------------------------

#include "tree.h"
#include <cstring>
#include <sstream>

//------------------------------------------------------------------------------
// Ввод параметров дерева из файла
tree::tree(ifstream &ifst) {
    ifst >> name >> age;
}

//------------------------------------------------------------------------------
// Случайный ввод параметров дерева
tree::tree(const Random& rand) {
    int length = rand(128);
    name.resize(length);
    for (size_t i = 0; i < length; ++i) {
        name[i] = char('a' + rand(26));
    }
    age = rand(100);
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в виде строки
std::string tree::toString() const {
    std::stringstream osst;
    osst << "It is Tree: name = " << name << ", age = " << age
         << ". hash = " << Hash() << "\n";
    return osst.str();
}

//------------------------------------------------------------------------------
// Вычисление хеша имени дерева
double tree::Hash() const {
    int vowel_count = 0;
    for(char c : name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)name.size();
}
