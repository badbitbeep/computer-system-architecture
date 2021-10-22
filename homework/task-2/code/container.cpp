//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

#include <sstream>

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
container::~container() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

container::container(container&& c) {
    len = c.len;
    for (int i = 0; i < len; i++) {
        cont[i] = c.cont[i];
    }
    c.len = 0;
}

container& container::operator=(container&& c) {
    this->~container();

    len = c.len;
    for (int i = 0; i < len; i++) {
        cont[i] = c.cont[i];
    }
    c.len = 0;

    return *this;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
container::container(std::ifstream& ifst) {
    while (!ifst.eof()) {
        if ((cont[len] = plant::create(ifst)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
container::container(const Random& rand, int size) {
    while (len < size) {
        if ((cont[len] = plant::createRnd(rand)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
std::string container::toString() const {
    std::stringstream osst;
    osst << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; i++) {
        osst << i << ": ";
        osst << cont[i]->toString();
    }
    return osst.str();
}

// Сортировка контейнера методом Straight Selection
void container::sort() {
    int i = 0, j, k;
    plant *temp;
    while (i < len) {
        k = i;
        for (j = i + 1; j < len; j++) {
            if (cont[j]->Hash() < cont[k]->Hash()) {
                k = j;
            }
        }
        temp = cont[i];
        cont[i] = cont[k];
        cont[k] = temp;
        i++;
    }
}
