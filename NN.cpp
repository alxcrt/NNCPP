#include "NN.h"
#include <math.h>
#include <iostream>

double sigmoid(double n) { return 1 / (1 + exp(-n)); }

double dsigmoid(double x) { return x * (1 - x); }

NN::NN(int input_nodes_, int hidden_nodes_, int output_nodes_) {
  input_nodes = input_nodes_;
  hidden_nodes = hidden_nodes_;
  output_nodes = output_nodes_;
  weights_ih.randomize(input_nodes, hidden_nodes);
  weights_ho.randomize(hidden_nodes, output_nodes);
  // Matrix bias_ih(1, hidden_nodes);
  // Matrix bias_ho(1, output_nodes);
}

Matrix NN::train(Matrix X, Matrix y) {
  // SIGMOID((INPUT * WEIGHTS ) + BIAS)

  for (int i = 0; i < 100000; i++) {
    // Feedfoward
    Matrix HIDDEN = X.dot(weights_ih);
    HIDDEN.apply(sigmoid);
    Matrix GUESES = HIDDEN.dot(weights_ho);
    GUESES.apply(sigmoid);
    if (i == 10000) return GUESES;

    Matrix OUTPUT_ERRORS = y - GUESES;

    // Calculate output gradients
    GUESES.apply(dsigmoid);
    GUESES = GUESES * OUTPUT_ERRORS;
    GUESES = GUESES * learning_rate;
    Matrix hidden_T = HIDDEN.transpose();

    // Calculate deltas
    Matrix weights_ho_deltas = hidden_T.dot(GUESES);

    // Calculate the hidden layers error
    Matrix weights_ho_transpose = weights_ho.transpose();
    Matrix HIDDEN_ERRORS = OUTPUT_ERRORS.dot(weights_ho_transpose);

    // Calculate output gradients
    HIDDEN.apply(dsigmoid);
    HIDDEN = HIDDEN * HIDDEN_ERRORS;
    HIDDEN = HIDDEN * learning_rate;
    Matrix x_T = X.transpose();

    // // Calculate deltas
    Matrix weights_ih_deltas = x_T.dot(HIDDEN);

    // // Add ajustments
    weights_ih = weights_ih + weights_ih_deltas;
    weights_ho = weights_ho + weights_ho_deltas;

    // std::cout << " train " << i << " / " << 1000 << std::endl;
  }
  // return GUESES;
}
