//
// Created by Hossam Samir on 28/12/2022.
//

#include "Multi_Layer.h"
#include <iostream>

Multi_Layer::Multi_Layer(const std::vector<int> &layers, double bias, double eta) : layers(layers), bias(bias),
                                                                                    eta(eta) {

    for (int i = 0; i < layers.size(); ++i) {
        values.push_back(std::vector(layers[i], 0.0));
        network.push_back(std::vector<Perceptron>());

        if (i > 0) // network[0] is the input layer
            for (int j = 0; j < layers[i]; ++j) {
                network[i].push_back(Perceptron(layers[i - 1], bias));
            }
    }
}

void
Multi_Layer::print_weights() {
    for (int i = 1; i < network.size(); ++i) {
        for (int j = 0; j < layers[i]; ++j) {
            cout << "Multi_Layer " << i + 1 << " neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                cout << it << "  ";
            cout << endl;

        }
    }
    cout << endl;
}

double
Multi_Layer::bp(vector<double> x, vector<double> y) {
    // backpropagation step by step.
    // step 1: Feed a sample to the network
    vector<double> outputs = run(x);

    // step 2: Calculate the MSE
    vector<double> error;
    double MSE = 0.0;
    for (int i = 0; i < y.size(); ++i) {
        error.push_back(outputs[i] - y[i]);
        MSE += error[i] * error[i];
    }
    MSE /= layers.back();



    return 0;
}

void
Multi_Layer::set_weights(vector<vector<vector<double>>> w_init) {
    for (int i = 0; i < w_init.size(); ++i) {
        for (int j = 0; j < w_init[i].size(); ++j) {
            network[i + 1][j].setWeights(w_init[i][j]);
        }
    }
}

vector<double>
Multi_Layer::run(vector<double> x) {
    values[0] = x;
    for (int i = 1; i < network.size(); ++i)
        for (int j = 0; j < layers[i]; ++j)
            values[i][j] = network[i][j].run(values[i - 1]);

    return values.back();
}
