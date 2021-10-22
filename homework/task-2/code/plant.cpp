//------------------------------------------------------------------------------
// plant.cpp - содержит процедуру ввода параметров
// для растения
//------------------------------------------------------------------------------

#include "plant.h"
#include "tree.h"
#include "flower.h"
#include "bush.h"

//------------------------------------------------------------------------------
// Ввод параметров из файла
plant* plant::create(ifstream &ifst) {
    std::string type_name;
    ifst >> type_name;

    if (type_name == "tree") {
        return new tree(ifst);
    }
    if (type_name == "flower") {
        return new flower(ifst);
    }
    if (type_name == "bush") {
        return new bush(ifst);
    }
    return nullptr;
}

//------------------------------------------------------------------------------
// Случайный ввод параметров
plant* plant::createRnd(const Random& rand) {
    int type_index = rand(3);

    if (type_index == 0)
        return new tree(rand);
    if (type_index == 1)
        return new flower(rand);
    if (type_index == 2)
        return new bush(rand);

    return nullptr;
}
