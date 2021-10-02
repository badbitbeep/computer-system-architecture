//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(triangle &t, ifstream &ifst) {
    ifst >> t.a >> t.b >> t.c;
}

// Случайный ввод параметров треугольника
void InRnd(triangle &t) {
    t.a = Random();
    t.b = Random();
    do {
        t.c = Random();
    } while((t.c >= (t.a + t.b))
          || (t.a >= (t.c + t.b))
          || (t.b >= (t.c + t.a)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(triangle &t, ofstream &ofst) {
    ofst << "It is Triangle: a = " 
         << t.a << ", b = " << t.b
         << ", c = " << t.c
         << ". Perimeter = " << Perimeter(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Perimeter(triangle &t) {
    return double(t.a + t.b + t.c);
}
