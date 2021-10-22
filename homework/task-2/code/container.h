#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "plant.h"
#include "rnd.h"

using namespace std;

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class container {
    static const int max_len = 10000;
    int len = 0;
    plant* cont[max_len] = { 0 };

public:
    container() = default;
    container(const Random& rand, int size);
    container(ifstream& ifst);

    container(container&& c);
    container& operator=(container&& c);

    ~container();

    // Очистка контейнера от элементов (освобождение памяти)
    void clear();
    // Сортировка элементов контейнера
    void sort();

    // Вывод элементов контейнера в форматируемый поток
    std::string toString() const;
};

#endif
