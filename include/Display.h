#ifndef DISPLAY_H
#define DISPLAY_H

#include "DrinkResult.h"
#include <iostream>
#include <string>
#include <vector>

class Display {
public:
    static void show(const std::vector<DrinkResult>& results) {
        std::cout << "========================================" << std::endl;
        std::cout << "        Кофемашина - Результаты" << std::endl;
        std::cout << "========================================" << std::endl;
        for (const auto& result : results) {
            std::cout << result.name << std::endl;
            std::cout << result.preparationTime << " секунд" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }
};

#endif
