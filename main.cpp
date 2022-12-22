#include <iostream>
#include "MultiLayerPerceptron.h"

int main() {
    srand(time(NULL));
    rand();
    std::cout << "\n \n....Logic Gate Example.......\n \n";
    Perceptron *p = new Perceptron(2);
    p->setWeights({10.0, 10.0, -15.0});

    std::cout << "Gate: " << std::endl;
    std::cout << p->run({0,0}) <<std::endl;
    std::cout << p->run({0,1}) <<std::endl;
    std::cout << p->run({1,0}) <<std::endl;
    std::cout << p->run({1,1}) <<std::endl;

    return 0;
}
