#include <iostream>
#include "Perceptron.h"
#include "Multi_Layer.h"

using namespace std;

int main() {
    srand(time(NULL));
    rand();
    std::cout << "\n \n....Logic Gate Example.......\n \n";
    Perceptron *p = new Perceptron(2);
    p->setWeights({10, 10, -15}); // AND
    p->setWeights({15, 15, -10}); // OR
    p->setWeights({-15, -15, 10}); // NOR
    p->setWeights({-10, -10, -15}); // NAND

    cout << "Gate: " << std::endl;
    cout << p->run({0, 0}) << endl;
    cout << p->run({0, 1}) << endl;
    cout << p->run({1, 0}) << endl;
    cout << p->run({1, 1}) << endl;

    std::cout << "\n\n --------hardcoded Xor Example --------\n\n";
    Multi_Layer mlp = Multi_Layer({2, 2, 1});
    mlp.set_weights({{{-10, -10, 15}, {15, 15, -10}},
                     {{10,  10,  -15}}});
    cout << "Hard coded weights:\n";
    mlp.print_weights();

    cout << "XOR : " << endl;
    cout << "0 0 = " << mlp.run({0, 0})[0] << endl;
    cout << "0 0 = " << mlp.run({0, 1})[0] << endl;
    cout << "0 0 = " << mlp.run({1, 0})[0] << endl;
    cout << "0 0 = " << mlp.run({1, 1})[0] << endl;

    return 0;
}
