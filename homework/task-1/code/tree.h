#ifndef __tree__
#define __tree__

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include <string>
using namespace std;

# include "rnd.h"

// дерево
struct tree {
    char name[128]; // название растения
    int age; // возраст дерева
};

// Ввод параметров дерева из файла
void In(tree &t, ifstream &ifst);

// Случайный ввод параметров дерева
void InRnd(tree &t);

// Вывод параметров дерева в форматируемый поток
void Out(tree &t, ofstream &ofst);

// Вычисление хеша имени дерева
double Hash(tree &t);

#endif //__tree__
