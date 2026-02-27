#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
public:
    Ingredient(const std::string& name, int portions, double initialTemp = 24.0)
        : name_(name), portions_(portions), temperature_(initialTemp) {}

    virtual ~Ingredient() = default;

    virtual int getPreparationTime() const = 0;
    virtual bool isWet() const = 0;
    virtual bool isCoffee() const { return false; }

    const std::string& getName() const { return name_; }
    int getPortions() const { return portions_; }
    double getTemperature() const { return temperature_; }

protected:
    std::string name_;
    int portions_;
    double temperature_;
};

#endif
