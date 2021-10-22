#ifndef __tree__
#define __tree__

//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса
//------------------------------------------------------------------------------


using namespace std;

#include "rnd.h"
#include "plant.h"

// дерево
class tree : public plant {
    std::string name; // название растения
    int age; // возраст дерева

public:
    // Ввод параметров дерева из файла
    tree(ifstream& ifst);
    // Случайный ввод параметров дерева
    tree(const Random& rand);

    // Вычисление хеша имени дерева
    virtual double Hash() const override;

    // Вывод параметров дерева в виде строки
    virtual std::string toString() const override;
};

#endif //__tree__
