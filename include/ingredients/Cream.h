#ifndef CREAM_H
#define CREAM_H

#include "WetIngredient.h"

class Cream : public WetIngredient {
public:
    explicit Cream(int portions = 1)
        : WetIngredient("сливки", portions, 65.0) {}
};

#endif
