#ifndef __plant__
#define __plant__

#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------------------------------
// plant.h - содержит описание обобщающего растения,
//------------------------------------------------------------------------------

#include "rnd.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся растения
class plant {
public:
    virtual std::string toString() const = 0;
    virtual double Hash() const = 0;
    virtual ~plant() = default;

    static plant* create(ifstream& ifst);
    static plant* createRnd(const Random& rand);
};

#endif
