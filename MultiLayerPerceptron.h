//
// Created by Hossam Samir on 22/12/2022.
//
#include <vector>

#ifndef NEURAL_NETWORKS_CPP_MULTILAYER_PERCEPTRON_H
#define NEURAL_NETWORKS_CPP_MULTILAYER_PERCEPTRON_H


class Perceptron {
public:
    // Return a new Perceptron object with the specified number of input ( +1 for bias)
    Perceptron(int inputs, double bias = 1.0);
    double run(std::vector<double> x);

    void setWeights(const std::vector<double> &weights);
    double sigmoid(double x);

public:
    std::vector<double> weights;
    double bias;

};


class MultiLayerPerceptron {


};


#endif //NEURAL_NETWORKS_CPP_MULTILAYER_PERCEPTRON_H
