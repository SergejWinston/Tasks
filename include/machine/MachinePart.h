#ifndef MACHINE_PART_H
#define MACHINE_PART_H

#include "../ingredients/Ingredient.h"
#include <string>

class MachinePart {
public:
    MachinePart(const std::string& name) : name_(name) {}
    virtual ~MachinePart() = default;

    virtual int process(const Ingredient& ingredient) const = 0;
    const std::string& getName() const { return name_; }

protected:
    std::string name_;
};

#endif
