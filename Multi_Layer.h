//
// Created by Hossam Samir on 28/12/2022.
//

#ifndef NEURAL_NETWORKS_CPP_MULTI_LAYER_H
#define NEURAL_NETWORKS_CPP_MULTI_LAYER_H

#include <vector>
#include "Perceptron.h"

using namespace std;

class Multi_Layer {

private:
    std::vector<int> layers;
public:
    Multi_Layer(const vector<int> &layers, double bias = 1.0, double eta = 0.5);

    // set the weights into the neural network
    void
    set_weights(vector<vector<vector<double>>> w_init);

    void
    print_weights();

    vector<double> run(vector <double> x);

    double
    bp(vector<double> x, vector<double> y);

private:
    double bias;
    double eta;
    std::vector<std::vector<Perceptron> > network;
    std::vector<std::vector<double> > values;
    std::vector<std::vector<double> > d;
};

#endif //NEURAL_NETWORKS_CPP_MULTI_LAYER_H
