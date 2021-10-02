//------------------------------------------------------------------------------
// tree.cpp - содержит процедуру ввода параметров
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include "tree.h"
#include <string.h>

//------------------------------------------------------------------------------
// Ввод параметров дерева из файла
void In(tree &t, ifstream &ifst) {
    ifst >> t.name >> t.age;
}

// Случайный ввод параметров дерева
void InRnd(tree &t) {
    int length = Random(size(t.name) - 1);
    for (size_t i = 0; i < length; ++i) {
        t.name[i] = char('a' + Random(26));
    }
    t.name[length] = '\0';
    t.age = Random(100);
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в форматируемый поток
void Out(tree &t, ofstream &ofst) {
    ofst << "It is Tree: name = " << t.name << ", age = " << t.age
         << ". hash = " << Hash(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление хеша имени дерева
double Hash(tree &t) {
    int vowel_count = 0;
    for(char c : t.name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count++;
        if (c == 'A' || c == 'B' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
    }
    return (double)vowel_count / (double)strlen(t.name);
}
