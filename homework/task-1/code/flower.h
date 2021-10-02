#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include <string>
using namespace std;

# include "rnd.h"

// дерево
struct flower {
    char name[128]; // название растения
    enum {
        HOME,
        GARDEN,
        WILD
    };
    int flower_type; // тип цветка
};

// Ввод параметров цветка из файла
void In(flower &f, ifstream &ifst);

// Случайный ввод параметров цветка
void InRnd(flower &f);

// Вывод параметров цветка в форматируемый поток
void Out(flower &f, ofstream &ofst);

// Вычисление хеша имени цветка
double Hash(flower &f);

#endif //__flower__
