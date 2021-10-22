#ifndef __bush__
#define __bush__

//------------------------------------------------------------------------------
// bash.h - содержит описание кустарника и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "plant.h"

// дерево
struct bush : public plant {
public:
    enum class month {
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER,
    };

private:
    std::string name; // название растения
    month bloom_month; // месяц цветения кустарника

public:
    // Ввод параметров кустарника из файла
    bush(ifstream& ifst);
    // Случайный ввод параметров кустарника
    bush(const Random& rand);

    // Вычисление хеша имени кустарника
    virtual double Hash() const override;

    // Вывод параметров кустарника в виде строки
    virtual std::string toString() const override;
};

#endif //__bush__
