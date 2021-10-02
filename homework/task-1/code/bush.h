#ifndef __bush__
#define __bush__

//------------------------------------------------------------------------------
// bash.h - содержит описание кустарника и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

// дерево
struct bush {
    char name[128]; // название растения
    enum {
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
    int bloom_month; // месяц цветения кустарника
};

// Ввод параметров кустарника из файла
void In(bush &b, ifstream &ifst);

// Случайный ввод параметров кустарника
void InRnd(bush &b);

// Вывод параметров кустарника в форматируемый поток
void Out(bush &b, ofstream &ofst);

// Вычисление хеша имени кустарника
double Hash(bush &b);

#endif //__bush__
