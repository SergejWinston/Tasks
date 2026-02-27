#ifndef BRANDY_H
#define BRANDY_H

#include "WetIngredient.h"

class Brandy : public WetIngredient {
public:
    explicit Brandy(int portions = 1)
        : WetIngredient("бренди", portions, 0.0) {}
};

#endif
