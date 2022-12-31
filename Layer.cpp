//
// Created by Hossam Samir on 28/12/2022.
//

#include "Layer.h"
#include <iostream>

Layer::Layer(const std::vector<int> &layers, double bias, double eta) : layers(layers), bias(bias), eta(eta) {

    for (int i = 0; i < layers.size(); ++i) {
        values.push_back(std::vector(layers[i], 0.0));
        network.push_back(std::vector<Perceptron>());

        if (i > 0) // network[0] is the input layer
            for (int j = 0; j < layers[i]; ++j) {
                network[i].push_back(Perceptron(layers[i - 1], bias));
            }
    }
}

void Layer::print_weights() {
    for (int i = 0; i < network.size(); ++i) {
        for (int j = 0; j < layers[i]; ++j) {
            cout << "Layer " << i + 1 << " neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                cout << it << "  ";
            cout << endl;

        }
    }
    cout << endl;
}

double Layer::bp(vector<double> x, vector<double> y) {
    return 0;
}

void Layer::set_weights(vector < vector < vector < double
>>> &w_init) {
}
