//------------------------------------------------------------------------------
// plant.cpp - содержит процедуры связанные с обработкой обобщенного растения
// и создания произвольного растения
//------------------------------------------------------------------------------

#include "plant.h"
#include <string.h>

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла
plant* In(ifstream &ifst) {
    plant *pl;
    char type[128];
    ifst >> type;
    if (strcmp(type, "tree") == 0) {
        pl = new plant;
        pl->k = plant::TREE;
        In(pl->t, ifst);
        return pl;
    }
    if (strcmp(type, "bush") == 0) {
        pl = new plant;
        pl->k = plant::BUSH;
        In(pl->b, ifst);
        return pl;
    }
    if (strcmp(type, "flower") == 0) {
        pl = new plant;
        pl->k = plant::FLOWER;
        In(pl->f, ifst);
        return pl;
    }
    return nullptr;
}

// Случайный ввод обобщенного растения
plant *InRnd() {
    plant *pl;
    auto k = Random(3);
    switch(k) {
        case 0:
            pl = new plant;
            pl->k = plant::TREE;
            InRnd(pl->t);
            return pl;
        case 1:
            pl = new plant;
            pl->k = plant::BUSH;
            InRnd(pl->b);
            return pl;
        case 2:
            pl = new plant;
            pl->k = plant::FLOWER;
            InRnd(pl->f);
            return pl;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего растения в поток
void Out(plant &pl, ofstream &ofst) {
    switch(pl.k) {
        case plant::TREE:
            Out(pl.t, ofst);
            break;
        case plant::BUSH:
            Out(pl.b, ofst);
            break;
        case plant::FLOWER:
            Out(pl.f, ofst);
            break;
        default:
            ofst << "Incorrect plant!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление хеша имени растения
double Hash(plant &pl) {
    switch(pl.k) {
        case plant::TREE:
            return Hash(pl.t);
        case plant::BUSH:
            return Hash(pl.b);
        case plant::FLOWER:
            return Hash(pl.f);
        default:
            return 0.0;
    }
}
