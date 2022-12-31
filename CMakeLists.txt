cmake_minimum_required(VERSION 3.24)
project(neural_networks_cpp)

set(CMAKE_CXX_STANDARD 17)


set(HEADERS Perceptron.h Layer.h)
set(SOURCES main.cpp
        Perceptron.cpp
        Layer.cpp)
add_executable(neural_networks_cpp ${HEADERS} ${SOURCES})
