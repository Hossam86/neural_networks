cmake_minimum_required(VERSION 3.24)
project(neural_networks_cpp)

set(CMAKE_CXX_STANDARD 17)


set(HEADERS MultiLayerPerceptron.h)
set(SOURCES main.cpp
            MultiLayerPerceptron.cpp)
add_executable(neural_networks_cpp ${HEADERS} ${SOURCES})
