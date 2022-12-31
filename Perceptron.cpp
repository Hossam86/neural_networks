//
// Created by Hossam Samir on 22/12/2022.
//

#include <random>
#include "Perceptron.h"

double
frand() {
    return (2.0 * rand() / RAND_MAX) - 1.0;
}

Perceptron::Perceptron(int inputs, double bias) : bias(bias) {
    weights.resize(inputs + 1);
    std::generate(weights.begin(), weights.end(), frand);
}

void
Perceptron::setWeights(const std::vector<double> &weights) {
    Perceptron::weights = weights;
}

double
Perceptron::run(std::vector<double> x) {

    x.push_back(bias);
    double sum = std::inner_product(x.begin(), x.end(), weights.begin(), (double) 0.0);
    return sigmoid(sum);
}

double
Perceptron::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}



