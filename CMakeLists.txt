cmake_minimum_required(VERSION 3.14)
project(CoffeeMachine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(coffee_machine src/main.cpp)
target_include_directories(coffee_machine PRIVATE include)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
