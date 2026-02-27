#ifndef MILK_H
#define MILK_H

#include "WetIngredient.h"

class Milk : public WetIngredient {
public:
    explicit Milk(int portions = 1)
        : WetIngredient("молоко", portions, 65.0) {}
};

#endif
