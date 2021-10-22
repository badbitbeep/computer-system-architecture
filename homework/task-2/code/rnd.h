#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 0 до max
//------------------------------------------------------------------------------

class Random {
public:
    auto operator()(int max) const {
        return rand() % max;
    }
};

#endif //__rnd__