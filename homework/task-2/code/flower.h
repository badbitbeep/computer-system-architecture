#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка и его интерфейса
//------------------------------------------------------------------------------
using namespace std;

#include "plant.h"

// цветок
class flower : public plant {
public:
    enum class flower_type {
        HOME,
        GARDEN,
        WILD
    };

private:
    std::string name; // название растения
    flower_type type; // тип цветка

public:
    // Ввод параметров цветка из файла
    flower(ifstream& ifst);
    // Случайный ввод параметров цветка
    flower(const Random& rand);

    // Вычисление хеша имени цветка
    virtual double Hash() const override;

    // Параметры цветка в виде строки
    virtual std::string toString() const override;
};

#endif //__flower__
